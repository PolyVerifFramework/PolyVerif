// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/SignalArray.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__SIGNAL_ARRAY__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__SIGNAL_ARRAY__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/signal_array__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_SignalArray_signals
{
public:
  explicit Init_SignalArray_signals(::lgsvl_msgs::msg::SignalArray & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::SignalArray signals(::lgsvl_msgs::msg::SignalArray::_signals_type arg)
  {
    msg_.signals = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::SignalArray msg_;
};

class Init_SignalArray_header
{
public:
  Init_SignalArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SignalArray_signals header(::lgsvl_msgs::msg::SignalArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SignalArray_signals(msg_);
  }

private:
  ::lgsvl_msgs::msg::SignalArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::SignalArray>()
{
  return lgsvl_msgs::msg::builder::Init_SignalArray_header();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__SIGNAL_ARRAY__BUILDER_HPP_
