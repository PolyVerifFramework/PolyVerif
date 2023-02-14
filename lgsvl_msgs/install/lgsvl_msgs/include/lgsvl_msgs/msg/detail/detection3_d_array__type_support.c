// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lgsvl_msgs:msg/Detection3DArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lgsvl_msgs/msg/detail/detection3_d_array__rosidl_typesupport_introspection_c.h"
#include "lgsvl_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lgsvl_msgs/msg/detail/detection3_d_array__functions.h"
#include "lgsvl_msgs/msg/detail/detection3_d_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `detections`
#include "lgsvl_msgs/msg/detection3_d.h"
// Member `detections`
#include "lgsvl_msgs/msg/detail/detection3_d__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lgsvl_msgs__msg__Detection3DArray__init(message_memory);
}

void Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_fini_function(void * message_memory)
{
  lgsvl_msgs__msg__Detection3DArray__fini(message_memory);
}

size_t Detection3DArray__rosidl_typesupport_introspection_c__size_function__Detection3D__detections(
  const void * untyped_member)
{
  const lgsvl_msgs__msg__Detection3D__Sequence * member =
    (const lgsvl_msgs__msg__Detection3D__Sequence *)(untyped_member);
  return member->size;
}

const void * Detection3DArray__rosidl_typesupport_introspection_c__get_const_function__Detection3D__detections(
  const void * untyped_member, size_t index)
{
  const lgsvl_msgs__msg__Detection3D__Sequence * member =
    (const lgsvl_msgs__msg__Detection3D__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Detection3DArray__rosidl_typesupport_introspection_c__get_function__Detection3D__detections(
  void * untyped_member, size_t index)
{
  lgsvl_msgs__msg__Detection3D__Sequence * member =
    (lgsvl_msgs__msg__Detection3D__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Detection3DArray__rosidl_typesupport_introspection_c__resize_function__Detection3D__detections(
  void * untyped_member, size_t size)
{
  lgsvl_msgs__msg__Detection3D__Sequence * member =
    (lgsvl_msgs__msg__Detection3D__Sequence *)(untyped_member);
  lgsvl_msgs__msg__Detection3D__Sequence__fini(member);
  return lgsvl_msgs__msg__Detection3D__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs__msg__Detection3DArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs__msg__Detection3DArray, detections),  // bytes offset in struct
    NULL,  // default value
    Detection3DArray__rosidl_typesupport_introspection_c__size_function__Detection3D__detections,  // size() function pointer
    Detection3DArray__rosidl_typesupport_introspection_c__get_const_function__Detection3D__detections,  // get_const(index) function pointer
    Detection3DArray__rosidl_typesupport_introspection_c__get_function__Detection3D__detections,  // get(index) function pointer
    Detection3DArray__rosidl_typesupport_introspection_c__resize_function__Detection3D__detections  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_message_members = {
  "lgsvl_msgs__msg",  // message namespace
  "Detection3DArray",  // message name
  2,  // number of fields
  sizeof(lgsvl_msgs__msg__Detection3DArray),
  Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_message_member_array,  // message members
  Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_init_function,  // function to initialize message memory (memory has to be allocated)
  Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_message_type_support_handle = {
  0,
  &Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lgsvl_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lgsvl_msgs, msg, Detection3DArray)() {
  Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lgsvl_msgs, msg, Detection3D)();
  if (!Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_message_type_support_handle.typesupport_identifier) {
    Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Detection3DArray__rosidl_typesupport_introspection_c__Detection3DArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
