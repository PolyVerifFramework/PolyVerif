// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lgsvl_msgs:msg/Signal.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__SIGNAL__STRUCT_HPP_
#define LGSVL_MSGS__MSG__DETAIL__SIGNAL__STRUCT_HPP_

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
// Member 'bbox'
#include "lgsvl_msgs/msg/detail/bounding_box3_d__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lgsvl_msgs__msg__Signal __attribute__((deprecated))
#else
# define DEPRECATED__lgsvl_msgs__msg__Signal __declspec(deprecated)
#endif

namespace lgsvl_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Signal_
{
  using Type = Signal_<ContainerAllocator>;

  explicit Signal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    bbox(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->label = "";
      this->score = 0.0f;
    }
  }

  explicit Signal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    label(_alloc),
    bbox(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->label = "";
      this->score = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _id_type =
    uint32_t;
  _id_type id;
  using _label_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _label_type label;
  using _score_type =
    float;
  _score_type score;
  using _bbox_type =
    lgsvl_msgs::msg::BoundingBox3D_<ContainerAllocator>;
  _bbox_type bbox;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__id(
    const uint32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__label(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->label = _arg;
    return *this;
  }
  Type & set__score(
    const float & _arg)
  {
    this->score = _arg;
    return *this;
  }
  Type & set__bbox(
    const lgsvl_msgs::msg::BoundingBox3D_<ContainerAllocator> & _arg)
  {
    this->bbox = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lgsvl_msgs::msg::Signal_<ContainerAllocator> *;
  using ConstRawPtr =
    const lgsvl_msgs::msg::Signal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::Signal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::Signal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::Signal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::Signal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::Signal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::Signal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::Signal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::Signal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lgsvl_msgs__msg__Signal
    std::shared_ptr<lgsvl_msgs::msg::Signal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lgsvl_msgs__msg__Signal
    std::shared_ptr<lgsvl_msgs::msg::Signal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Signal_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->label != other.label) {
      return false;
    }
    if (this->score != other.score) {
      return false;
    }
    if (this->bbox != other.bbox) {
      return false;
    }
    return true;
  }
  bool operator!=(const Signal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Signal_

// alias to use template instance with default allocator
using Signal =
  lgsvl_msgs::msg::Signal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__SIGNAL__STRUCT_HPP_
