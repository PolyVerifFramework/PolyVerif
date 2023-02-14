// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lgsvl_msgs:msg/DetectedRadarObject.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__BUILDER_HPP_
#define LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__BUILDER_HPP_

#include "lgsvl_msgs/msg/detail/detected_radar_object__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace lgsvl_msgs
{

namespace msg
{

namespace builder
{

class Init_DetectedRadarObject_new_detection
{
public:
  explicit Init_DetectedRadarObject_new_detection(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  ::lgsvl_msgs::msg::DetectedRadarObject new_detection(::lgsvl_msgs::msg::DetectedRadarObject::_new_detection_type arg)
  {
    msg_.new_detection = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_object_state
{
public:
  explicit Init_DetectedRadarObject_object_state(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  Init_DetectedRadarObject_new_detection object_state(::lgsvl_msgs::msg::DetectedRadarObject::_object_state_type arg)
  {
    msg_.object_state = std::move(arg);
    return Init_DetectedRadarObject_new_detection(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_object_collider_size
{
public:
  explicit Init_DetectedRadarObject_object_collider_size(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  Init_DetectedRadarObject_object_state object_collider_size(::lgsvl_msgs::msg::DetectedRadarObject::_object_collider_size_type arg)
  {
    msg_.object_collider_size = std::move(arg);
    return Init_DetectedRadarObject_object_state(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_object_relative_velocity
{
public:
  explicit Init_DetectedRadarObject_object_relative_velocity(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  Init_DetectedRadarObject_object_collider_size object_relative_velocity(::lgsvl_msgs::msg::DetectedRadarObject::_object_relative_velocity_type arg)
  {
    msg_.object_relative_velocity = std::move(arg);
    return Init_DetectedRadarObject_object_collider_size(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_object_relative_position
{
public:
  explicit Init_DetectedRadarObject_object_relative_position(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  Init_DetectedRadarObject_object_relative_velocity object_relative_position(::lgsvl_msgs::msg::DetectedRadarObject::_object_relative_position_type arg)
  {
    msg_.object_relative_position = std::move(arg);
    return Init_DetectedRadarObject_object_relative_velocity(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_object_velocity
{
public:
  explicit Init_DetectedRadarObject_object_velocity(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  Init_DetectedRadarObject_object_relative_position object_velocity(::lgsvl_msgs::msg::DetectedRadarObject::_object_velocity_type arg)
  {
    msg_.object_velocity = std::move(arg);
    return Init_DetectedRadarObject_object_relative_position(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_object_position
{
public:
  explicit Init_DetectedRadarObject_object_position(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  Init_DetectedRadarObject_object_velocity object_position(::lgsvl_msgs::msg::DetectedRadarObject::_object_position_type arg)
  {
    msg_.object_position = std::move(arg);
    return Init_DetectedRadarObject_object_velocity(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_sensor_angle
{
public:
  explicit Init_DetectedRadarObject_sensor_angle(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  Init_DetectedRadarObject_object_position sensor_angle(::lgsvl_msgs::msg::DetectedRadarObject::_sensor_angle_type arg)
  {
    msg_.sensor_angle = std::move(arg);
    return Init_DetectedRadarObject_object_position(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_sensor_velocity
{
public:
  explicit Init_DetectedRadarObject_sensor_velocity(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  Init_DetectedRadarObject_sensor_angle sensor_velocity(::lgsvl_msgs::msg::DetectedRadarObject::_sensor_velocity_type arg)
  {
    msg_.sensor_velocity = std::move(arg);
    return Init_DetectedRadarObject_sensor_angle(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_sensor_position
{
public:
  explicit Init_DetectedRadarObject_sensor_position(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  Init_DetectedRadarObject_sensor_velocity sensor_position(::lgsvl_msgs::msg::DetectedRadarObject::_sensor_position_type arg)
  {
    msg_.sensor_position = std::move(arg);
    return Init_DetectedRadarObject_sensor_velocity(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_sensor_right
{
public:
  explicit Init_DetectedRadarObject_sensor_right(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  Init_DetectedRadarObject_sensor_position sensor_right(::lgsvl_msgs::msg::DetectedRadarObject::_sensor_right_type arg)
  {
    msg_.sensor_right = std::move(arg);
    return Init_DetectedRadarObject_sensor_position(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_sensor_aim
{
public:
  explicit Init_DetectedRadarObject_sensor_aim(::lgsvl_msgs::msg::DetectedRadarObject & msg)
  : msg_(msg)
  {}
  Init_DetectedRadarObject_sensor_right sensor_aim(::lgsvl_msgs::msg::DetectedRadarObject::_sensor_aim_type arg)
  {
    msg_.sensor_aim = std::move(arg);
    return Init_DetectedRadarObject_sensor_right(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

class Init_DetectedRadarObject_id
{
public:
  Init_DetectedRadarObject_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectedRadarObject_sensor_aim id(::lgsvl_msgs::msg::DetectedRadarObject::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_DetectedRadarObject_sensor_aim(msg_);
  }

private:
  ::lgsvl_msgs::msg::DetectedRadarObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lgsvl_msgs::msg::DetectedRadarObject>()
{
  return lgsvl_msgs::msg::builder::Init_DetectedRadarObject_id();
}

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__BUILDER_HPP_
