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
#include "std_msgs/Float64MultiArray.h"
// %EndTag(MSG_HEADER)%
#include "hubo_ros/hubo.h"
#include <sstream>
#include <vector>

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
  int r = ach_open(&chan_hubo_state, HUBO_CHAN_STATE_NAME , NULL);
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
  ros::init(argc, argv, "hubo-state");
  // %EndTag(INIT)%

  // %Tag(NODEHANDLE)%
  ros::NodeHandle n;
  // %EndTag(NODEHANDLE)%

  // %Tag(PUBLISHER)%
  /* Number of iterations to save */
  int numSave = 100; 

  // Note that Float64MultiArray is the ROS equivalent of a double array
  // Note that ByteMultiArray is the ROS equivalent of a bool array
  ros::Publisher pub_joint_pos = n.advertise<std_msgs::Float64MultiArray>("/joint/pos", numSave);
  ros::Publisher pub_joint_cur = n.advertise<std_msgs::Float64MultiArray>("/joint/cur", numSave);
  ros::Publisher pub_joint_vel = n.advertise<std_msgs::Float64MultiArray>("/joint/vel", numSave);
  ros::Publisher pub_joint_active = n.advertise<std_msgs::Float64MultiArray>("/joint/active", numSave);
  ros::Publisher pub_joint_zeroed = n.advertise<std_msgs::Float64MultiArray>("/joint/zeroed", numSave);
  // %EndTag(PUBLISHER)%

  // %Tag(LOOP_RATE)%
  ros::Rate loop_rate(10);
  // %EndTag(LOOP_RATE)%

  // %Tag(ROS_OK)%
  
  // Create vectors and initialize them as zero. Note that assigning data to ros message is automagically done when we use a vector of doubles instead of an array of doubles.
  std::vector<double> pos(HUBO_JOINT_COUNT,0); 
  std::vector<double> cur(HUBO_JOINT_COUNT,0); 
  std::vector<double> vel(HUBO_JOINT_COUNT,0); 
  std::vector<double> active(HUBO_JOINT_COUNT,0); 
  std::vector<double> zeroed(HUBO_JOINT_COUNT,0); 


  while (ros::ok())
    {
      // %EndTag(ROS_OK)%


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

      /* Get States */
      for( int i = 0; i < HUBO_JOINT_COUNT; i++) {
	pos[i] = H_state.joint[i].pos;
	cur[i] = H_state.joint[i].cur;
	vel[i] = H_state.joint[i].vel;
	active[i] = H_state.joint[i].active;
	zeroed[i] = H_state.joint[i].zeroed;
      }


      // %Tag(PUBLISH)%
      // Note that you have to assign the data to your message first
      std_msgs::Float64MultiArray my_msg;

      my_msg.data = pos;
      pub_joint_pos.publish(my_msg);
      
      my_msg.data = cur;
      pub_joint_cur.publish(my_msg);

      my_msg.data = vel;
      pub_joint_vel.publish(my_msg);

      my_msg.data = active;
      pub_joint_active.publish(my_msg);

      my_msg.data = zeroed;
      pub_joint_zeroed.publish(my_msg);

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
