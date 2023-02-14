// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/Signal.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__SIGNAL__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__SIGNAL__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/signal__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_Signal_bbox
{
public:
  explicit Init_Signal_bbox(::lgsvl_msgs::msg::Signal & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::Signal bbox(::lgsvl_msgs::msg::Signal::_bbox_type arg)
  {
    msg_.bbox = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::Signal msg_;
};

class Init_Signal_score
{
public:
  explicit Init_Signal_score(::lgsvl_msgs::msg::Signal & msg)
  : msg_(msg)
  {}
  Init_Signal_bbox score(::lgsvl_msgs::msg::Signal::_score_type arg)
  {
    msg_.score = std::move(arg);
    return Init_Signal_bbox(msg_);
  }

private:
  ::lgsvl_msgs::msg::Signal msg_;
};

class Init_Signal_label
{
public:
  explicit Init_Signal_label(::lgsvl_msgs::msg::Signal & msg)
  : msg_(msg)
  {}
  Init_Signal_score label(::lgsvl_msgs::msg::Signal::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_Signal_score(msg_);
  }

private:
  ::lgsvl_msgs::msg::Signal msg_;
};

class Init_Signal_id
{
public:
  explicit Init_Signal_id(::lgsvl_msgs::msg::Signal & msg)
  : msg_(msg)
  {}
  Init_Signal_label id(::lgsvl_msgs::msg::Signal::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Signal_label(msg_);
  }

private:
  ::lgsvl_msgs::msg::Signal msg_;
};

class Init_Signal_header
{
public:
  Init_Signal_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Signal_id header(::lgsvl_msgs::msg::Signal::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Signal_id(msg_);
  }

private:
  ::lgsvl_msgs::msg::Signal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::Signal>()
{
  return lgsvl_msgs::msg::builder::Init_Signal_header();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__SIGNAL__BUILDER_HPP_
