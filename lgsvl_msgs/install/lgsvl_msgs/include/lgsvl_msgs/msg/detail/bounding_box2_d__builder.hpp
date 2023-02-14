// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/BoundingBox2D.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__BOUNDING_BOX2_D__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__BOUNDING_BOX2_D__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/bounding_box2_d__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_BoundingBox2D_height
{
public:
  explicit Init_BoundingBox2D_height(::lgsvl_msgs::msg::BoundingBox2D & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::BoundingBox2D height(::lgsvl_msgs::msg::BoundingBox2D::_height_type arg)
  {
    msg_.height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::BoundingBox2D msg_;
};

class Init_BoundingBox2D_width
{
public:
  explicit Init_BoundingBox2D_width(::lgsvl_msgs::msg::BoundingBox2D & msg)
  : msg_(msg)
  {}
  Init_BoundingBox2D_height width(::lgsvl_msgs::msg::BoundingBox2D::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_BoundingBox2D_height(msg_);
  }

private:
  ::lgsvl_msgs::msg::BoundingBox2D msg_;
};

class Init_BoundingBox2D_y
{
public:
  explicit Init_BoundingBox2D_y(::lgsvl_msgs::msg::BoundingBox2D & msg)
  : msg_(msg)
  {}
  Init_BoundingBox2D_width y(::lgsvl_msgs::msg::BoundingBox2D::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_BoundingBox2D_width(msg_);
  }

private:
  ::lgsvl_msgs::msg::BoundingBox2D msg_;
};

class Init_BoundingBox2D_x
{
public:
  Init_BoundingBox2D_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox2D_y x(::lgsvl_msgs::msg::BoundingBox2D::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_BoundingBox2D_y(msg_);
  }

private:
  ::lgsvl_msgs::msg::BoundingBox2D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::BoundingBox2D>()
{
  return lgsvl_msgs::msg::builder::Init_BoundingBox2D_x();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__BOUNDING_BOX2_D__BUILDER_HPP_
