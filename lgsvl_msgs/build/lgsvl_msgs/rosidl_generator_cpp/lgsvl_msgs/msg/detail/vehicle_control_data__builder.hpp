// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/VehicleControlData.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/vehicle_control_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleControlData_target_gear
{
public:
  explicit Init_VehicleControlData_target_gear(::lgsvl_msgs::msg::VehicleControlData & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::VehicleControlData target_gear(::lgsvl_msgs::msg::VehicleControlData::_target_gear_type arg)
  {
    msg_.target_gear = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleControlData msg_;
};

class Init_VehicleControlData_target_wheel_angular_rate
{
public:
  explicit Init_VehicleControlData_target_wheel_angular_rate(::lgsvl_msgs::msg::VehicleControlData & msg)
  : msg_(msg)
  {}
  Init_VehicleControlData_target_gear target_wheel_angular_rate(::lgsvl_msgs::msg::VehicleControlData::_target_wheel_angular_rate_type arg)
  {
    msg_.target_wheel_angular_rate = std::move(arg);
    return Init_VehicleControlData_target_gear(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleControlData msg_;
};

class Init_VehicleControlData_target_wheel_angle
{
public:
  explicit Init_VehicleControlData_target_wheel_angle(::lgsvl_msgs::msg::VehicleControlData & msg)
  : msg_(msg)
  {}
  Init_VehicleControlData_target_wheel_angular_rate target_wheel_angle(::lgsvl_msgs::msg::VehicleControlData::_target_wheel_angle_type arg)
  {
    msg_.target_wheel_angle = std::move(arg);
    return Init_VehicleControlData_target_wheel_angular_rate(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleControlData msg_;
};

class Init_VehicleControlData_braking_pct
{
public:
  explicit Init_VehicleControlData_braking_pct(::lgsvl_msgs::msg::VehicleControlData & msg)
  : msg_(msg)
  {}
  Init_VehicleControlData_target_wheel_angle braking_pct(::lgsvl_msgs::msg::VehicleControlData::_braking_pct_type arg)
  {
    msg_.braking_pct = std::move(arg);
    return Init_VehicleControlData_target_wheel_angle(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleControlData msg_;
};

class Init_VehicleControlData_acceleration_pct
{
public:
  explicit Init_VehicleControlData_acceleration_pct(::lgsvl_msgs::msg::VehicleControlData & msg)
  : msg_(msg)
  {}
  Init_VehicleControlData_braking_pct acceleration_pct(::lgsvl_msgs::msg::VehicleControlData::_acceleration_pct_type arg)
  {
    msg_.acceleration_pct = std::move(arg);
    return Init_VehicleControlData_braking_pct(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleControlData msg_;
};

class Init_VehicleControlData_header
{
public:
  Init_VehicleControlData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleControlData_acceleration_pct header(::lgsvl_msgs::msg::VehicleControlData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VehicleControlData_acceleration_pct(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleControlData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::VehicleControlData>()
{
  return lgsvl_msgs::msg::builder::Init_VehicleControlData_header();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__BUILDER_HPP_
