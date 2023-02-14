// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from lgsvl_msgs:msg/VehicleStateData.idl
// generated code does not contain a copyright notice
#include "lgsvl_msgs/msg/detail/vehicle_state_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "lgsvl_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "lgsvl_msgs/msg/detail/vehicle_state_data__struct.h"
#include "lgsvl_msgs/msg/detail/vehicle_state_data__functions.h"
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


using _VehicleStateData__ros_msg_type = lgsvl_msgs__msg__VehicleStateData;

static bool _VehicleStateData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VehicleStateData__ros_msg_type * ros_message = static_cast<const _VehicleStateData__ros_msg_type *>(untyped_ros_message);
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

  // Field name: blinker_state
  {
    cdr << ros_message->blinker_state;
  }

  // Field name: headlight_state
  {
    cdr << ros_message->headlight_state;
  }

  // Field name: wiper_state
  {
    cdr << ros_message->wiper_state;
  }

  // Field name: current_gear
  {
    cdr << ros_message->current_gear;
  }

  // Field name: vehicle_mode
  {
    cdr << ros_message->vehicle_mode;
  }

  // Field name: hand_brake_active
  {
    cdr << (ros_message->hand_brake_active ? true : false);
  }

  // Field name: horn_active
  {
    cdr << (ros_message->horn_active ? true : false);
  }

  // Field name: autonomous_mode_active
  {
    cdr << (ros_message->autonomous_mode_active ? true : false);
  }

  return true;
}

static bool _VehicleStateData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VehicleStateData__ros_msg_type * ros_message = static_cast<_VehicleStateData__ros_msg_type *>(untyped_ros_message);
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

  // Field name: blinker_state
  {
    cdr >> ros_message->blinker_state;
  }

  // Field name: headlight_state
  {
    cdr >> ros_message->headlight_state;
  }

  // Field name: wiper_state
  {
    cdr >> ros_message->wiper_state;
  }

  // Field name: current_gear
  {
    cdr >> ros_message->current_gear;
  }

  // Field name: vehicle_mode
  {
    cdr >> ros_message->vehicle_mode;
  }

  // Field name: hand_brake_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hand_brake_active = tmp ? true : false;
  }

  // Field name: horn_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->horn_active = tmp ? true : false;
  }

  // Field name: autonomous_mode_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->autonomous_mode_active = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lgsvl_msgs
size_t get_serialized_size_lgsvl_msgs__msg__VehicleStateData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehicleStateData__ros_msg_type * ros_message = static_cast<const _VehicleStateData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name blinker_state
  {
    size_t item_size = sizeof(ros_message->blinker_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name headlight_state
  {
    size_t item_size = sizeof(ros_message->headlight_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name wiper_state
  {
    size_t item_size = sizeof(ros_message->wiper_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_gear
  {
    size_t item_size = sizeof(ros_message->current_gear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vehicle_mode
  {
    size_t item_size = sizeof(ros_message->vehicle_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hand_brake_active
  {
    size_t item_size = sizeof(ros_message->hand_brake_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name horn_active
  {
    size_t item_size = sizeof(ros_message->horn_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name autonomous_mode_active
  {
    size_t item_size = sizeof(ros_message->autonomous_mode_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _VehicleStateData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_lgsvl_msgs__msg__VehicleStateData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lgsvl_msgs
size_t max_serialized_size_lgsvl_msgs__msg__VehicleStateData(
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
  // member: blinker_state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: headlight_state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: wiper_state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: current_gear
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: vehicle_mode
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hand_brake_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: horn_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: autonomous_mode_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _VehicleStateData__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_lgsvl_msgs__msg__VehicleStateData(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_VehicleStateData = {
  "lgsvl_msgs::msg",
  "VehicleStateData",
  _VehicleStateData__cdr_serialize,
  _VehicleStateData__cdr_deserialize,
  _VehicleStateData__get_serialized_size,
  _VehicleStateData__max_serialized_size
};

static rosidl_message_type_support_t _VehicleStateData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehicleStateData,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lgsvl_msgs, msg, VehicleStateData)() {
  return &_VehicleStateData__type_support;
}

#if defined(__cplusplus)
}
#endif
