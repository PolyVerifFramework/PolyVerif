// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lgsvl_msgs:msg/Signal.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__SIGNAL__TRAITS_HPP_
#define LGSVL_MSGS__MSG__DETAIL__SIGNAL__TRAITS_HPP_

#include "lgsvl_msgs/msg/detail/signal__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'bbox'
#include "lgsvl_msgs/msg/detail/bounding_box3_d__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lgsvl_msgs::msg::Signal>()
{
  return "lgsvl_msgs::msg::Signal";
}

template<>
inline const char * name<lgsvl_msgs::msg::Signal>()
{
  return "lgsvl_msgs/msg/Signal";
}

template<>
struct has_fixed_size<lgsvl_msgs::msg::Signal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lgsvl_msgs::msg::Signal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lgsvl_msgs::msg::Signal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LGSVL_MSGS__MSG__DETAIL__SIGNAL__TRAITS_HPP_
