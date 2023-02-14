// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lgsvl_msgs:msg/VehicleControlData.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__STRUCT_HPP_
#define LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__lgsvl_msgs__msg__VehicleControlData __attribute__((deprecated))
#else
# define DEPRECATED__lgsvl_msgs__msg__VehicleControlData __declspec(deprecated)
#endif

namespace lgsvl_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleControlData_
{
  using Type = VehicleControlData_<ContainerAllocator>;

  explicit VehicleControlData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->acceleration_pct = 0.0f;
      this->braking_pct = 0.0f;
      this->target_wheel_angle = 0.0f;
      this->target_wheel_angular_rate = 0.0f;
      this->target_gear = 0;
    }
  }

  explicit VehicleControlData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->acceleration_pct = 0.0f;
      this->braking_pct = 0.0f;
      this->target_wheel_angle = 0.0f;
      this->target_wheel_angular_rate = 0.0f;
      this->target_gear = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _acceleration_pct_type =
    float;
  _acceleration_pct_type acceleration_pct;
  using _braking_pct_type =
    float;
  _braking_pct_type braking_pct;
  using _target_wheel_angle_type =
    float;
  _target_wheel_angle_type target_wheel_angle;
  using _target_wheel_angular_rate_type =
    float;
  _target_wheel_angular_rate_type target_wheel_angular_rate;
  using _target_gear_type =
    uint8_t;
  _target_gear_type target_gear;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__acceleration_pct(
    const float & _arg)
  {
    this->acceleration_pct = _arg;
    return *this;
  }
  Type & set__braking_pct(
    const float & _arg)
  {
    this->braking_pct = _arg;
    return *this;
  }
  Type & set__target_wheel_angle(
    const float & _arg)
  {
    this->target_wheel_angle = _arg;
    return *this;
  }
  Type & set__target_wheel_angular_rate(
    const float & _arg)
  {
    this->target_wheel_angular_rate = _arg;
    return *this;
  }
  Type & set__target_gear(
    const uint8_t & _arg)
  {
    this->target_gear = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t GEAR_NEUTRAL =
    0u;
  static constexpr uint8_t GEAR_DRIVE =
    1u;
  static constexpr uint8_t GEAR_REVERSE =
    2u;
  static constexpr uint8_t GEAR_PARKING =
    3u;
  static constexpr uint8_t GEAR_LOW =
    4u;

  // pointer types
  using RawPtr =
    lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator> *;
  using ConstRawPtr =
    const lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lgsvl_msgs__msg__VehicleControlData
    std::shared_ptr<lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lgsvl_msgs__msg__VehicleControlData
    std::shared_ptr<lgsvl_msgs::msg::VehicleControlData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleControlData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->acceleration_pct != other.acceleration_pct) {
      return false;
    }
    if (this->braking_pct != other.braking_pct) {
      return false;
    }
    if (this->target_wheel_angle != other.target_wheel_angle) {
      return false;
    }
    if (this->target_wheel_angular_rate != other.target_wheel_angular_rate) {
      return false;
    }
    if (this->target_gear != other.target_gear) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleControlData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleControlData_

// alias to use template instance with default allocator
using VehicleControlData =
  lgsvl_msgs::msg::VehicleControlData_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr uint8_t VehicleControlData_<ContainerAllocator>::GEAR_NEUTRAL;
template<typename ContainerAllocator>
constexpr uint8_t VehicleControlData_<ContainerAllocator>::GEAR_DRIVE;
template<typename ContainerAllocator>
constexpr uint8_t VehicleControlData_<ContainerAllocator>::GEAR_REVERSE;
template<typename ContainerAllocator>
constexpr uint8_t VehicleControlData_<ContainerAllocator>::GEAR_PARKING;
template<typename ContainerAllocator>
constexpr uint8_t VehicleControlData_<ContainerAllocator>::GEAR_LOW;

}  // namespace msg

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__STRUCT_HPP_
