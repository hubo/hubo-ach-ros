/* Auto-generated by genmsg_cpp for file /home/geovana/projects/hubo-ros/hubo_ros_msgs/msg/HuboHandCommand.msg */
#ifndef HUBO_ROS_MSGS_MESSAGE_HUBOHANDCOMMAND_H
#define HUBO_ROS_MSGS_MESSAGE_HUBOHANDCOMMAND_H
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
struct HuboHandCommand_ {
  typedef HuboHandCommand_<ContainerAllocator> Type;

  HuboHandCommand_()
  : thumb(0.0)
  , index(0.0)
  , middle(0.0)
  , ring(0.0)
  , pinky(0.0)
  {
  }

  HuboHandCommand_(const ContainerAllocator& _alloc)
  : thumb(0.0)
  , index(0.0)
  , middle(0.0)
  , ring(0.0)
  , pinky(0.0)
  {
  }

  typedef double _thumb_type;
  double thumb;

  typedef double _index_type;
  double index;

  typedef double _middle_type;
  double middle;

  typedef double _ring_type;
  double ring;

  typedef double _pinky_type;
  double pinky;


  typedef boost::shared_ptr< ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct HuboHandCommand
typedef  ::hubo_ros_msgs::HuboHandCommand_<std::allocator<void> > HuboHandCommand;

typedef boost::shared_ptr< ::hubo_ros_msgs::HuboHandCommand> HuboHandCommandPtr;
typedef boost::shared_ptr< ::hubo_ros_msgs::HuboHandCommand const> HuboHandCommandConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace hubo_ros_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> > {
  static const char* value() 
  {
    return "866b2feb73aeeddf8529bc2bbe447b0d";
  }

  static const char* value(const  ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x866b2feb73aeeddfULL;
  static const uint64_t static_value2 = 0x8529bc2bbe447b0dULL;
};

template<class ContainerAllocator>
struct DataType< ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hubo_ros_msgs/HuboHandCommand";
  }

  static const char* value(const  ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> > {
  static const char* value() 
  {
    return "float64 thumb\n\
float64 index\n\
float64 middle\n\
float64 ring\n\
float64 pinky\n\
\n\
";
  }

  static const char* value(const  ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.thumb);
    stream.next(m.index);
    stream.next(m.middle);
    stream.next(m.ring);
    stream.next(m.pinky);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct HuboHandCommand_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::hubo_ros_msgs::HuboHandCommand_<ContainerAllocator> & v) 
  {
    s << indent << "thumb: ";
    Printer<double>::stream(s, indent + "  ", v.thumb);
    s << indent << "index: ";
    Printer<double>::stream(s, indent + "  ", v.index);
    s << indent << "middle: ";
    Printer<double>::stream(s, indent + "  ", v.middle);
    s << indent << "ring: ";
    Printer<double>::stream(s, indent + "  ", v.ring);
    s << indent << "pinky: ";
    Printer<double>::stream(s, indent + "  ", v.pinky);
  }
};


} // namespace message_operations
} // namespace ros

#endif // HUBO_ROS_MSGS_MESSAGE_HUBOHANDCOMMAND_H

