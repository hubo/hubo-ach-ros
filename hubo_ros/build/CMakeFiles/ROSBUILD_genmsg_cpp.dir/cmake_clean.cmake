FILE(REMOVE_RECURSE
  "../src/hubo_ros/msg"
  "../msg_gen"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/hubo_ros/HuboHandCommand.h"
  "../msg_gen/cpp/include/hubo_ros/HuboHand.h"
  "../msg_gen/cpp/include/hubo_ros/HuboCommand.h"
  "../msg_gen/cpp/include/hubo_ros/HuboJointState.h"
  "../msg_gen/cpp/include/hubo_ros/HuboFT.h"
  "../msg_gen/cpp/include/hubo_ros/HuboJointCommand.h"
  "../msg_gen/cpp/include/hubo_ros/HuboState.h"
  "../msg_gen/cpp/include/hubo_ros/HuboIMU.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
