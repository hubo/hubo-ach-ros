FILE(REMOVE_RECURSE
  "../src/hubo_ros_msgs/msg"
  "../msg_gen"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/hubo_ros_msgs/HuboHandCommand.h"
  "../msg_gen/cpp/include/hubo_ros_msgs/HuboHand.h"
  "../msg_gen/cpp/include/hubo_ros_msgs/HuboCommand.h"
  "../msg_gen/cpp/include/hubo_ros_msgs/HuboJointState.h"
  "../msg_gen/cpp/include/hubo_ros_msgs/HuboFT.h"
  "../msg_gen/cpp/include/hubo_ros_msgs/HuboJointCommand.h"
  "../msg_gen/cpp/include/hubo_ros_msgs/HuboState.h"
  "../msg_gen/cpp/include/hubo_ros_msgs/HuboIMU.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
