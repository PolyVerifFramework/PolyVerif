// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from lgsvl_msgs:msg/CanBusData.idl
// generated code does not contain a copyright notice
#include "lgsvl_msgs/msg/detail/can_bus_data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "lgsvl_msgs/msg/detail/can_bus_data__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Quaternion &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Quaternion &);
size_t get_serialized_size(
  const geometry_msgs::msg::Quaternion &,
  size_t current_alignment);
size_t
max_serialized_size_Quaternion(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Vector3 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Vector3 &);
size_t get_serialized_size(
  const geometry_msgs::msg::Vector3 &,
  size_t current_alignment);
size_t
max_serialized_size_Vector3(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace lgsvl_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lgsvl_msgs
cdr_serialize(
  const lgsvl_msgs::msg::CanBusData & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: speed_mps
  cdr << ros_message.speed_mps;
  // Member: throttle_pct
  cdr << ros_message.throttle_pct;
  // Member: brake_pct
  cdr << ros_message.brake_pct;
  // Member: steer_pct
  cdr << ros_message.steer_pct;
  // Member: parking_brake_active
  cdr << (ros_message.parking_brake_active ? true : false);
  // Member: high_beams_active
  cdr << (ros_message.high_beams_active ? true : false);
  // Member: low_beams_active
  cdr << (ros_message.low_beams_active ? true : false);
  // Member: hazard_lights_active
  cdr << (ros_message.hazard_lights_active ? true : false);
  // Member: fog_lights_active
  cdr << (ros_message.fog_lights_active ? true : false);
  // Member: left_turn_signal_active
  cdr << (ros_message.left_turn_signal_active ? true : false);
  // Member: right_turn_signal_active
  cdr << (ros_message.right_turn_signal_active ? true : false);
  // Member: wipers_active
  cdr << (ros_message.wipers_active ? true : false);
  // Member: reverse_gear_active
  cdr << (ros_message.reverse_gear_active ? true : false);
  // Member: selected_gear
  cdr << ros_message.selected_gear;
  // Member: engine_active
  cdr << (ros_message.engine_active ? true : false);
  // Member: engine_rpm
  cdr << ros_message.engine_rpm;
  // Member: gps_latitude
  cdr << ros_message.gps_latitude;
  // Member: gps_longitude
  cdr << ros_message.gps_longitude;
  // Member: gps_altitude
  cdr << ros_message.gps_altitude;
  // Member: orientation
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.orientation,
    cdr);
  // Member: linear_velocities
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.linear_velocities,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lgsvl_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  lgsvl_msgs::msg::CanBusData & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: speed_mps
  cdr >> ros_message.speed_mps;

  // Member: throttle_pct
  cdr >> ros_message.throttle_pct;

  // Member: brake_pct
  cdr >> ros_message.brake_pct;

  // Member: steer_pct
  cdr >> ros_message.steer_pct;

  // Member: parking_brake_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.parking_brake_active = tmp ? true : false;
  }

  // Member: high_beams_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.high_beams_active = tmp ? true : false;
  }

  // Member: low_beams_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.low_beams_active = tmp ? true : false;
  }

  // Member: hazard_lights_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hazard_lights_active = tmp ? true : false;
  }

  // Member: fog_lights_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.fog_lights_active = tmp ? true : false;
  }

  // Member: left_turn_signal_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.left_turn_signal_active = tmp ? true : false;
  }

  // Member: right_turn_signal_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.right_turn_signal_active = tmp ? true : false;
  }

  // Member: wipers_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.wipers_active = tmp ? true : false;
  }

  // Member: reverse_gear_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.reverse_gear_active = tmp ? true : false;
  }

  // Member: selected_gear
  cdr >> ros_message.selected_gear;

  // Member: engine_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.engine_active = tmp ? true : false;
  }

  // Member: engine_rpm
  cdr >> ros_message.engine_rpm;

  // Member: gps_latitude
  cdr >> ros_message.gps_latitude;

  // Member: gps_longitude
  cdr >> ros_message.gps_longitude;

  // Member: gps_altitude
  cdr >> ros_message.gps_altitude;

  // Member: orientation
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.orientation);

  // Member: linear_velocities
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.linear_velocities);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lgsvl_msgs
get_serialized_size(
  const lgsvl_msgs::msg::CanBusData & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: speed_mps
  {
    size_t item_size = sizeof(ros_message.speed_mps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: throttle_pct
  {
    size_t item_size = sizeof(ros_message.throttle_pct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: brake_pct
  {
    size_t item_size = sizeof(ros_message.brake_pct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: steer_pct
  {
    size_t item_size = sizeof(ros_message.steer_pct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: parking_brake_active
  {
    size_t item_size = sizeof(ros_message.parking_brake_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: high_beams_active
  {
    size_t item_size = sizeof(ros_message.high_beams_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: low_beams_active
  {
    size_t item_size = sizeof(ros_message.low_beams_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hazard_lights_active
  {
    size_t item_size = sizeof(ros_message.hazard_lights_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fog_lights_active
  {
    size_t item_size = sizeof(ros_message.fog_lights_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: left_turn_signal_active
  {
    size_t item_size = sizeof(ros_message.left_turn_signal_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_turn_signal_active
  {
    size_t item_size = sizeof(ros_message.right_turn_signal_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: wipers_active
  {
    size_t item_size = sizeof(ros_message.wipers_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: reverse_gear_active
  {
    size_t item_size = sizeof(ros_message.reverse_gear_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: selected_gear
  {
    size_t item_size = sizeof(ros_message.selected_gear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: engine_active
  {
    size_t item_size = sizeof(ros_message.engine_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: engine_rpm
  {
    size_t item_size = sizeof(ros_message.engine_rpm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gps_latitude
  {
    size_t item_size = sizeof(ros_message.gps_latitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gps_longitude
  {
    size_t item_size = sizeof(ros_message.gps_longitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gps_altitude
  {
    size_t item_size = sizeof(ros_message.gps_altitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: orientation

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.orientation, current_alignment);
  // Member: linear_velocities

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.linear_velocities, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lgsvl_msgs
max_serialized_size_CanBusData(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: speed_mps
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: throttle_pct
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: brake_pct
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: steer_pct
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: parking_brake_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: high_beams_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: low_beams_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hazard_lights_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: fog_lights_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: left_turn_signal_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: right_turn_signal_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: wipers_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: reverse_gear_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: selected_gear
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: engine_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: engine_rpm
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gps_latitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gps_longitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: gps_altitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: orientation
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Quaternion(
        full_bounded, current_alignment);
    }
  }

  // Member: linear_velocities
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Vector3(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _CanBusData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const lgsvl_msgs::msg::CanBusData *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CanBusData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<lgsvl_msgs::msg::CanBusData *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CanBusData__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const lgsvl_msgs::msg::CanBusData *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CanBusData__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_CanBusData(full_bounded, 0);
}

static message_type_support_callbacks_t _CanBusData__callbacks = {
  "lgsvl_msgs::msg",
  "CanBusData",
  _CanBusData__cdr_serialize,
  _CanBusData__cdr_deserialize,
  _CanBusData__get_serialized_size,
  _CanBusData__max_serialized_size
};

static rosidl_message_type_support_t _CanBusData__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CanBusData__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace lgsvl_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_lgsvl_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<lgsvl_msgs::msg::CanBusData>()
{
  return &lgsvl_msgs::msg::typesupport_fastrtps_cpp::_CanBusData__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lgsvl_msgs, msg, CanBusData)() {
  return &lgsvl_msgs::msg::typesupport_fastrtps_cpp::_CanBusData__handle;
}

#ifdef __cplusplus
}
#endif
