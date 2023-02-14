// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lgsvl_msgs:msg/BoundingBox2D.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__BOUNDING_BOX2_D__TRAITS_HPP_
#define LGSVL_MSGS__MSG__DETAIL__BOUNDING_BOX2_D__TRAITS_HPP_

#include "lgsvl_msgs/msg/detail/bounding_box2_d__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lgsvl_msgs::msg::BoundingBox2D>()
{
  return "lgsvl_msgs::msg::BoundingBox2D";
}

template<>
inline const char * name<lgsvl_msgs::msg::BoundingBox2D>()
{
  return "lgsvl_msgs/msg/BoundingBox2D";
}

template<>
struct has_fixed_size<lgsvl_msgs::msg::BoundingBox2D>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lgsvl_msgs::msg::BoundingBox2D>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lgsvl_msgs::msg::BoundingBox2D>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LGSVL_MSGS__MSG__DETAIL__BOUNDING_BOX2_D__TRAITS_HPP_
