/* Auto-generated by genmsg_cpp for file /home/wind/ROS_Packages/drc/hubo_ros_msgs/msg/HuboState.msg */
#ifndef HUBO_ROS_MSGS_MESSAGE_HUBOSTATE_H
#define HUBO_ROS_MSGS_MESSAGE_HUBOSTATE_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "hubo_ros_msgs/HuboJointState.h"
#include "hubo_ros_msgs/HuboIMU.h"
#include "hubo_ros_msgs/HuboIMU.h"
#include "hubo_ros_msgs/HuboIMU.h"
#include "hubo_ros_msgs/HuboFT.h"
#include "hubo_ros_msgs/HuboFT.h"
#include "hubo_ros_msgs/HuboFT.h"
#include "hubo_ros_msgs/HuboFT.h"

namespace hubo_ros_msgs
{
template <class ContainerAllocator>
struct HuboState_ {
  typedef HuboState_<ContainerAllocator> Type;

  HuboState_()
  : joints()
  , imu()
  , left_foot()
  , right_foot()
  , left_wrist()
  , right_wrist()
  , left_ankle()
  , right_ankle()
  {
  }

  HuboState_(const ContainerAllocator& _alloc)
  : joints(_alloc)
  , imu(_alloc)
  , left_foot(_alloc)
  , right_foot(_alloc)
  , left_wrist(_alloc)
  , right_wrist(_alloc)
  , left_ankle(_alloc)
  , right_ankle(_alloc)
  {
  }

  typedef std::vector< ::hubo_ros_msgs::HuboJointState_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::hubo_ros_msgs::HuboJointState_<ContainerAllocator> >::other >  _joints_type;
  std::vector< ::hubo_ros_msgs::HuboJointState_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::hubo_ros_msgs::HuboJointState_<ContainerAllocator> >::other >  joints;

  typedef  ::hubo_ros_msgs::HuboIMU_<ContainerAllocator>  _imu_type;
   ::hubo_ros_msgs::HuboIMU_<ContainerAllocator>  imu;

  typedef  ::hubo_ros_msgs::HuboIMU_<ContainerAllocator>  _left_foot_type;
   ::hubo_ros_msgs::HuboIMU_<ContainerAllocator>  left_foot;

  typedef  ::hubo_ros_msgs::HuboIMU_<ContainerAllocator>  _right_foot_type;
   ::hubo_ros_msgs::HuboIMU_<ContainerAllocator>  right_foot;

  typedef  ::hubo_ros_msgs::HuboFT_<ContainerAllocator>  _left_wrist_type;
   ::hubo_ros_msgs::HuboFT_<ContainerAllocator>  left_wrist;

  typedef  ::hubo_ros_msgs::HuboFT_<ContainerAllocator>  _right_wrist_type;
   ::hubo_ros_msgs::HuboFT_<ContainerAllocator>  right_wrist;

  typedef  ::hubo_ros_msgs::HuboFT_<ContainerAllocator>  _left_ankle_type;
   ::hubo_ros_msgs::HuboFT_<ContainerAllocator>  left_ankle;

  typedef  ::hubo_ros_msgs::HuboFT_<ContainerAllocator>  _right_ankle_type;
   ::hubo_ros_msgs::HuboFT_<ContainerAllocator>  right_ankle;


  typedef boost::shared_ptr< ::hubo_ros_msgs::HuboState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hubo_ros_msgs::HuboState_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct HuboState
typedef  ::hubo_ros_msgs::HuboState_<std::allocator<void> > HuboState;

typedef boost::shared_ptr< ::hubo_ros_msgs::HuboState> HuboStatePtr;
typedef boost::shared_ptr< ::hubo_ros_msgs::HuboState const> HuboStateConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::hubo_ros_msgs::HuboState_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::hubo_ros_msgs::HuboState_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace hubo_ros_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hubo_ros_msgs::HuboState_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hubo_ros_msgs::HuboState_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hubo_ros_msgs::HuboState_<ContainerAllocator> > {
  static const char* value() 
  {
    return "4fcc49221fa083e1c5207aa30b4f35d7";
  }

  static const char* value(const  ::hubo_ros_msgs::HuboState_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x4fcc49221fa083e1ULL;
  static const uint64_t static_value2 = 0xc5207aa30b4f35d7ULL;
};

template<class ContainerAllocator>
struct DataType< ::hubo_ros_msgs::HuboState_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hubo_ros_msgs/HuboState";
  }

