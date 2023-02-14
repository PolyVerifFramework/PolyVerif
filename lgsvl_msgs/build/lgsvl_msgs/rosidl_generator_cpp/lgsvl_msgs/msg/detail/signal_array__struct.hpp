// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lgsvl_msgs:msg/SignalArray.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__SIGNAL_ARRAY__STRUCT_HPP_
#define LGSVL_MSGS__MSG__DETAIL__SIGNAL_ARRAY__STRUCT_HPP_

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
// Member 'signals'
#include "lgsvl_msgs/msg/detail/signal__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lgsvl_msgs__msg__SignalArray __attribute__((deprecated))
#else
# define DEPRECATED__lgsvl_msgs__msg__SignalArray __declspec(deprecated)
#endif

namespace lgsvl_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SignalArray_
{
  using Type = SignalArray_<ContainerAllocator>;

  explicit SignalArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit SignalArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _signals_type =
    std::vector<lgsvl_msgs::msg::Signal_<ContainerAllocator>, typename ContainerAllocator::template rebind<lgsvl_msgs::msg::Signal_<ContainerAllocator>>::other>;
  _signals_type signals;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__signals(
    const std::vector<lgsvl_msgs::msg::Signal_<ContainerAllocator>, typename ContainerAllocator::template rebind<lgsvl_msgs::msg::Signal_<ContainerAllocator>>::other> & _arg)
  {
    this->signals = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lgsvl_msgs::msg::SignalArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const lgsvl_msgs::msg::SignalArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::SignalArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lgsvl_msgs::msg::SignalArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::SignalArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::SignalArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lgsvl_msgs::msg::SignalArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lgsvl_msgs::msg::SignalArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::SignalArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lgsvl_msgs::msg::SignalArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lgsvl_msgs__msg__SignalArray
    std::shared_ptr<lgsvl_msgs::msg::SignalArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lgsvl_msgs__msg__SignalArray
    std::shared_ptr<lgsvl_msgs::msg::SignalArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SignalArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->signals != other.signals) {
      return false;
    }
    return true;
  }
  bool operator!=(const SignalArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SignalArray_

// alias to use template instance with default allocator
using SignalArray =
  lgsvl_msgs::msg::SignalArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lgsvl_msgs

#endif  // LGSVL_MSGS__MSG__DETAIL__SIGNAL_ARRAY__STRUCT_HPP_
