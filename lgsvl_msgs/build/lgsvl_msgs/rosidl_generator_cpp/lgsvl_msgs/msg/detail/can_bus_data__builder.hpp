// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/CanBusData.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__CAN_BUS_DATA__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__CAN_BUS_DATA__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/can_bus_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_CanBusData_linear_velocities
{
public:
  explicit Init_CanBusData_linear_velocities(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::CanBusData linear_velocities(::lgsvl_msgs::msg::CanBusData::_linear_velocities_type arg)
  {
    msg_.linear_velocities = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_orientation
{
public:
  explicit Init_CanBusData_orientation(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_linear_velocities orientation(::lgsvl_msgs::msg::CanBusData::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return Init_CanBusData_linear_velocities(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_gps_altitude
{
public:
  explicit Init_CanBusData_gps_altitude(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_orientation gps_altitude(::lgsvl_msgs::msg::CanBusData::_gps_altitude_type arg)
  {
    msg_.gps_altitude = std::move(arg);
    return Init_CanBusData_orientation(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_gps_longitude
{
public:
  explicit Init_CanBusData_gps_longitude(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_gps_altitude gps_longitude(::lgsvl_msgs::msg::CanBusData::_gps_longitude_type arg)
  {
    msg_.gps_longitude = std::move(arg);
    return Init_CanBusData_gps_altitude(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_gps_latitude
{
public:
  explicit Init_CanBusData_gps_latitude(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_gps_longitude gps_latitude(::lgsvl_msgs::msg::CanBusData::_gps_latitude_type arg)
  {
    msg_.gps_latitude = std::move(arg);
    return Init_CanBusData_gps_longitude(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_engine_rpm
{
public:
  explicit Init_CanBusData_engine_rpm(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_gps_latitude engine_rpm(::lgsvl_msgs::msg::CanBusData::_engine_rpm_type arg)
  {
    msg_.engine_rpm = std::move(arg);
    return Init_CanBusData_gps_latitude(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_engine_active
{
public:
  explicit Init_CanBusData_engine_active(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_engine_rpm engine_active(::lgsvl_msgs::msg::CanBusData::_engine_active_type arg)
  {
    msg_.engine_active = std::move(arg);
    return Init_CanBusData_engine_rpm(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_selected_gear
{
public:
  explicit Init_CanBusData_selected_gear(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_engine_active selected_gear(::lgsvl_msgs::msg::CanBusData::_selected_gear_type arg)
  {
    msg_.selected_gear = std::move(arg);
    return Init_CanBusData_engine_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_reverse_gear_active
{
public:
  explicit Init_CanBusData_reverse_gear_active(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_selected_gear reverse_gear_active(::lgsvl_msgs::msg::CanBusData::_reverse_gear_active_type arg)
  {
    msg_.reverse_gear_active = std::move(arg);
    return Init_CanBusData_selected_gear(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_wipers_active
{
public:
  explicit Init_CanBusData_wipers_active(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_reverse_gear_active wipers_active(::lgsvl_msgs::msg::CanBusData::_wipers_active_type arg)
  {
    msg_.wipers_active = std::move(arg);
    return Init_CanBusData_reverse_gear_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_right_turn_signal_active
{
public:
  explicit Init_CanBusData_right_turn_signal_active(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_wipers_active right_turn_signal_active(::lgsvl_msgs::msg::CanBusData::_right_turn_signal_active_type arg)
  {
    msg_.right_turn_signal_active = std::move(arg);
    return Init_CanBusData_wipers_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_left_turn_signal_active
{
public:
  explicit Init_CanBusData_left_turn_signal_active(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_right_turn_signal_active left_turn_signal_active(::lgsvl_msgs::msg::CanBusData::_left_turn_signal_active_type arg)
  {
    msg_.left_turn_signal_active = std::move(arg);
    return Init_CanBusData_right_turn_signal_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_fog_lights_active
{
public:
  explicit Init_CanBusData_fog_lights_active(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_left_turn_signal_active fog_lights_active(::lgsvl_msgs::msg::CanBusData::_fog_lights_active_type arg)
  {
    msg_.fog_lights_active = std::move(arg);
    return Init_CanBusData_left_turn_signal_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_hazard_lights_active
{
public:
  explicit Init_CanBusData_hazard_lights_active(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_fog_lights_active hazard_lights_active(::lgsvl_msgs::msg::CanBusData::_hazard_lights_active_type arg)
  {
    msg_.hazard_lights_active = std::move(arg);
    return Init_CanBusData_fog_lights_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_low_beams_active
{
public:
  explicit Init_CanBusData_low_beams_active(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_hazard_lights_active low_beams_active(::lgsvl_msgs::msg::CanBusData::_low_beams_active_type arg)
  {
    msg_.low_beams_active = std::move(arg);
    return Init_CanBusData_hazard_lights_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_high_beams_active
{
public:
  explicit Init_CanBusData_high_beams_active(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_low_beams_active high_beams_active(::lgsvl_msgs::msg::CanBusData::_high_beams_active_type arg)
  {
    msg_.high_beams_active = std::move(arg);
    return Init_CanBusData_low_beams_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_parking_brake_active
{
public:
  explicit Init_CanBusData_parking_brake_active(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_high_beams_active parking_brake_active(::lgsvl_msgs::msg::CanBusData::_parking_brake_active_type arg)
  {
    msg_.parking_brake_active = std::move(arg);
    return Init_CanBusData_high_beams_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_steer_pct
{
public:
  explicit Init_CanBusData_steer_pct(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_parking_brake_active steer_pct(::lgsvl_msgs::msg::CanBusData::_steer_pct_type arg)
  {
    msg_.steer_pct = std::move(arg);
    return Init_CanBusData_parking_brake_active(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_brake_pct
{
public:
  explicit Init_CanBusData_brake_pct(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_steer_pct brake_pct(::lgsvl_msgs::msg::CanBusData::_brake_pct_type arg)
  {
    msg_.brake_pct = std::move(arg);
    return Init_CanBusData_steer_pct(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_throttle_pct
{
public:
  explicit Init_CanBusData_throttle_pct(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_brake_pct throttle_pct(::lgsvl_msgs::msg::CanBusData::_throttle_pct_type arg)
  {
    msg_.throttle_pct = std::move(arg);
    return Init_CanBusData_brake_pct(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_speed_mps
{
public:
  explicit Init_CanBusData_speed_mps(::lgsvl_msgs::msg::CanBusData & msg)
  : msg_(msg)
  {}
  Init_CanBusData_throttle_pct speed_mps(::lgsvl_msgs::msg::CanBusData::_speed_mps_type arg)
  {
    msg_.speed_mps = std::move(arg);
    return Init_CanBusData_throttle_pct(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

class Init_CanBusData_header
{
public:
  Init_CanBusData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CanBusData_speed_mps header(::lgsvl_msgs::msg::CanBusData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CanBusData_speed_mps(msg_);
  }

private:
  ::lgsvl_msgs::msg::CanBusData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::CanBusData>()
{
  return lgsvl_msgs::msg::builder::Init_CanBusData_header();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__CAN_BUS_DATA__BUILDER_HPP_
