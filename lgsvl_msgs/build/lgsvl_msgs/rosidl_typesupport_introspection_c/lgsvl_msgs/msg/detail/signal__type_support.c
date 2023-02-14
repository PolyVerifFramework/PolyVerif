// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lgsvl_msgs:msg/Signal.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lgsvl_msgs/msg/detail/signal__rosidl_typesupport_introspection_c.h"
#include "lgsvl_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lgsvl_msgs/msg/detail/signal__functions.h"
#include "lgsvl_msgs/msg/detail/signal__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `label`
#include "rosidl_runtime_c/string_functions.h"
// Member `bbox`
#include "lgsvl_msgs/msg/bounding_box3_d.h"
// Member `bbox`
#include "lgsvl_msgs/msg/detail/bounding_box3_d__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Signal__rosidl_typesupport_introspection_c__Signal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lgsvl_msgs__msg__Signal__init(message_memory);
}

void Signal__rosidl_typesupport_introspection_c__Signal_fini_function(void * message_memory)
{
  lgsvl_msgs__msg__Signal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Signal__rosidl_typesupport_introspection_c__Signal_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs__msg__Signal, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs__msg__Signal, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs__msg__Signal, label),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "score",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs__msg__Signal, score),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bbox",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs__msg__Signal, bbox),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Signal__rosidl_typesupport_introspection_c__Signal_message_members = {
  "lgsvl_msgs__msg",  // message namespace
  "Signal",  // message name
  5,  // number of fields
  sizeof(lgsvl_msgs__msg__Signal),
  Signal__rosidl_typesupport_introspection_c__Signal_message_member_array,  // message members
  Signal__rosidl_typesupport_introspection_c__Signal_init_function,  // function to initialize message memory (memory has to be allocated)
  Signal__rosidl_typesupport_introspection_c__Signal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Signal__rosidl_typesupport_introspection_c__Signal_message_type_support_handle = {
  0,
  &Signal__rosidl_typesupport_introspection_c__Signal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lgsvl_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lgsvl_msgs, msg, Signal)() {
  Signal__rosidl_typesupport_introspection_c__Signal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  Signal__rosidl_typesupport_introspection_c__Signal_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lgsvl_msgs, msg, BoundingBox3D)();
  if (!Signal__rosidl_typesupport_introspection_c__Signal_message_type_support_handle.typesupport_identifier) {
    Signal__rosidl_typesupport_introspection_c__Signal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Signal__rosidl_typesupport_introspection_c__Signal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
