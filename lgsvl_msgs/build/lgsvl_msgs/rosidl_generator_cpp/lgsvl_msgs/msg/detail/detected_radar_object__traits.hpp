// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lgsvl_msgs:msg/DetectedRadarObject.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__TRAITS_HPP_
#define LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__TRAITS_HPP_

#include "lgsvl_msgs/msg/detail/detected_radar_object__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'sensor_aim'
// Member 'sensor_right'
// Member 'sensor_velocity'
// Member 'object_velocity'
// Member 'object_relative_velocity'
// Member 'object_collider_size'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'sensor_position'
// Member 'object_position'
// Member 'object_relative_position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lgsvl_msgs::msg::DetectedRadarObject>()
{
  return "lgsvl_msgs::msg::DetectedRadarObject";
}

template<>
inline const char * name<lgsvl_msgs::msg::DetectedRadarObject>()
{
  return "lgsvl_msgs/msg/DetectedRadarObject";
}

template<>
struct has_fixed_size<lgsvl_msgs::msg::DetectedRadarObject>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<lgsvl_msgs::msg::DetectedRadarObject>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<lgsvl_msgs::msg::DetectedRadarObject>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__TRAITS_HPP_