  static const char* value(const  ::hubo_ros_msgs::HuboState_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hubo_ros_msgs::HuboState_<ContainerAllocator> > {
  static const char* value() 
  {
    return "HuboJointState[] joints\n\
HuboIMU imu\n\
HuboIMU left_foot\n\
HuboIMU right_foot\n\
HuboFT left_wrist\n\
HuboFT right_wrist\n\
HuboFT left_ankle\n\
HuboFT right_ankle\n\
\n\
================================================================================\n\
MSG: hubo_ros_msgs/HuboJointState\n\
string name\n\
float64 position\n\
float64 velocity\n\
float64 current\n\
float64 temperature\n\
int32 active\n\
int32 zeroed\n\
\n\
================================================================================\n\
MSG: hubo_ros_msgs/HuboIMU\n\
float64 x_acceleration\n\
float64 y_acceleration\n\
float64 z_acceleration\n\
float64 x_rotation\n\
float64 y_rotation\n\
float64 z_rotation\n\
\n\
================================================================================\n\
MSG: hubo_ros_msgs/HuboFT\n\
float64 Mx\n\
float64 My\n\
float64 Fz\n\
\n\
";
  }

  static const char* value(const  ::hubo_ros_msgs::HuboState_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hubo_ros_msgs::HuboState_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.joints);
    stream.next(m.imu);
    stream.next(m.left_foot);
    stream.next(m.right_foot);
    stream.next(m.left_wrist);
    stream.next(m.right_wrist);
    stream.next(m.left_ankle);
    stream.next(m.right_ankle);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct HuboState_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hubo_ros_msgs::HuboState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::hubo_ros_msgs::HuboState_<ContainerAllocator> & v) 
  {
    s << indent << "joints[]" << std::endl;
    for (size_t i = 0; i < v.joints.size(); ++i)
    {
      s << indent << "  joints[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::hubo_ros_msgs::HuboJointState_<ContainerAllocator> >::stream(s, indent + "    ", v.joints[i]);
    }
    s << indent << "imu: ";
s << std::endl;
    Printer< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> >::stream(s, indent + "  ", v.imu);
    s << indent << "left_foot: ";
s << std::endl;
    Printer< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> >::stream(s, indent + "  ", v.left_foot);
    s << indent << "right_foot: ";
s << std::endl;
    Printer< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> >::stream(s, indent + "  ", v.right_foot);
    s << indent << "left_wrist: ";
s << std::endl;
    Printer< ::hubo_ros_msgs::HuboFT_<ContainerAllocator> >::stream(s, indent + "  ", v.left_wrist);
    s << indent << "right_wrist: ";
s << std::endl;
    Printer< ::hubo_ros_msgs::HuboFT_<ContainerAllocator> >::stream(s, indent + "  ", v.right_wrist);
    s << indent << "left_ankle: ";
s << std::endl;
    Printer< ::hubo_ros_msgs::HuboFT_<ContainerAllocator> >::stream(s, indent + "  ", v.left_ankle);
    s << indent << "right_ankle: ";
s << std::endl;
    Printer< ::hubo_ros_msgs::HuboFT_<ContainerAllocator> >::stream(s, indent + "  ", v.right_ankle);
  }
};


} // namespace message_operations
} // namespace ros

#endif // HUBO_ROS_MSGS_MESSAGE_HUBOSTATE_H
