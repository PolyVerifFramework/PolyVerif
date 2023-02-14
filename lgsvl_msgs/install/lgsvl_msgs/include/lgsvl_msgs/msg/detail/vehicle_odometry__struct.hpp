// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lgsvl_msgs:msg/VehicleOdometry.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__VEHICLE_ODOMETRY__STRUCT_HPP_
#define LGSVL_MSGS__MSG__DETAIL__VEHICLE_ODOMETRY__STRUCT_HPP_

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
# define DEPRECATED__lgsvl_msgs__msg__VehicleOdometry __attribute__((deprecated))
#else
# define DEPRECATED__lgsvl_msgs__msg__VehicleOdometry __declspec(deprecated)
#endif

namespace lgsvl_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleOdometry_
{
  using Type = VehicleOdometry_<ContainerAllocator>;

  explicit VehicleOdometry_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0f;
      this->front_wheel_angle = 0.0f;
      this->rear_wheel_angle = 0.0f;
    }
  }

  explicit VehicleOdometry_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0f;
      this->front_wheel_angle = 0.0f;
      this->rear_wheel_angle = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _velocity_type =
    float;
  _velocity_type velocity;
  using _front_wheel_angle_type =
    float;
  _front_wheel_angle_type front_wheel_angle;
  using _rear_wheel_angle_type =
    float;
  _rear_wheel_angle_type rear_wheel_angle;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__velocity(
    const float & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__front_wheel_angle(
    const float & _arg)
  {
    this->front_wheel_angle = _arg;
    return *this;
  }
  Type & set__rear_wheel_angle(
    const float & _arg)
  {
    this->rear_wheel_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator> *;
  using ConstRawPtr =
    const lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lgsvl_msgs__msg__VehicleOdometry
    std::shared_ptr<lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lgsvl_msgs__msg__VehicleOdometry
    std::shared_ptr<lgsvl_msgs::msg::VehicleOdometry_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleOdometry_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->front_wheel_angle != other.front_wheel_angle) {
      return false;
    }
    if (this->rear_wheel_angle != other.rear_wheel_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleOdometry_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleOdometry_

// alias to use template instance with default allocator
using VehicleOdometry =
  lgsvl_msgs::msg::VehicleOdometry_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__VEHICLE_ODOMETRY__STRUCT_HPP_
