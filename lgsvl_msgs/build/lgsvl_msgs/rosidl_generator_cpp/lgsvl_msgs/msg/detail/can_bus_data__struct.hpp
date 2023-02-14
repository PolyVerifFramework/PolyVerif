// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lgsvl_msgs:msg/CanBusData.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__CAN_BUS_DATA__STRUCT_HPP_
#define LGSVL_MSGS__MSG__DETAIL__CAN_BUS_DATA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__struct.hpp"
// Member 'linear_velocities'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lgsvl_msgs__msg__CanBusData __attribute__((deprecated))
#else
# define DEPRECATED__lgsvl_msgs__msg__CanBusData __declspec(deprecated)
#endif

namespace lgsvl_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CanBusData_
{
  using Type = CanBusData_<ContainerAllocator>;

  explicit CanBusData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    orientation(_init),
    linear_velocities(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed_mps = 0.0f;
      this->throttle_pct = 0.0f;
      this->brake_pct = 0.0f;
      this->steer_pct = 0.0f;
      this->parking_brake_active = false;
      this->high_beams_active = false;
      this->low_beams_active = false;
      this->hazard_lights_active = false;
      this->fog_lights_active = false;
      this->left_turn_signal_active = false;
      this->right_turn_signal_active = false;
      this->wipers_active = false;
      this->reverse_gear_active = false;
      this->selected_gear = 0;
      this->engine_active = false;
      this->engine_rpm = 0.0f;
      this->gps_latitude = 0.0;
      this->gps_longitude = 0.0;
      this->gps_altitude = 0.0;
    }
  }

  explicit CanBusData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    orientation(_alloc, _init),
    linear_velocities(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed_mps = 0.0f;
      this->throttle_pct = 0.0f;
      this->brake_pct = 0.0f;
      this->steer_pct = 0.0f;
      this->parking_brake_active = false;
      this->high_beams_active = false;
      this->low_beams_active = false;
      this->hazard_lights_active = false;
      this->fog_lights_active = false;
      this->left_turn_signal_active = false;
      this->right_turn_signal_active = false;
      this->wipers_active = false;
      this->reverse_gear_active = false;
      this->selected_gear = 0;
      this->engine_active = false;
      this->engine_rpm = 0.0f;
      this->gps_latitude = 0.0;
      this->gps_longitude = 0.0;
      this->gps_altitude = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _speed_mps_type =
    float;
  _speed_mps_type speed_mps;
  using _throttle_pct_type =
    float;
  _throttle_pct_type throttle_pct;
  using _brake_pct_type =
    float;
  _brake_pct_type brake_pct;
  using _steer_pct_type =
    float;
  _steer_pct_type steer_pct;
  using _parking_brake_active_type =
    bool;
  _parking_brake_active_type parking_brake_active;
  using _high_beams_active_type =
    bool;
  _high_beams_active_type high_beams_active;
  using _low_beams_active_type =
    bool;
  _low_beams_active_type low_beams_active;
  using _hazard_lights_active_type =
    bool;
  _hazard_lights_active_type hazard_lights_active;
  using _fog_lights_active_type =
    bool;
  _fog_lights_active_type fog_lights_active;
  using _left_turn_signal_active_type =
    bool;
  _left_turn_signal_active_type left_turn_signal_active;
  using _right_turn_signal_active_type =
    bool;
  _right_turn_signal_active_type right_turn_signal_active;
  using _wipers_active_type =
    bool;
  _wipers_active_type wipers_active;
  using _reverse_gear_active_type =
    bool;
  _reverse_gear_active_type reverse_gear_active;
  using _selected_gear_type =
    int8_t;
  _selected_gear_type selected_gear;
  using _engine_active_type =
    bool;
  _engine_active_type engine_active;
  using _engine_rpm_type =
    float;
  _engine_rpm_type engine_rpm;
  using _gps_latitude_type =
    double;
  _gps_latitude_type gps_latitude;
  using _gps_longitude_type =
    double;
  _gps_longitude_type gps_longitude;
  using _gps_altitude_type =
    double;
  _gps_altitude_type gps_altitude;
  using _orientation_type =
    geometry_msgs::msg::Quaternion_<ContainerAllocator>;
  _orientation_type orientation;
  using _linear_velocities_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _linear_velocities_type linear_velocities;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__speed_mps(
    const float & _arg)
  {
    this->speed_mps = _arg;
    return *this;
  }
  Type & set__throttle_pct(
    const float & _arg)
  {
    this->throttle_pct = _arg;
    return *this;
  }
  Type & set__brake_pct(
    const float & _arg)
  {
    this->brake_pct = _arg;
    return *this;
  }
  Type & set__steer_pct(
    const float & _arg)
  {
    this->steer_pct = _arg;
    return *this;
  }
  Type & set__parking_brake_active(
    const bool & _arg)
  {
    this->parking_brake_active = _arg;
    return *this;
  }
  Type & set__high_beams_active(
    const bool & _arg)
  {
    this->high_beams_active = _arg;
    return *this;
  }
  Type & set__low_beams_active(
    const bool & _arg)
  {
    this->low_beams_active = _arg;
    return *this;
  }
  Type & set__hazard_lights_active(
    const bool & _arg)
  {
    this->hazard_lights_active = _arg;
    return *this;
  }
  Type & set__fog_lights_active(
    const bool & _arg)
  {
    this->fog_lights_active = _arg;
    return *this;
  }
  Type & set__left_turn_signal_active(
    const bool & _arg)
  {
    this->left_turn_signal_active = _arg;
    return *this;
  }
  Type & set__right_turn_signal_active(
    const bool & _arg)
  {
    this->right_turn_signal_active = _arg;
    return *this;
  }
  Type & set__wipers_active(
    const bool & _arg)
  {
    this->wipers_active = _arg;
    return *this;
  }
  Type & set__reverse_gear_active(
    const bool & _arg)
  {
    this->reverse_gear_active = _arg;
    return *this;
  }
  Type & set__selected_gear(
    const int8_t & _arg)
  {
    this->selected_gear = _arg;
    return *this;
  }
  Type & set__engine_active(
    const bool & _arg)
  {
    this->engine_active = _arg;
    return *this;
  }
  Type & set__engine_rpm(
    const float & _arg)
  {
    this->engine_rpm = _arg;
    return *this;
  }
  Type & set__gps_latitude(
    const double & _arg)
  {
    this->gps_latitude = _arg;
    return *this;
  }
  Type & set__gps_longitude(
    const double & _arg)
  {
    this->gps_longitude = _arg;
    return *this;
  }
  Type & set__gps_altitude(
    const double & _arg)
  {
    this->gps_altitude = _arg;
    return *this;
  }
  Type & set__orientation(
    const geometry_msgs::msg::Quaternion_<ContainerAllocator> & _arg)
  {
    this->orientation = _arg;
    return *this;
  }
  Type & set__linear_velocities(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->linear_velocities = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t GEAR_NEUTRAL =
    0;
  static constexpr int8_t GEAR_DRIVE =
    1;
  static constexpr int8_t GEAR_REVERSE =
    2;
  static constexpr int8_t GEAR_PARKING =
    3;
  static constexpr int8_t GEAR_LOW =
    4;

  // pointer types
  using RawPtr =
    lgsvl_msgs::msg::CanBusData_<ContainerAllocator> *;
  using ConstRawPtr =
    const lgsvl_msgs::msg::CanBusData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::CanBusData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::CanBusData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::CanBusData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::CanBusData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::CanBusData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::CanBusData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::CanBusData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::CanBusData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lgsvl_msgs__msg__CanBusData
    std::shared_ptr<lgsvl_msgs::msg::CanBusData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lgsvl_msgs__msg__CanBusData
    std::shared_ptr<lgsvl_msgs::msg::CanBusData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CanBusData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->speed_mps != other.speed_mps) {
      return false;
    }
    if (this->throttle_pct != other.throttle_pct) {
      return false;
    }
    if (this->brake_pct != other.brake_pct) {
      return false;
    }
    if (this->steer_pct != other.steer_pct) {
      return false;
    }
    if (this->parking_brake_active != other.parking_brake_active) {
      return false;
    }
    if (this->high_beams_active != other.high_beams_active) {
      return false;
    }
    if (this->low_beams_active != other.low_beams_active) {
      return false;
    }
    if (this->hazard_lights_active != other.hazard_lights_active) {
      return false;
    }
    if (this->fog_lights_active != other.fog_lights_active) {
      return false;
    }
    if (this->left_turn_signal_active != other.left_turn_signal_active) {
      return false;
    }
    if (this->right_turn_signal_active != other.right_turn_signal_active) {
      return false;
    }
    if (this->wipers_active != other.wipers_active) {
      return false;
    }
    if (this->reverse_gear_active != other.reverse_gear_active) {
      return false;
    }
    if (this->selected_gear != other.selected_gear) {
      return false;
    }
    if (this->engine_active != other.engine_active) {
      return false;
    }
    if (this->engine_rpm != other.engine_rpm) {
      return false;
    }
    if (this->gps_latitude != other.gps_latitude) {
      return false;
    }
    if (this->gps_longitude != other.gps_longitude) {
      return false;
    }
    if (this->gps_altitude != other.gps_altitude) {
      return false;
    }
    if (this->orientation != other.orientation) {
      return false;
    }
    if (this->linear_velocities != other.linear_velocities) {
      return false;
    }
    return true;
  }
  bool operator!=(const CanBusData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CanBusData_

// alias to use template instance with default allocator
using CanBusData =
  lgsvl_msgs::msg::CanBusData_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int8_t CanBusData_<ContainerAllocator>::GEAR_NEUTRAL;
template<typename ContainerAllocator>
constexpr int8_t CanBusData_<ContainerAllocator>::GEAR_DRIVE;
template<typename ContainerAllocator>
constexpr int8_t CanBusData_<ContainerAllocator>::GEAR_REVERSE;
template<typename ContainerAllocator>
constexpr int8_t CanBusData_<ContainerAllocator>::GEAR_PARKING;
template<typename ContainerAllocator>
constexpr int8_t CanBusData_<ContainerAllocator>::GEAR_LOW;

}  // namespace msg

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__CAN_BUS_DATA__STRUCT_HPP_
