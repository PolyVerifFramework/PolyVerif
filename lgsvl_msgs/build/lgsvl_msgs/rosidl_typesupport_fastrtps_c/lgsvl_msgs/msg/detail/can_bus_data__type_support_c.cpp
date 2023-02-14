// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from lgsvl_msgs:msg/CanBusData.idl
// generated code does not contain a copyright notice
#include "lgsvl_msgs/msg/detail/can_bus_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "lgsvl_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "lgsvl_msgs/msg/detail/can_bus_data__struct.h"
#include "lgsvl_msgs/msg/detail/can_bus_data__functions.h"
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

#include "geometry_msgs/msg/detail/quaternion__functions.h"  // orientation
#include "geometry_msgs/msg/detail/vector3__functions.h"  // linear_velocities
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lgsvl_msgs
size_t get_serialized_size_geometry_msgs__msg__Quaternion(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lgsvl_msgs
size_t max_serialized_size_geometry_msgs__msg__Quaternion(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lgsvl_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Quaternion)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lgsvl_msgs
size_t get_serialized_size_geometry_msgs__msg__Vector3(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lgsvl_msgs
size_t max_serialized_size_geometry_msgs__msg__Vector3(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_lgsvl_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3)();
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


using _CanBusData__ros_msg_type = lgsvl_msgs__msg__CanBusData;

static bool _CanBusData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CanBusData__ros_msg_type * ros_message = static_cast<const _CanBusData__ros_msg_type *>(untyped_ros_message);
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

  // Field name: speed_mps
  {
    cdr << ros_message->speed_mps;
  }

  // Field name: throttle_pct
  {
    cdr << ros_message->throttle_pct;
  }

  // Field name: brake_pct
  {
    cdr << ros_message->brake_pct;
  }

  // Field name: steer_pct
  {
    cdr << ros_message->steer_pct;
  }

  // Field name: parking_brake_active
  {
    cdr << (ros_message->parking_brake_active ? true : false);
  }

  // Field name: high_beams_active
  {
    cdr << (ros_message->high_beams_active ? true : false);
  }

  // Field name: low_beams_active
  {
    cdr << (ros_message->low_beams_active ? true : false);
  }

  // Field name: hazard_lights_active
  {
    cdr << (ros_message->hazard_lights_active ? true : false);
  }

  // Field name: fog_lights_active
  {
    cdr << (ros_message->fog_lights_active ? true : false);
  }

  // Field name: left_turn_signal_active
  {
    cdr << (ros_message->left_turn_signal_active ? true : false);
  }

  // Field name: right_turn_signal_active
  {
    cdr << (ros_message->right_turn_signal_active ? true : false);
  }

  // Field name: wipers_active
  {
    cdr << (ros_message->wipers_active ? true : false);
  }

  // Field name: reverse_gear_active
  {
    cdr << (ros_message->reverse_gear_active ? true : false);
  }

  // Field name: selected_gear
  {
    cdr << ros_message->selected_gear;
  }

  // Field name: engine_active
  {
    cdr << (ros_message->engine_active ? true : false);
  }

  // Field name: engine_rpm
  {
    cdr << ros_message->engine_rpm;
  }

  // Field name: gps_latitude
  {
    cdr << ros_message->gps_latitude;
  }

  // Field name: gps_longitude
  {
    cdr << ros_message->gps_longitude;
  }

  // Field name: gps_altitude
  {
    cdr << ros_message->gps_altitude;
  }

  // Field name: orientation
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Quaternion
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->orientation, cdr))
    {
      return false;
    }
  }

  // Field name: linear_velocities
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->linear_velocities, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _CanBusData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CanBusData__ros_msg_type * ros_message = static_cast<_CanBusData__ros_msg_type *>(untyped_ros_message);
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

  // Field name: speed_mps
  {
    cdr >> ros_message->speed_mps;
  }

  // Field name: throttle_pct
  {
    cdr >> ros_message->throttle_pct;
  }

  // Field name: brake_pct
  {
    cdr >> ros_message->brake_pct;
  }

  // Field name: steer_pct
  {
    cdr >> ros_message->steer_pct;
  }

  // Field name: parking_brake_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->parking_brake_active = tmp ? true : false;
  }

  // Field name: high_beams_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->high_beams_active = tmp ? true : false;
  }

  // Field name: low_beams_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->low_beams_active = tmp ? true : false;
  }

  // Field name: hazard_lights_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->hazard_lights_active = tmp ? true : false;
  }

  // Field name: fog_lights_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->fog_lights_active = tmp ? true : false;
  }

  // Field name: left_turn_signal_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->left_turn_signal_active = tmp ? true : false;
  }

  // Field name: right_turn_signal_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->right_turn_signal_active = tmp ? true : false;
  }

  // Field name: wipers_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->wipers_active = tmp ? true : false;
  }

  // Field name: reverse_gear_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->reverse_gear_active = tmp ? true : false;
  }

  // Field name: selected_gear
  {
    cdr >> ros_message->selected_gear;
  }

  // Field name: engine_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->engine_active = tmp ? true : false;
  }

  // Field name: engine_rpm
  {
    cdr >> ros_message->engine_rpm;
  }

  // Field name: gps_latitude
  {
    cdr >> ros_message->gps_latitude;
  }

  // Field name: gps_longitude
  {
    cdr >> ros_message->gps_longitude;
  }

  // Field name: gps_altitude
  {
    cdr >> ros_message->gps_altitude;
  }

  // Field name: orientation
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Quaternion
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->orientation))
    {
      return false;
    }
  }

  // Field name: linear_velocities
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->linear_velocities))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lgsvl_msgs
size_t get_serialized_size_lgsvl_msgs__msg__CanBusData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CanBusData__ros_msg_type * ros_message = static_cast<const _CanBusData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name speed_mps
  {
    size_t item_size = sizeof(ros_message->speed_mps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name throttle_pct
  {
    size_t item_size = sizeof(ros_message->throttle_pct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name brake_pct
  {
    size_t item_size = sizeof(ros_message->brake_pct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name steer_pct
  {
    size_t item_size = sizeof(ros_message->steer_pct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name parking_brake_active
  {
    size_t item_size = sizeof(ros_message->parking_brake_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name high_beams_active
  {
    size_t item_size = sizeof(ros_message->high_beams_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name low_beams_active
  {
    size_t item_size = sizeof(ros_message->low_beams_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hazard_lights_active
  {
    size_t item_size = sizeof(ros_message->hazard_lights_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fog_lights_active
  {
    size_t item_size = sizeof(ros_message->fog_lights_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_turn_signal_active
  {
    size_t item_size = sizeof(ros_message->left_turn_signal_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_turn_signal_active
  {
    size_t item_size = sizeof(ros_message->right_turn_signal_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name wipers_active
  {
    size_t item_size = sizeof(ros_message->wipers_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reverse_gear_active
  {
    size_t item_size = sizeof(ros_message->reverse_gear_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name selected_gear
  {
    size_t item_size = sizeof(ros_message->selected_gear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name engine_active
  {
    size_t item_size = sizeof(ros_message->engine_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name engine_rpm
  {
    size_t item_size = sizeof(ros_message->engine_rpm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gps_latitude
  {
    size_t item_size = sizeof(ros_message->gps_latitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gps_longitude
  {
    size_t item_size = sizeof(ros_message->gps_longitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gps_altitude
  {
    size_t item_size = sizeof(ros_message->gps_altitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name orientation

  current_alignment += get_serialized_size_geometry_msgs__msg__Quaternion(
    &(ros_message->orientation), current_alignment);
  // field.name linear_velocities

  current_alignment += get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->linear_velocities), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _CanBusData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_lgsvl_msgs__msg__CanBusData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lgsvl_msgs
size_t max_serialized_size_lgsvl_msgs__msg__CanBusData(
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
  // member: speed_mps
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: throttle_pct
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: brake_pct
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: steer_pct
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: parking_brake_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: high_beams_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: low_beams_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: hazard_lights_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: fog_lights_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: left_turn_signal_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: right_turn_signal_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: wipers_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reverse_gear_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: selected_gear
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: engine_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: engine_rpm
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gps_latitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gps_longitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: gps_altitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: orientation
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Quaternion(
        full_bounded, current_alignment);
    }
  }
  // member: linear_velocities
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Vector3(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _CanBusData__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_lgsvl_msgs__msg__CanBusData(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_CanBusData = {
  "lgsvl_msgs::msg",
  "CanBusData",
  _CanBusData__cdr_serialize,
  _CanBusData__cdr_deserialize,
  _CanBusData__get_serialized_size,
  _CanBusData__max_serialized_size
};

static rosidl_message_type_support_t _CanBusData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CanBusData,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lgsvl_msgs, msg, CanBusData)() {
  return &_CanBusData__type_support;
}

#if defined(__cplusplus)
}
#endif
