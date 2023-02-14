// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from lgsvl_msgs:msg/VehicleControlData.idl
// generated code does not contain a copyright notice
#include "lgsvl_msgs/msg/detail/vehicle_control_data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "lgsvl_msgs/msg/detail/vehicle_control_data__struct.hpp"

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


namespace lgsvl_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lgsvl_msgs
cdr_serialize(
  const lgsvl_msgs::msg::VehicleControlData & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: acceleration_pct
  cdr << ros_message.acceleration_pct;
  // Member: braking_pct
  cdr << ros_message.braking_pct;
  // Member: target_wheel_angle
  cdr << ros_message.target_wheel_angle;
  // Member: target_wheel_angular_rate
  cdr << ros_message.target_wheel_angular_rate;
  // Member: target_gear
  cdr << ros_message.target_gear;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lgsvl_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  lgsvl_msgs::msg::VehicleControlData & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: acceleration_pct
  cdr >> ros_message.acceleration_pct;

  // Member: braking_pct
  cdr >> ros_message.braking_pct;

  // Member: target_wheel_angle
  cdr >> ros_message.target_wheel_angle;

  // Member: target_wheel_angular_rate
  cdr >> ros_message.target_wheel_angular_rate;

  // Member: target_gear
  cdr >> ros_message.target_gear;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lgsvl_msgs
get_serialized_size(
  const lgsvl_msgs::msg::VehicleControlData & ros_message,
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
  // Member: acceleration_pct
  {
    size_t item_size = sizeof(ros_message.acceleration_pct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: braking_pct
  {
    size_t item_size = sizeof(ros_message.braking_pct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: target_wheel_angle
  {
    size_t item_size = sizeof(ros_message.target_wheel_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: target_wheel_angular_rate
  {
    size_t item_size = sizeof(ros_message.target_wheel_angular_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: target_gear
  {
    size_t item_size = sizeof(ros_message.target_gear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lgsvl_msgs
max_serialized_size_VehicleControlData(
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

  // Member: acceleration_pct
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: braking_pct
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: target_wheel_angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: target_wheel_angular_rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: target_gear
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _VehicleControlData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const lgsvl_msgs::msg::VehicleControlData *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _VehicleControlData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<lgsvl_msgs::msg::VehicleControlData *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _VehicleControlData__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const lgsvl_msgs::msg::VehicleControlData *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _VehicleControlData__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_VehicleControlData(full_bounded, 0);
}

static message_type_support_callbacks_t _VehicleControlData__callbacks = {
  "lgsvl_msgs::msg",
  "VehicleControlData",
  _VehicleControlData__cdr_serialize,
  _VehicleControlData__cdr_deserialize,
  _VehicleControlData__get_serialized_size,
  _VehicleControlData__max_serialized_size
};

static rosidl_message_type_support_t _VehicleControlData__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_VehicleControlData__callbacks,
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
get_message_type_support_handle<lgsvl_msgs::msg::VehicleControlData>()
{
  return &lgsvl_msgs::msg::typesupport_fastrtps_cpp::_VehicleControlData__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lgsvl_msgs, msg, VehicleControlData)() {
  return &lgsvl_msgs::msg::typesupport_fastrtps_cpp::_VehicleControlData__handle;
}

#ifdef __cplusplus
}
#endif
