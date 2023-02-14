// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lgsvl_msgs:msg/DetectedRadarObject.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__STRUCT_HPP_
#define LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'sensor_aim'
// Member 'sensor_right'
// Member 'sensor_velocity'
// Member 'object_velocity'
// Member 'object_relative_velocity'
// Member 'object_collider_size'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
// Member 'sensor_position'
// Member 'object_position'
// Member 'object_relative_position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lgsvl_msgs__msg__DetectedRadarObject __attribute__((deprecated))
#else
# define DEPRECATED__lgsvl_msgs__msg__DetectedRadarObject __declspec(deprecated)
#endif

namespace lgsvl_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectedRadarObject_
{
  using Type = DetectedRadarObject_<ContainerAllocator>;

  explicit DetectedRadarObject_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sensor_aim(_init),
    sensor_right(_init),
    sensor_position(_init),
    sensor_velocity(_init),
    object_position(_init),
    object_velocity(_init),
    object_relative_position(_init),
    object_relative_velocity(_init),
    object_collider_size(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->sensor_angle = 0.0;
      this->object_state = 0;
      this->new_detection = false;
    }
  }

  explicit DetectedRadarObject_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sensor_aim(_alloc, _init),
    sensor_right(_alloc, _init),
    sensor_position(_alloc, _init),
    sensor_velocity(_alloc, _init),
    object_position(_alloc, _init),
    object_velocity(_alloc, _init),
    object_relative_position(_alloc, _init),
    object_relative_velocity(_alloc, _init),
    object_collider_size(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->sensor_angle = 0.0;
      this->object_state = 0;
      this->new_detection = false;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _sensor_aim_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _sensor_aim_type sensor_aim;
  using _sensor_right_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _sensor_right_type sensor_right;
  using _sensor_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _sensor_position_type sensor_position;
  using _sensor_velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _sensor_velocity_type sensor_velocity;
  using _sensor_angle_type =
    double;
  _sensor_angle_type sensor_angle;
  using _object_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _object_position_type object_position;
  using _object_velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _object_velocity_type object_velocity;
  using _object_relative_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _object_relative_position_type object_relative_position;
  using _object_relative_velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _object_relative_velocity_type object_relative_velocity;
  using _object_collider_size_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _object_collider_size_type object_collider_size;
  using _object_state_type =
    uint8_t;
  _object_state_type object_state;
  using _new_detection_type =
    bool;
  _new_detection_type new_detection;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__sensor_aim(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->sensor_aim = _arg;
    return *this;
  }
  Type & set__sensor_right(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->sensor_right = _arg;
    return *this;
  }
  Type & set__sensor_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->sensor_position = _arg;
    return *this;
  }
  Type & set__sensor_velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->sensor_velocity = _arg;
    return *this;
  }
  Type & set__sensor_angle(
    const double & _arg)
  {
    this->sensor_angle = _arg;
    return *this;
  }
  Type & set__object_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->object_position = _arg;
    return *this;
  }
  Type & set__object_velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->object_velocity = _arg;
    return *this;
  }
  Type & set__object_relative_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->object_relative_position = _arg;
    return *this;
  }
  Type & set__object_relative_velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->object_relative_velocity = _arg;
    return *this;
  }
  Type & set__object_collider_size(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->object_collider_size = _arg;
    return *this;
  }
  Type & set__object_state(
    const uint8_t & _arg)
  {
    this->object_state = _arg;
    return *this;
  }
  Type & set__new_detection(
    const bool & _arg)
  {
    this->new_detection = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t STATE_MOVING =
    0u;
  static constexpr uint8_t STATE_STATIONARY =
    1u;

  // pointer types
  using RawPtr =
    lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator> *;
  using ConstRawPtr =
    const lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lgsvl_msgs__msg__DetectedRadarObject
    std::shared_ptr<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lgsvl_msgs__msg__DetectedRadarObject
    std::shared_ptr<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectedRadarObject_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->sensor_aim != other.sensor_aim) {
      return false;
    }
    if (this->sensor_right != other.sensor_right) {
      return false;
    }
    if (this->sensor_position != other.sensor_position) {
      return false;
    }
    if (this->sensor_velocity != other.sensor_velocity) {
      return false;
    }
    if (this->sensor_angle != other.sensor_angle) {
      return false;
    }
    if (this->object_position != other.object_position) {
      return false;
    }
    if (this->object_velocity != other.object_velocity) {
      return false;
    }
    if (this->object_relative_position != other.object_relative_position) {
      return false;
    }
    if (this->object_relative_velocity != other.object_relative_velocity) {
      return false;
    }
    if (this->object_collider_size != other.object_collider_size) {
      return false;
    }
    if (this->object_state != other.object_state) {
      return false;
    }
    if (this->new_detection != other.new_detection) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectedRadarObject_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectedRadarObject_

// alias to use template instance with default allocator
using DetectedRadarObject =
  lgsvl_msgs::msg::DetectedRadarObject_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr uint8_t DetectedRadarObject_<ContainerAllocator>::STATE_MOVING;
template<typename ContainerAllocator>
constexpr uint8_t DetectedRadarObject_<ContainerAllocator>::STATE_STATIONARY;

}  // namespace msg

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__STRUCT_HPP_
