/*
Copyright (c) 2012, Daniel M. Lofaro
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the author nor the names of its contributors may 
      be used to endorse or promote products derived from this software 
      without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, 
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// %Tag(FULLTEXT)%
// %Tag(ROS_HEADER)%
#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "std_msgs/String.h"
#include "std_msgs/Float32MultiArray.h"
// %EndTag(MSG_HEADER)%
#include "../../../hubo-ach/include/hubo.h"
#include <sstream>

double tmp = 0.0;
int hubo_debug = 0;
int main(int argc, char **argv)
{


// %Tag(INIT)%
  ros::init(argc, argv, "hubo_test");
// %EndTag(INIT)%

// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

// %Tag(PUBLISHER)%
  /* Number of iterations to save */
  int numSave = 1000; 


//  ros::Publisher pub_state = n.advertise<hubo_state>("state", numSave);

  ros::Publisher pub_joint_pos = n.advertise<std_msgs::Float32MultiArray>("/hubo/ref", numSave);
//  ros::Publisher pub_joint_cur = n.advertise<std_msgs::Float32MultiArray>("/joint/cur", numSave);
//  ros::Publisher pub_joint_vel = n.advertise<std_msgs::Float32MultiArray>("/joint/vel", numSave);
//  ros::Publisher pub_joint_active = n.advertise<std_msgs::Float32MultiArray>("/joint/active", numSave);
//  ros::Publisher pub_joint_zeroed = n.advertise<std_msgs::Float32MultiArray>("/joint/zeroed", numSave);
// %EndTag(PUBLISHER)%
// %EndTag(PUBLISHER)%

// %Tag(LOOP_RATE)%
  ros::Rate loop_rate(1);
// %EndTag(LOOP_RATE)%

// %Tag(ROS_OK)%

  while (ros::ok())
  {
// %EndTag(ROS_OK)%

std_msgs::Float32MultiArray pos;
/* ach get */

if(tmp < 1.0) tmp = 2.0;
else tmp = 0;

for( int i = 0; i < HUBO_JOINT_COUNT; i++) {
  if( i == 0 ) pos.data.push_back(tmp);
  pos.data.push_back(0.0);
}




// %Tag(PUBLISH)%
    pub_joint_pos.publish(pos);
    //chatter_pub.publish(1);
// %EndTag(PUBLISH)%

// %Tag(SPINONCE)%
    ros::spinOnce();
// %EndTag(SPINONCE)%

// %Tag(RATE_SLEEP)%
    loop_rate.sleep();
// %EndTag(RATE_SLEEP)%
  }


  return 0;
}
// %EndTag(FULLTEXT)%
