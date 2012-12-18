FILE(REMOVE_RECURSE
  "../src/hubo_ros/msg"
  "../msg_gen"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/hubo_ros/msg/__init__.py"
  "../src/hubo_ros/msg/_HuboHandCommand.py"
  "../src/hubo_ros/msg/_HuboHand.py"
  "../src/hubo_ros/msg/_HuboCommand.py"
  "../src/hubo_ros/msg/_HuboJointState.py"
  "../src/hubo_ros/msg/_HuboFT.py"
  "../src/hubo_ros/msg/_HuboJointCommand.py"
  "../src/hubo_ros/msg/_HuboState.py"
  "../src/hubo_ros/msg/_HuboIMU.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
