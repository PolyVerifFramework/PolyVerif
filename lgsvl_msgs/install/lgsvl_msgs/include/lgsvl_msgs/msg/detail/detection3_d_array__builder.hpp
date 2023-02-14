// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/Detection3DArray.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTION3_D_ARRAY__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__DETECTION3_D_ARRAY__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/detection3_d_array__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_Detection3DArray_detections
{
public:
  explicit Init_Detection3DArray_detections(::lgsvl_msgs::msg::Detection3DArray & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::Detection3DArray detections(::lgsvl_msgs::msg::Detection3DArray::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::Detection3DArray msg_;
};

class Init_Detection3DArray_header
{
public:
  Init_Detection3DArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection3DArray_detections header(::lgsvl_msgs::msg::Detection3DArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Detection3DArray_detections(msg_);
  }

private:
  ::lgsvl_msgs::msg::Detection3DArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::Detection3DArray>()
{
  return lgsvl_msgs::msg::builder::Init_Detection3DArray_header();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTION3_D_ARRAY__BUILDER_HPP_
