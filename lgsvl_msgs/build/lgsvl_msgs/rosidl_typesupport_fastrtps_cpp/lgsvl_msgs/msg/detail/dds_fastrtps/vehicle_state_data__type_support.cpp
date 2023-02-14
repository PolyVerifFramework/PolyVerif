// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from lgsvl_msgs:msg/VehicleStateData.idl
// generated code does not contain a copyright notice
#include "lgsvl_msgs/msg/detail/vehicle_state_data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "lgsvl_msgs/msg/detail/vehicle_state_data__struct.hpp"

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
  const lgsvl_msgs::msg::VehicleStateData & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: blinker_state
  cdr << ros_message.blinker_state;
  // Member: headlight_state
  cdr << ros_message.headlight_state;
  // Member: wiper_state
  cdr << ros_message.wiper_state;
  // Member: current_gear
  cdr << ros_message.current_gear;
  // Member: vehicle_mode
  cdr << ros_message.vehicle_mode;
  // Member: hand_brake_active
  cdr << (ros_message.hand_brake_active ? true : false);
  // Member: horn_active
  cdr << (ros_message.horn_active ? true : false);
  // Member: autonomous_mode_active
  cdr << (ros_message.autonomous_mode_active ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lgsvl_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  lgsvl_msgs::msg::VehicleStateData & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: blinker_state
  cdr >> ros_message.blinker_state;

  // Member: headlight_state
  cdr >> ros_message.headlight_state;

  // Member: wiper_state
  cdr >> ros_message.wiper_state;

  // Member: current_gear
  cdr >> ros_message.current_gear;

  // Member: vehicle_mode
  cdr >> ros_message.vehicle_mode;

  // Member: hand_brake_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.hand_brake_active = tmp ? true : false;
  }

  // Member: horn_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.horn_active = tmp ? true : false;
  }

  // Member: autonomous_mode_active
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.autonomous_mode_active = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lgsvl_msgs
get_serialized_size(
  const lgsvl_msgs::msg::VehicleStateData & ros_message,
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
  // Member: blinker_state
  {
    size_t item_size = sizeof(ros_message.blinker_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: headlight_state
  {
    size_t item_size = sizeof(ros_message.headlight_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: wiper_state
  {
    size_t item_size = sizeof(ros_message.wiper_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_gear
  {
    size_t item_size = sizeof(ros_message.current_gear);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vehicle_mode
  {
    size_t item_size = sizeof(ros_message.vehicle_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hand_brake_active
  {
    size_t item_size = sizeof(ros_message.hand_brake_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: horn_active
  {
    size_t item_size = sizeof(ros_message.horn_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: autonomous_mode_active
  {
    size_t item_size = sizeof(ros_message.autonomous_mode_active);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lgsvl_msgs
max_serialized_size_VehicleStateData(
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

  // Member: blinker_state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: headlight_state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: wiper_state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: current_gear
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: vehicle_mode
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: hand_brake_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: horn_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: autonomous_mode_active
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _VehicleStateData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const lgsvl_msgs::msg::VehicleStateData *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _VehicleStateData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<lgsvl_msgs::msg::VehicleStateData *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _VehicleStateData__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const lgsvl_msgs::msg::VehicleStateData *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _VehicleStateData__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_VehicleStateData(full_bounded, 0);
}

static message_type_support_callbacks_t _VehicleStateData__callbacks = {
  "lgsvl_msgs::msg",
  "VehicleStateData",
  _VehicleStateData__cdr_serialize,
  _VehicleStateData__cdr_deserialize,
  _VehicleStateData__get_serialized_size,
  _VehicleStateData__max_serialized_size
};

static rosidl_message_type_support_t _VehicleStateData__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_VehicleStateData__callbacks,
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
get_message_type_support_handle<lgsvl_msgs::msg::VehicleStateData>()
{
  return &lgsvl_msgs::msg::typesupport_fastrtps_cpp::_VehicleStateData__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lgsvl_msgs, msg, VehicleStateData)() {
  return &lgsvl_msgs::msg::typesupport_fastrtps_cpp::_VehicleStateData__handle;
}

#ifdef __cplusplus
}
#endif
