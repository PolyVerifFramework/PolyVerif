// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/VehicleStateData.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__VEHICLE_STATE_DATA__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__VEHICLE_STATE_DATA__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/vehicle_state_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleStateData_autonomous_mode_active
{
public:
  explicit Init_VehicleStateData_autonomous_mode_active(::lgsvl_msgs::msg::VehicleStateData & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::VehicleStateData autonomous_mode_active(::lgsvl_msgs::msg::VehicleStateData::_autonomous_mode_active_type arg)
  {
    msg_.autonomous_mode_active = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleStateData msg_;
};

class Init_VehicleStateData_horn_active
{
public:
  explicit Init_VehicleStateData_horn_active(::lgsvl_msgs::msg::VehicleStateData & msg)
  : msg_(msg)
  {}
  Init_VehicleStateData_autonomous_mode_active horn_active(::lgsvl_msgs::msg::VehicleStateData::_horn_active_type arg)
  {
    msg_.horn_active = std::move(arg);
    return Init_VehicleStateData_autonomous_mode_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleStateData msg_;
};

class Init_VehicleStateData_hand_brake_active
{
public:
  explicit Init_VehicleStateData_hand_brake_active(::lgsvl_msgs::msg::VehicleStateData & msg)
  : msg_(msg)
  {}
  Init_VehicleStateData_horn_active hand_brake_active(::lgsvl_msgs::msg::VehicleStateData::_hand_brake_active_type arg)
  {
    msg_.hand_brake_active = std::move(arg);
    return Init_VehicleStateData_horn_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleStateData msg_;
};

class Init_VehicleStateData_vehicle_mode
{
public:
  explicit Init_VehicleStateData_vehicle_mode(::lgsvl_msgs::msg::VehicleStateData & msg)
  : msg_(msg)
  {}
  Init_VehicleStateData_hand_brake_active vehicle_mode(::lgsvl_msgs::msg::VehicleStateData::_vehicle_mode_type arg)
  {
    msg_.vehicle_mode = std::move(arg);
    return Init_VehicleStateData_hand_brake_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleStateData msg_;
};

class Init_VehicleStateData_current_gear
{
public:
  explicit Init_VehicleStateData_current_gear(::lgsvl_msgs::msg::VehicleStateData & msg)
  : msg_(msg)
  {}
  Init_VehicleStateData_vehicle_mode current_gear(::lgsvl_msgs::msg::VehicleStateData::_current_gear_type arg)
  {
    msg_.current_gear = std::move(arg);
    return Init_VehicleStateData_vehicle_mode(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleStateData msg_;
};

class Init_VehicleStateData_wiper_state
{
public:
  explicit Init_VehicleStateData_wiper_state(::lgsvl_msgs::msg::VehicleStateData & msg)
  : msg_(msg)
  {}
  Init_VehicleStateData_current_gear wiper_state(::lgsvl_msgs::msg::VehicleStateData::_wiper_state_type arg)
  {
    msg_.wiper_state = std::move(arg);
    return Init_VehicleStateData_current_gear(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleStateData msg_;
};

class Init_VehicleStateData_headlight_state
{
public:
  explicit Init_VehicleStateData_headlight_state(::lgsvl_msgs::msg::VehicleStateData & msg)
  : msg_(msg)
  {}
  Init_VehicleStateData_wiper_state headlight_state(::lgsvl_msgs::msg::VehicleStateData::_headlight_state_type arg)
  {
    msg_.headlight_state = std::move(arg);
    return Init_VehicleStateData_wiper_state(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleStateData msg_;
};

class Init_VehicleStateData_blinker_state
{
public:
  explicit Init_VehicleStateData_blinker_state(::lgsvl_msgs::msg::VehicleStateData & msg)
  : msg_(msg)
  {}
  Init_VehicleStateData_headlight_state blinker_state(::lgsvl_msgs::msg::VehicleStateData::_blinker_state_type arg)
  {
    msg_.blinker_state = std::move(arg);
    return Init_VehicleStateData_headlight_state(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleStateData msg_;
};

class Init_VehicleStateData_header
{
public:
  Init_VehicleStateData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleStateData_blinker_state header(::lgsvl_msgs::msg::VehicleStateData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VehicleStateData_blinker_state(msg_);
  }

private:
  ::lgsvl_msgs::msg::VehicleStateData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::VehicleStateData>()
{
  return lgsvl_msgs::msg::builder::Init_VehicleStateData_header();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__VEHICLE_STATE_DATA__BUILDER_HPP_
