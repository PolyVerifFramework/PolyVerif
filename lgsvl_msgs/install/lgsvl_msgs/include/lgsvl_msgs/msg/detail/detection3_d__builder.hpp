// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/Detection3D.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTION3_D__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__DETECTION3_D__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/detection3_d__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_Detection3D_velocity
{
public:
  explicit Init_Detection3D_velocity(::lgsvl_msgs::msg::Detection3D & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::Detection3D velocity(::lgsvl_msgs::msg::Detection3D::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::Detection3D msg_;
};

class Init_Detection3D_bbox
{
public:
  explicit Init_Detection3D_bbox(::lgsvl_msgs::msg::Detection3D & msg)
  : msg_(msg)
  {}
  Init_Detection3D_velocity bbox(::lgsvl_msgs::msg::Detection3D::_bbox_type arg)
  {
    msg_.bbox = std::move(arg);
    return Init_Detection3D_velocity(msg_);
  }

private:
  ::lgsvl_msgs::msg::Detection3D msg_;
};

class Init_Detection3D_score
{
public:
  explicit Init_Detection3D_score(::lgsvl_msgs::msg::Detection3D & msg)
  : msg_(msg)
  {}
  Init_Detection3D_bbox score(::lgsvl_msgs::msg::Detection3D::_score_type arg)
  {
    msg_.score = std::move(arg);
    return Init_Detection3D_bbox(msg_);
  }

private:
  ::lgsvl_msgs::msg::Detection3D msg_;
};

class Init_Detection3D_label
{
public:
  explicit Init_Detection3D_label(::lgsvl_msgs::msg::Detection3D & msg)
  : msg_(msg)
  {}
  Init_Detection3D_score label(::lgsvl_msgs::msg::Detection3D::_label_type arg)
  {
    msg_.label = std::move(arg);
    return Init_Detection3D_score(msg_);
  }

private:
  ::lgsvl_msgs::msg::Detection3D msg_;
};

class Init_Detection3D_id
{
public:
  explicit Init_Detection3D_id(::lgsvl_msgs::msg::Detection3D & msg)
  : msg_(msg)
  {}
  Init_Detection3D_label id(::lgsvl_msgs::msg::Detection3D::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Detection3D_label(msg_);
  }

private:
  ::lgsvl_msgs::msg::Detection3D msg_;
};

class Init_Detection3D_header
{
public:
  Init_Detection3D_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection3D_id header(::lgsvl_msgs::msg::Detection3D::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Detection3D_id(msg_);
  }

private:
  ::lgsvl_msgs::msg::Detection3D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::Detection3D>()
{
  return lgsvl_msgs::msg::builder::Init_Detection3D_header();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTION3_D__BUILDER_HPP_
