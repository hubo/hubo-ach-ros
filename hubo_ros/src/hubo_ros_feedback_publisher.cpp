/*
ROS code:
---------
Copyright (c) 2012, Calder Phillips-Grafflin, WPI DRC Team
(2-clause BSD)

ACH code:
---------
Copyright (c) 2012, Daniel M. Lofaro
(3-clause BSD)
*/

// ros includes
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "ros/ros.h"
#include <math.h>
#include <sstream>
#include <errno.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include "std_msgs/String.h"
#include "hubo_ros_msgs/HuboState.h"
#include "hubo_ros_msgs/HuboJointState.h"
#include "hubo_ros_msgs/HuboIMU.h"
#include "hubo_ros_msgs/HuboFT.h"
#include "ach.h"
#include "../../../hubo-ach/include/hubo.h"

//Global variables
ach_channel_t chan_hubo_state;    // hubo-ach-state
int hubo_debug = 0;
char *joint_names[] = {"HPY", "not in urdf1", "HNR", "HNP", "LSP", "LSR", "LSY", "LEP", "LWY", "not in urdf2", "LWP", "RSP", "RSR", "RSY", "REP", "RWY", "not in urdf3", "RWP", "not in ach1", "LHY", "LHR", "LHP", "LKP", "LAP", "LAR", "not in ach1", "RHY", "RHR", "RHP", "RKP", "RAP", "RAR", "not in urdf4", "not in urdf5", "not in urdf6", "not in urdf7", "not in urdf8", "not in urdf9", "not in urdf10", "not in urdf11", "not in urdf12", "not in urdf13", "unknown1", "unknown2", "unknown3", "unknown4", "unknown5", "unknown6", "unknown7", "unknown8"};

//Semi-empty function - Dan, since you're the HUBO expert here, make sure that this actually does what we think it does.
bool ACHtoHuboState(struct hubo_state * robot_state, hubo_ros_msgs::HuboState * msg)
{

    if (robot_state != NULL && msg != NULL)
    {
        //Copy data from a hubo_state struct used in ACH to
        //the HuboState message used in ROS
        //First, copy the joint values
        for (int i = 0; i < HUBO_JOINT_COUNT; i++)
        {
            if (robot_state->joint != NULL)
            {
                //Copy an individual joint
                msg->joints[i].name = joint_names[i];
                msg->joints[i].position = robot_state->joint[i].pos;
                msg->joints[i].velocity = robot_state->joint[i].vel;
                msg->joints[i].current = robot_state->joint[i].cur;
                msg->joints[i].temperature = robot_state->joint[i].tmp;
                msg->joints[i].active = (int)robot_state->joint[i].pos;
                msg->joints[i].zeroed = (int)robot_state->joint[i].zeroed;
            }
            else
            {
                printf("*** WARNING - NULL joint state received ***\n");
            }
        }
        //Now, copy the three IMUs
        //IMU "1" the main IMU
        msg->imu.x_acceleration = robot_state->imu[0].a_x;
        msg->imu.y_acceleration = robot_state->imu[0].a_y;
        msg->imu.z_acceleration = robot_state->imu[0].a_z;
        msg->imu.x_rotation = robot_state->imu[0].w_x;
        msg->imu.y_rotation = robot_state->imu[0].w_y;
        //IMU "2" the left foot IMU
        msg->left_foot.x_acceleration = robot_state->imu[1].a_x;
        msg->left_foot.y_acceleration = robot_state->imu[1].a_y;
        msg->left_foot.z_acceleration = robot_state->imu[1].a_z;
        msg->left_foot.x_rotation = robot_state->imu[1].w_x;
        msg->left_foot.y_rotation = robot_state->imu[1].w_y;
        //IMU "3" the right foot IMU
        msg->right_foot.x_acceleration = robot_state->imu[2].a_x;
        msg->right_foot.y_acceleration = robot_state->imu[2].a_y;
        msg->right_foot.z_acceleration = robot_state->imu[2].a_z;
        msg->right_foot.x_rotation = robot_state->imu[2].w_x;
        msg->right_foot.y_rotation = robot_state->imu[2].w_y;
        //Now, copy the four force-torque sensors
        //F-T "1" the left wrist
        msg->left_wrist.Mx = robot_state->ft[0].m_x;
        msg->left_wrist.My = robot_state->ft[0].m_y;
        msg->left_wrist.Fz = robot_state->ft[0].f_z;
        //F-T "2" the right wrist
        msg->right_wrist.Mx = robot_state->ft[1].m_x;
        msg->right_wrist.My = robot_state->ft[1].m_y;
        msg->right_wrist.Fz = robot_state->ft[1].f_z;
        //F-T "3" the left ankle
        msg->left_ankle.Mx = robot_state->ft[2].m_x;
        msg->left_ankle.My = robot_state->ft[2].m_y;
        msg->left_ankle.Fz = robot_state->ft[2].f_z;
        //F-T "4" the right ankle
        msg->right_ankle.Mx = robot_state->ft[3].m_x;
        msg->right_ankle.My = robot_state->ft[3].m_y;
        msg->right_ankle.Fz = robot_state->ft[3].f_z;
        //
        return true;
    }
    else
    {
        return false;
    }
}


//NEW MAIN LOOP
int main(int argc, char **argv)
{
    printf("Initializing ACH-to-ROS bridge\n");
    //initialize ACH channel
    int r = ach_open(&chan_hubo_state, HUBO_CHAN_STATE_NAME , NULL);
    assert( ACH_OK == r );

    struct hubo_state H_state;
    memset(&H_state, 0, sizeof(H_state));

    size_t fs;

    r = ach_get(&chan_hubo_state, &H_state, sizeof(H_state), &fs, NULL, ACH_O_LAST);
    if(ACH_OK != r)
    {
        if(hubo_debug)
        {
            printf("State ini r = %i\n",r);
        }
    }
    else
    {
        assert(sizeof(H_state) == fs);
    }
    printf("ACH channels loaded\n");
    //initialize ROS node
    ros::init(argc, argv, "hubo_from_ach");
    ros::NodeHandle nh;

    //construct ROS RT publisher
    ros::Publisher hubo_state_pub = nh.advertise<hubo_ros_msgs::HuboState>("Hubo/HuboState", 1);
    printf("ROS publisher loaded\n");
    //Loop
    while (ros::ok())
    {
        //Get latest state from ACH
        // CODE HERE
        r = ach_get(&chan_hubo_state, &H_state, sizeof(H_state), &fs, NULL, ACH_O_WAIT);
        if(ACH_OK != r)
        {
            if(hubo_debug)
            {
                printf("State ini r = %i\n",r);
            }
        }
        else
        {
            assert(sizeof(H_state) == fs);
        }
        //Assemble new HuboState message
        hubo_ros_msgs::HuboState msg = hubo_ros_msgs::HuboState();
        msg.joints.resize(HUBO_JOINT_COUNT);
        if(ACHtoHuboState(&H_state, &msg))
        {
            //Publish HuboState
            hubo_state_pub.publish(msg);
        }
        else
        {
            printf("*** Invalid state recieved from HUBO! ***\n");
        }
        ros::spinOnce();
    }
    //Satisfy the compiler
    return 0;
}
