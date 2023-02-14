// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/Ultrasonic.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__ULTRASONIC__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__ULTRASONIC__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/ultrasonic__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_Ultrasonic_minimum_distance
{
public:
  explicit Init_Ultrasonic_minimum_distance(::lgsvl_msgs::msg::Ultrasonic & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::Ultrasonic minimum_distance(::lgsvl_msgs::msg::Ultrasonic::_minimum_distance_type arg)
  {
    msg_.minimum_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::Ultrasonic msg_;
};

class Init_Ultrasonic_header
{
public:
  Init_Ultrasonic_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Ultrasonic_minimum_distance header(::lgsvl_msgs::msg::Ultrasonic::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Ultrasonic_minimum_distance(msg_);
  }

private:
  ::lgsvl_msgs::msg::Ultrasonic msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::Ultrasonic>()
{
  return lgsvl_msgs::msg::builder::Init_Ultrasonic_header();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__ULTRASONIC__BUILDER_HPP_
