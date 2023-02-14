// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lgsvl_msgs:msg/VehicleStateData.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__VEHICLE_STATE_DATA__STRUCT_HPP_
#define LGSVL_MSGS__MSG__DETAIL__VEHICLE_STATE_DATA__STRUCT_HPP_

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
# define DEPRECATED__lgsvl_msgs__msg__VehicleStateData __attribute__((deprecated))
#else
# define DEPRECATED__lgsvl_msgs__msg__VehicleStateData __declspec(deprecated)
#endif

namespace lgsvl_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleStateData_
{
  using Type = VehicleStateData_<ContainerAllocator>;

  explicit VehicleStateData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->blinker_state = 0;
      this->headlight_state = 0;
      this->wiper_state = 0;
      this->current_gear = 0;
      this->vehicle_mode = 0;
      this->hand_brake_active = false;
      this->horn_active = false;
      this->autonomous_mode_active = false;
    }
  }

  explicit VehicleStateData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->blinker_state = 0;
      this->headlight_state = 0;
      this->wiper_state = 0;
      this->current_gear = 0;
      this->vehicle_mode = 0;
      this->hand_brake_active = false;
      this->horn_active = false;
      this->autonomous_mode_active = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _blinker_state_type =
    uint8_t;
  _blinker_state_type blinker_state;
  using _headlight_state_type =
    uint8_t;
  _headlight_state_type headlight_state;
  using _wiper_state_type =
    uint8_t;
  _wiper_state_type wiper_state;
  using _current_gear_type =
    uint8_t;
  _current_gear_type current_gear;
  using _vehicle_mode_type =
    uint8_t;
  _vehicle_mode_type vehicle_mode;
  using _hand_brake_active_type =
    bool;
  _hand_brake_active_type hand_brake_active;
  using _horn_active_type =
    bool;
  _horn_active_type horn_active;
  using _autonomous_mode_active_type =
    bool;
  _autonomous_mode_active_type autonomous_mode_active;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__blinker_state(
    const uint8_t & _arg)
  {
    this->blinker_state = _arg;
    return *this;
  }
  Type & set__headlight_state(
    const uint8_t & _arg)
  {
    this->headlight_state = _arg;
    return *this;
  }
  Type & set__wiper_state(
    const uint8_t & _arg)
  {
    this->wiper_state = _arg;
    return *this;
  }
  Type & set__current_gear(
    const uint8_t & _arg)
  {
    this->current_gear = _arg;
    return *this;
  }
  Type & set__vehicle_mode(
    const uint8_t & _arg)
  {
    this->vehicle_mode = _arg;
    return *this;
  }
  Type & set__hand_brake_active(
    const bool & _arg)
  {
    this->hand_brake_active = _arg;
    return *this;
  }
  Type & set__horn_active(
    const bool & _arg)
  {
    this->horn_active = _arg;
    return *this;
  }
  Type & set__autonomous_mode_active(
    const bool & _arg)
  {
    this->autonomous_mode_active = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t BLINKERS_OFF =
    0u;
  static constexpr uint8_t BLINKERS_LEFT =
    1u;
  static constexpr uint8_t BLINKERS_RIGHT =
    2u;
  static constexpr uint8_t BLINKERS_HAZARD =
    3u;
  static constexpr uint8_t HEADLIGHTS_OFF =
    0u;
  static constexpr uint8_t HEADLIGHTS_LOW =
    1u;
  static constexpr uint8_t HEADLIGHTS_HIGH =
    2u;
  static constexpr uint8_t WIPERS_OFF =
    0u;
  static constexpr uint8_t WIPERS_LOW =
    1u;
  static constexpr uint8_t WIPERS_MED =
    2u;
  static constexpr uint8_t WIPERS_HIGH =
    3u;
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
  static constexpr uint8_t VEHICLE_MODE_COMPLETE_MANUAL =
    0u;
  static constexpr uint8_t VEHICLE_MODE_COMPLETE_AUTO_DRIVE =
    1u;
  static constexpr uint8_t VEHICLE_MODE_AUTO_STEER_ONLY =
    2u;
  static constexpr uint8_t VEHICLE_MODE_AUTO_SPEED_ONLY =
    3u;
  static constexpr uint8_t VEHICLE_MODE_EMERGENCY_MODE =
    4u;

  // pointer types
  using RawPtr =
    lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator> *;
  using ConstRawPtr =
    const lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lgsvl_msgs__msg__VehicleStateData
    std::shared_ptr<lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lgsvl_msgs__msg__VehicleStateData
    std::shared_ptr<lgsvl_msgs::msg::VehicleStateData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleStateData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->blinker_state != other.blinker_state) {
      return false;
    }
    if (this->headlight_state != other.headlight_state) {
      return false;
    }
    if (this->wiper_state != other.wiper_state) {
      return false;
    }
    if (this->current_gear != other.current_gear) {
      return false;
    }
    if (this->vehicle_mode != other.vehicle_mode) {
      return false;
    }
    if (this->hand_brake_active != other.hand_brake_active) {
      return false;
    }
    if (this->horn_active != other.horn_active) {
      return false;
    }
    if (this->autonomous_mode_active != other.autonomous_mode_active) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleStateData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleStateData_

// alias to use template instance with default allocator
using VehicleStateData =
  lgsvl_msgs::msg::VehicleStateData_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::BLINKERS_OFF;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::BLINKERS_LEFT;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::BLINKERS_RIGHT;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::BLINKERS_HAZARD;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::HEADLIGHTS_OFF;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::HEADLIGHTS_LOW;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::HEADLIGHTS_HIGH;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::WIPERS_OFF;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::WIPERS_LOW;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::WIPERS_MED;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::WIPERS_HIGH;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::GEAR_NEUTRAL;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::GEAR_DRIVE;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::GEAR_REVERSE;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::GEAR_PARKING;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::GEAR_LOW;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::VEHICLE_MODE_COMPLETE_MANUAL;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::VEHICLE_MODE_COMPLETE_AUTO_DRIVE;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::VEHICLE_MODE_AUTO_STEER_ONLY;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::VEHICLE_MODE_AUTO_SPEED_ONLY;
template<typename ContainerAllocator>
constexpr uint8_t VehicleStateData_<ContainerAllocator>::VEHICLE_MODE_EMERGENCY_MODE;

}  // namespace msg

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__VEHICLE_STATE_DATA__STRUCT_HPP_
