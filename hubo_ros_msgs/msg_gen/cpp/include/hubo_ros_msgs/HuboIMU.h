/* Auto-generated by genmsg_cpp for file /home/geovana/projects/hubo-ros/hubo_ros_msgs/msg/HuboIMU.msg */
#ifndef HUBO_ROS_MSGS_MESSAGE_HUBOIMU_H
#define HUBO_ROS_MSGS_MESSAGE_HUBOIMU_H
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


namespace hubo_ros_msgs
{
template <class ContainerAllocator>
struct HuboIMU_ {
  typedef HuboIMU_<ContainerAllocator> Type;

  HuboIMU_()
  : x_acceleration(0.0)
  , y_acceleration(0.0)
  , z_acceleration(0.0)
  , x_rotation(0.0)
  , y_rotation(0.0)
  {
  }

  HuboIMU_(const ContainerAllocator& _alloc)
  : x_acceleration(0.0)
  , y_acceleration(0.0)
  , z_acceleration(0.0)
  , x_rotation(0.0)
  , y_rotation(0.0)
  {
  }

  typedef double _x_acceleration_type;
  double x_acceleration;

  typedef double _y_acceleration_type;
  double y_acceleration;

  typedef double _z_acceleration_type;
  double z_acceleration;

  typedef double _x_rotation_type;
  double x_rotation;

  typedef double _y_rotation_type;
  double y_rotation;


  typedef boost::shared_ptr< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct HuboIMU
typedef  ::hubo_ros_msgs::HuboIMU_<std::allocator<void> > HuboIMU;

typedef boost::shared_ptr< ::hubo_ros_msgs::HuboIMU> HuboIMUPtr;
typedef boost::shared_ptr< ::hubo_ros_msgs::HuboIMU const> HuboIMUConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace hubo_ros_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> > {
  static const char* value() 
  {
    return "9c14264f3bcdc765b4eeefc475d9111c";
  }

  static const char* value(const  ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x9c14264f3bcdc765ULL;
  static const uint64_t static_value2 = 0xb4eeefc475d9111cULL;
};

template<class ContainerAllocator>
struct DataType< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hubo_ros_msgs/HuboIMU";
  }

  static const char* value(const  ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> > {
  static const char* value() 
  {
    return "float64 x_acceleration\n\
float64 y_acceleration\n\
float64 z_acceleration\n\
float64 x_rotation\n\
float64 y_rotation\n\
\n\
";
  }

  static const char* value(const  ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.x_acceleration);
    stream.next(m.y_acceleration);
    stream.next(m.z_acceleration);
    stream.next(m.x_rotation);
    stream.next(m.y_rotation);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct HuboIMU_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::hubo_ros_msgs::HuboIMU_<ContainerAllocator> & v) 
  {
    s << indent << "x_acceleration: ";
    Printer<double>::stream(s, indent + "  ", v.x_acceleration);
    s << indent << "y_acceleration: ";
    Printer<double>::stream(s, indent + "  ", v.y_acceleration);
    s << indent << "z_acceleration: ";
    Printer<double>::stream(s, indent + "  ", v.z_acceleration);
    s << indent << "x_rotation: ";
    Printer<double>::stream(s, indent + "  ", v.x_rotation);
    s << indent << "y_rotation: ";
    Printer<double>::stream(s, indent + "  ", v.y_rotation);
  }
};


} // namespace message_operations
} // namespace ros

#endif // HUBO_ROS_MSGS_MESSAGE_HUBOIMU_H

