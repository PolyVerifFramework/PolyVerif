// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from lgsvl_msgs:msg/DetectedRadarObjectArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "lgsvl_msgs/msg/detail/detected_radar_object_array__struct.hpp"
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

void DetectedRadarObjectArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) lgsvl_msgs::msg::DetectedRadarObjectArray(_init);
}

void DetectedRadarObjectArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<lgsvl_msgs::msg::DetectedRadarObjectArray *>(message_memory);
  typed_message->~DetectedRadarObjectArray();
}

size_t size_function__DetectedRadarObjectArray__objects(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lgsvl_msgs::msg::DetectedRadarObject> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DetectedRadarObjectArray__objects(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lgsvl_msgs::msg::DetectedRadarObject> *>(untyped_member);
  return &member[index];
}

void * get_function__DetectedRadarObjectArray__objects(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lgsvl_msgs::msg::DetectedRadarObject> *>(untyped_member);
  return &member[index];
}

void resize_function__DetectedRadarObjectArray__objects(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lgsvl_msgs::msg::DetectedRadarObject> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DetectedRadarObjectArray_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs::msg::DetectedRadarObjectArray, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "objects",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lgsvl_msgs::msg::DetectedRadarObject>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs::msg::DetectedRadarObjectArray, objects),  // bytes offset in struct
    nullptr,  // default value
    size_function__DetectedRadarObjectArray__objects,  // size() function pointer
    get_const_function__DetectedRadarObjectArray__objects,  // get_const(index) function pointer
    get_function__DetectedRadarObjectArray__objects,  // get(index) function pointer
    resize_function__DetectedRadarObjectArray__objects  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DetectedRadarObjectArray_message_members = {
  "lgsvl_msgs::msg",  // message namespace
  "DetectedRadarObjectArray",  // message name
  2,  // number of fields
  sizeof(lgsvl_msgs::msg::DetectedRadarObjectArray),
  DetectedRadarObjectArray_message_member_array,  // message members
  DetectedRadarObjectArray_init_function,  // function to initialize message memory (memory has to be allocated)
  DetectedRadarObjectArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DetectedRadarObjectArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DetectedRadarObjectArray_message_members,
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
get_message_type_support_handle<lgsvl_msgs::msg::DetectedRadarObjectArray>()
{
  return &::lgsvl_msgs::msg::rosidl_typesupport_introspection_cpp::DetectedRadarObjectArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lgsvl_msgs, msg, DetectedRadarObjectArray)() {
  return &::lgsvl_msgs::msg::rosidl_typesupport_introspection_cpp::DetectedRadarObjectArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
