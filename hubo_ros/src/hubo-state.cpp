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

// for ach
#include <errno.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <inttypes.h>
#include "ach.h"
#include <string.h>
#include <stdio.h>


ach_channel_t chan_hubo_state;    // hubo-ach-state
int hubo_debug = 0;
int main(int argc, char **argv)
{

/* Ach Stuff */
  // open hubo state
  int r = ach_open(&chan_hubo_state, HUBO_CHAN_STATE_NAME, NULL);
  assert( ACH_OK == r );

  struct hubo_state H_state;
  memset( &H_state, 0, sizeof(H_state));

  size_t fs;

  r = ach_get( &chan_hubo_state, &H_state, sizeof(H_state), &fs, NULL, ACH_O_LAST );
  if(ACH_OK != r) {
    if(hubo_debug) {
      //printf("State ini r = %s\n",ach_result_to_string(r));}
      printf("State ini r = %i\n",r);}
  }
  else{   
    assert( sizeof(H_state) == fs );
  }



// %Tag(INIT)%
  ros::init(argc, argv, "hubo_state");
// %EndTag(INIT)%

// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

// %Tag(PUBLISHER)%
  /* Number of iterations to save */
  int numSave = 1000; 


//  ros::Publisher pub_state = n.advertise<hubo_state>("state", numSave);

  ros::Publisher pub_joint_pos = n.advertise<std_msgs::Float32MultiArray>("/hubo/state/pos", numSave);
//  ros::Publisher pub_joint_cur = n.advertise<std_msgs::Float32MultiArray>("/joint/cur", numSave);
//  ros::Publisher pub_joint_vel = n.advertise<std_msgs::Float32MultiArray>("/joint/vel", numSave);
//  ros::Publisher pub_joint_active = n.advertise<std_msgs::Float32MultiArray>("/joint/active", numSave);
//  ros::Publisher pub_joint_zeroed = n.advertise<std_msgs::Float32MultiArray>("/joint/zeroed", numSave);
// %EndTag(PUBLISHER)%
// %EndTag(PUBLISHER)%

// %Tag(LOOP_RATE)%
  ros::Rate loop_rate(10);
// %EndTag(LOOP_RATE)%

// %Tag(ROS_OK)%

  while (ros::ok())
  {
// %EndTag(ROS_OK)%

std_msgs::Float32MultiArray pos;
/* ach get */
  r = ach_get( &chan_hubo_state, &H_state, sizeof(H_state), &fs, NULL, ACH_O_LAST );
  if(ACH_OK != r) {
    if(hubo_debug) {
      //printf("State ini r = %s\n",ach_result_to_string(r));}
      printf("State ini r = %i\n",r);}
  }
  else{   
    assert( sizeof(H_state) == fs );
  }



for( int i = 0; i < HUBO_JOINT_COUNT; i++) {
    pos.data.push_back(H_state.joint[i].pos);
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
