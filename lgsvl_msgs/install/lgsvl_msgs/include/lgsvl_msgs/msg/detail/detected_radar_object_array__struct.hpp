// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lgsvl_msgs:msg/DetectedRadarObjectArray.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__STRUCT_HPP_
#define LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__STRUCT_HPP_

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
// Member 'objects'
#include "lgsvl_msgs/msg/detail/detected_radar_object__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lgsvl_msgs__msg__DetectedRadarObjectArray __attribute__((deprecated))
#else
# define DEPRECATED__lgsvl_msgs__msg__DetectedRadarObjectArray __declspec(deprecated)
#endif

namespace lgsvl_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectedRadarObjectArray_
{
  using Type = DetectedRadarObjectArray_<ContainerAllocator>;

  explicit DetectedRadarObjectArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit DetectedRadarObjectArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _objects_type =
    std::vector<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator>, typename ContainerAllocator::template rebind<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator>>::other>;
  _objects_type objects;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__objects(
    const std::vector<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator>, typename ContainerAllocator::template rebind<lgsvl_msgs::msg::DetectedRadarObject_<ContainerAllocator>>::other> & _arg)
  {
    this->objects = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lgsvl_msgs__msg__DetectedRadarObjectArray
    std::shared_ptr<lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lgsvl_msgs__msg__DetectedRadarObjectArray
    std::shared_ptr<lgsvl_msgs::msg::DetectedRadarObjectArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectedRadarObjectArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->objects != other.objects) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectedRadarObjectArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectedRadarObjectArray_

// alias to use template instance with default allocator
using DetectedRadarObjectArray =
  lgsvl_msgs::msg::DetectedRadarObjectArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__STRUCT_HPP_
