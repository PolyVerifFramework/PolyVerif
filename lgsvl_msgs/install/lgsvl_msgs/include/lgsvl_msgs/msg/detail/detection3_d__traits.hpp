// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lgsvl_msgs:msg/Detection3D.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTION3_D__TRAITS_HPP_
#define LGSVL_MSGS__MSG__DETAIL__DETECTION3_D__TRAITS_HPP_

#include "lgsvl_msgs/msg/detail/detection3_d__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'bbox'
#include "lgsvl_msgs/msg/detail/bounding_box3_d__traits.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lgsvl_msgs::msg::Detection3D>()
{
  return "lgsvl_msgs::msg::Detection3D";
}

template<>
inline const char * name<lgsvl_msgs::msg::Detection3D>()
{
  return "lgsvl_msgs/msg/Detection3D";
}

template<>
struct has_fixed_size<lgsvl_msgs::msg::Detection3D>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lgsvl_msgs::msg::Detection3D>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lgsvl_msgs::msg::Detection3D>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTION3_D__TRAITS_HPP_
