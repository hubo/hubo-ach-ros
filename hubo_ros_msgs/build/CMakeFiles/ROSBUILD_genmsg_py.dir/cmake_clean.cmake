FILE(REMOVE_RECURSE
  "../src/hubo_ros_msgs/msg"
  "../msg_gen"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/hubo_ros_msgs/msg/__init__.py"
  "../src/hubo_ros_msgs/msg/_HuboHandCommand.py"
  "../src/hubo_ros_msgs/msg/_HuboHand.py"
  "../src/hubo_ros_msgs/msg/_HuboCommand.py"
  "../src/hubo_ros_msgs/msg/_HuboJointState.py"
  "../src/hubo_ros_msgs/msg/_HuboFT.py"
  "../src/hubo_ros_msgs/msg/_HuboJointCommand.py"
  "../src/hubo_ros_msgs/msg/_HuboState.py"
  "../src/hubo_ros_msgs/msg/_HuboIMU.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
