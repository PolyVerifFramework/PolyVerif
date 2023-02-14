// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lgsvl_msgs:msg/VehicleControlData.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__TRAITS_HPP_
#define LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__TRAITS_HPP_

#include "lgsvl_msgs/msg/detail/vehicle_control_data__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lgsvl_msgs::msg::VehicleControlData>()
{
  return "lgsvl_msgs::msg::VehicleControlData";
}

template<>
inline const char * name<lgsvl_msgs::msg::VehicleControlData>()
{
  return "lgsvl_msgs/msg/VehicleControlData";
}

template<>
struct has_fixed_size<lgsvl_msgs::msg::VehicleControlData>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<lgsvl_msgs::msg::VehicleControlData>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<lgsvl_msgs::msg::VehicleControlData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__TRAITS_HPP_
