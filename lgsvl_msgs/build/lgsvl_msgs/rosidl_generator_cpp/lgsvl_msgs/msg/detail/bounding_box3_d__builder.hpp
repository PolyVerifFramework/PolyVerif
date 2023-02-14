// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/BoundingBox3D.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__BOUNDING_BOX3_D__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__BOUNDING_BOX3_D__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/bounding_box3_d__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_BoundingBox3D_size
{
public:
  explicit Init_BoundingBox3D_size(::lgsvl_msgs::msg::BoundingBox3D & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::BoundingBox3D size(::lgsvl_msgs::msg::BoundingBox3D::_size_type arg)
  {
    msg_.size = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::BoundingBox3D msg_;
};

class Init_BoundingBox3D_position
{
public:
  Init_BoundingBox3D_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox3D_size position(::lgsvl_msgs::msg::BoundingBox3D::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_BoundingBox3D_size(msg_);
  }

private:
  ::lgsvl_msgs::msg::BoundingBox3D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::BoundingBox3D>()
{
  return lgsvl_msgs::msg::builder::Init_BoundingBox3D_position();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__BOUNDING_BOX3_D__BUILDER_HPP_
