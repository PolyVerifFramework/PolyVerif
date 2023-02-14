// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from lgsvl_msgs:msg/VehicleOdometry.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "lgsvl_msgs/msg/detail/vehicle_odometry__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace lgsvl_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void VehicleOdometry_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) lgsvl_msgs::msg::VehicleOdometry(_init);
}

void VehicleOdometry_fini_function(void * message_memory)
{
  auto typed_message = static_cast<lgsvl_msgs::msg::VehicleOdometry *>(message_memory);
  typed_message->~VehicleOdometry();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VehicleOdometry_message_member_array[4] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs::msg::VehicleOdometry, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs::msg::VehicleOdometry, velocity),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "front_wheel_angle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs::msg::VehicleOdometry, front_wheel_angle),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rear_wheel_angle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs::msg::VehicleOdometry, rear_wheel_angle),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VehicleOdometry_message_members = {
  "lgsvl_msgs::msg",  // message namespace
  "VehicleOdometry",  // message name
  4,  // number of fields
  sizeof(lgsvl_msgs::msg::VehicleOdometry),
  VehicleOdometry_message_member_array,  // message members
  VehicleOdometry_init_function,  // function to initialize message memory (memory has to be allocated)
  VehicleOdometry_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VehicleOdometry_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VehicleOdometry_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace lgsvl_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<lgsvl_msgs::msg::VehicleOdometry>()
{
  return &::lgsvl_msgs::msg::rosidl_typesupport_introspection_cpp::VehicleOdometry_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lgsvl_msgs, msg, VehicleOdometry)() {
  return &::lgsvl_msgs::msg::rosidl_typesupport_introspection_cpp::VehicleOdometry_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
