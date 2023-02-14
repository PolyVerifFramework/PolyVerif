// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from lgsvl_msgs:msg/VehicleControlData.idl
// generated code does not contain a copyright notice
#include "lgsvl_msgs/msg/detail/vehicle_control_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "lgsvl_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "lgsvl_msgs/msg/detail/vehicle_control_data__struct.h"
#include "lgsvl_msgs/msg/detail/vehicle_control_data__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lgsvl_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lgsvl_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lgsvl_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _VehicleControlData__ros_msg_type = lgsvl_msgs__msg__VehicleControlData;

static bool _VehicleControlData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VehicleControlData__ros_msg_type * ros_message = static_cast<const _VehicleControlData__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: acceleration_pct
  {
    cdr << ros_message->acceleration_pct;
  }

  // Field name: braking_pct
  {
    cdr << ros_message->braking_pct;
  }

  // Field name: target_wheel_angle
  {
    cdr << ros_message->target_wheel_angle;
  }

  // Field name: target_wheel_angular_rate
  {
    cdr << ros_message->target_wheel_angular_rate;
  }

  // Field name: target_gear
  {
    cdr << ros_message->target_gear;
  }

  return true;
}

static bool _VehicleControlData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VehicleControlData__ros_msg_type * ros_message = static_cast<_VehicleControlData__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: acceleration_pct
  {
    cdr >> ros_message->acceleration_pct;
  }

  // Field name: braking_pct
  {
    cdr >> ros_message->braking_pct;
  }

  // Field name: target_wheel_angle
  {
    cdr >> ros_message->target_wheel_angle;
  }

  // Field name: target_wheel_angular_rate
  {
    cdr >> ros_message->target_wheel_angular_rate;
  }

  // Field name: target_gear
  {
    cdr >> ros_message->target_gear;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lgsvl_msgs
size_t get_serialized_size_lgsvl_msgs__msg__VehicleControlData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehicleControlData__ros_msg_type * ros_message = static_cast<const _VehicleControlData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name acceleration_pct
  {
    size_t item_size = sizeof(ros_message->acceleration_pct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name braking_pct
  {
    size_t item_size = sizeof(ros_message->braking_pct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_wheel_angle
  {
    size_t item_size = sizeof(ros_message->target_wheel_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_wheel_angular_rate
  {
    size_t item_size = sizeof(ros_message->target_wheel_angular_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_gear
  {
    size_t item_size = sizeof(ros_message->target_gear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _VehicleControlData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_lgsvl_msgs__msg__VehicleControlData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lgsvl_msgs
size_t max_serialized_size_lgsvl_msgs__msg__VehicleControlData(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: acceleration_pct
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: braking_pct
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: target_wheel_angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: target_wheel_angular_rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: target_gear
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _VehicleControlData__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_lgsvl_msgs__msg__VehicleControlData(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_VehicleControlData = {
  "lgsvl_msgs::msg",
  "VehicleControlData",
  _VehicleControlData__cdr_serialize,
  _VehicleControlData__cdr_deserialize,
  _VehicleControlData__get_serialized_size,
  _VehicleControlData__max_serialized_size
};

static rosidl_message_type_support_t _VehicleControlData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehicleControlData,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lgsvl_msgs, msg, VehicleControlData)() {
  return &_VehicleControlData__type_support;
}

#if defined(__cplusplus)
}
#endif
