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
#include "hubo_ros_msgs/HuboTrajectory.h"
#include "hubo_ros_msgs/HuboJointCommand.h"
#include "ach.h"
#include "../../../hubo-ach/include/hubo.h"
#include "../../../hubo-ach/include/hubo-ref-filter.h"

//Global variables
ach_channel_t chan_hubo_ref_filter;

//Semi-empty function - Dan, since you're the HUBO expert here, make sure that this actually does what we think it does.
void hubo_cb(const hubo_ros_msgs::HuboTrajectory &msg)
{
    //Send the commands from the HuboCommand message onto ACH to the robot
    //Make the necessary hubo struct for ACH
    struct hubo_ref H_ref_filter;
    memset( &H_ref_filter, 0, sizeof(H_ref_filter));
    //Add the joint values one at a time into the hubo struct
    for (int i = 0; i < msg.num_joints; i++)
    {
        H_ref_filter.ref[i] = msg.joints[i].position;
    }
    //Populate the empty values in the header for safety
    for (int i = msg.num_joints; i < HUBO_JOINT_COUNT; i++)
    {
        H_ref_filter.ref[i] = 0.0;
    }
    //Put the new message into the ACH channel
    ach_put(&chan_hubo_ref_filter, &H_ref_filter, sizeof(H_ref_filter));
}


//NEW MAIN LOOP
int main(int argc, char **argv)
{
    //initialize ACH channel
    int r = ach_open(&chan_hubo_ref_filter, HUBO_CHAN_REF_FILTER_NAME , NULL);
    assert(ACH_OK == r);

    //initialize ROS node
    ros::init(argc, argv, "hubo_to_ach");
    ros::NodeHandle nh;

    //construct ROS RT Subscriber
    ros::Subscriber hubo_command_sub = nh.subscribe("Hubo/HuboCommand", 1, hubo_cb);
    //spin
    ros::spin();
    //Satisfy the compiler
    return 0;
}
