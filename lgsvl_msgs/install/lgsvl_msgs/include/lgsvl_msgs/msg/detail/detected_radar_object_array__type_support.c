// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lgsvl_msgs:msg/DetectedRadarObjectArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lgsvl_msgs/msg/detail/detected_radar_object_array__rosidl_typesupport_introspection_c.h"
#include "lgsvl_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lgsvl_msgs/msg/detail/detected_radar_object_array__functions.h"
#include "lgsvl_msgs/msg/detail/detected_radar_object_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `objects`
#include "lgsvl_msgs/msg/detected_radar_object.h"
// Member `objects`
#include "lgsvl_msgs/msg/detail/detected_radar_object__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lgsvl_msgs__msg__DetectedRadarObjectArray__init(message_memory);
}

void DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_fini_function(void * message_memory)
{
  lgsvl_msgs__msg__DetectedRadarObjectArray__fini(message_memory);
}

size_t DetectedRadarObjectArray__rosidl_typesupport_introspection_c__size_function__DetectedRadarObject__objects(
  const void * untyped_member)
{
  const lgsvl_msgs__msg__DetectedRadarObject__Sequence * member =
    (const lgsvl_msgs__msg__DetectedRadarObject__Sequence *)(untyped_member);
  return member->size;
}

const void * DetectedRadarObjectArray__rosidl_typesupport_introspection_c__get_const_function__DetectedRadarObject__objects(
  const void * untyped_member, size_t index)
{
  const lgsvl_msgs__msg__DetectedRadarObject__Sequence * member =
    (const lgsvl_msgs__msg__DetectedRadarObject__Sequence *)(untyped_member);
  return &member->data[index];
}

void * DetectedRadarObjectArray__rosidl_typesupport_introspection_c__get_function__DetectedRadarObject__objects(
  void * untyped_member, size_t index)
{
  lgsvl_msgs__msg__DetectedRadarObject__Sequence * member =
    (lgsvl_msgs__msg__DetectedRadarObject__Sequence *)(untyped_member);
  return &member->data[index];
}

bool DetectedRadarObjectArray__rosidl_typesupport_introspection_c__resize_function__DetectedRadarObject__objects(
  void * untyped_member, size_t size)
{
  lgsvl_msgs__msg__DetectedRadarObject__Sequence * member =
    (lgsvl_msgs__msg__DetectedRadarObject__Sequence *)(untyped_member);
  lgsvl_msgs__msg__DetectedRadarObject__Sequence__fini(member);
  return lgsvl_msgs__msg__DetectedRadarObject__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs__msg__DetectedRadarObjectArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lgsvl_msgs__msg__DetectedRadarObjectArray, objects),  // bytes offset in struct
    NULL,  // default value
    DetectedRadarObjectArray__rosidl_typesupport_introspection_c__size_function__DetectedRadarObject__objects,  // size() function pointer
    DetectedRadarObjectArray__rosidl_typesupport_introspection_c__get_const_function__DetectedRadarObject__objects,  // get_const(index) function pointer
    DetectedRadarObjectArray__rosidl_typesupport_introspection_c__get_function__DetectedRadarObject__objects,  // get(index) function pointer
    DetectedRadarObjectArray__rosidl_typesupport_introspection_c__resize_function__DetectedRadarObject__objects  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_message_members = {
  "lgsvl_msgs__msg",  // message namespace
  "DetectedRadarObjectArray",  // message name
  2,  // number of fields
  sizeof(lgsvl_msgs__msg__DetectedRadarObjectArray),
  DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_message_member_array,  // message members
  DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_init_function,  // function to initialize message memory (memory has to be allocated)
  DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_message_type_support_handle = {
  0,
  &DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lgsvl_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lgsvl_msgs, msg, DetectedRadarObjectArray)() {
  DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lgsvl_msgs, msg, DetectedRadarObject)();
  if (!DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_message_type_support_handle.typesupport_identifier) {
    DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &DetectedRadarObjectArray__rosidl_typesupport_introspection_c__DetectedRadarObjectArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
