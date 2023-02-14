// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/DetectedRadarObjectArray.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/detected_radar_object_array__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_DetectedRadarObjectArray_objects
{
public:
  explicit Init_DetectedRadarObjectArray_objects(::lgsvl_msgs::msg::DetectedRadarObjectArray & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::DetectedRadarObjectArray objects(::lgsvl_msgs::msg::DetectedRadarObjectArray::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObjectArray msg_;
};

class Init_DetectedRadarObjectArray_header
{
public:
  Init_DetectedRadarObjectArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectedRadarObjectArray_objects header(::lgsvl_msgs::msg::DetectedRadarObjectArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DetectedRadarObjectArray_objects(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObjectArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::DetectedRadarObjectArray>()
{
  return lgsvl_msgs::msg::builder::Init_DetectedRadarObjectArray_header();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__BUILDER_HPP_
