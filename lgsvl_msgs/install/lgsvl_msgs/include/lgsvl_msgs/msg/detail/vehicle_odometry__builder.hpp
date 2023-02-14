// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/VehicleOdometry.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__VEHICLE_ODOMETRY__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__VEHICLE_ODOMETRY__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/vehicle_odometry__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleOdometry_rear_wheel_angle
{
public:
  explicit Init_VehicleOdometry_rear_wheel_angle(::lgsvl_msgs::msg::VehicleOdometry & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::VehicleOdometry rear_wheel_angle(::lgsvl_msgs::msg::VehicleOdometry::_rear_wheel_angle_type arg)
  {
    msg_.rear_wheel_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleOdometry msg_;
};

class Init_VehicleOdometry_front_wheel_angle
{
public:
  explicit Init_VehicleOdometry_front_wheel_angle(::lgsvl_msgs::msg::VehicleOdometry & msg)
  : msg_(msg)
  {}
  Init_VehicleOdometry_rear_wheel_angle front_wheel_angle(::lgsvl_msgs::msg::VehicleOdometry::_front_wheel_angle_type arg)
  {
    msg_.front_wheel_angle = std::move(arg);
    return Init_VehicleOdometry_rear_wheel_angle(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleOdometry msg_;
};

class Init_VehicleOdometry_velocity
{
public:
  explicit Init_VehicleOdometry_velocity(::lgsvl_msgs::msg::VehicleOdometry & msg)
  : msg_(msg)
  {}
  Init_VehicleOdometry_front_wheel_angle velocity(::lgsvl_msgs::msg::VehicleOdometry::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_VehicleOdometry_front_wheel_angle(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleOdometry msg_;
};

class Init_VehicleOdometry_header
{
public:
  Init_VehicleOdometry_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleOdometry_velocity header(::lgsvl_msgs::msg::VehicleOdometry::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VehicleOdometry_velocity(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleOdometry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::VehicleOdometry>()
{
  return lgsvl_msgs::msg::builder::Init_VehicleOdometry_header();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__VEHICLE_ODOMETRY__BUILDER_HPP_
