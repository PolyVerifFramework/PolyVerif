// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lgsvl_msgs:msg/VehicleControlData.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__STRUCT_H_
#define LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'GEAR_NEUTRAL'.
enum
{
  lgsvl_msgs__msg__VehicleControlData__GEAR_NEUTRAL = 0
};

/// Constant 'GEAR_DRIVE'.
enum
{
  lgsvl_msgs__msg__VehicleControlData__GEAR_DRIVE = 1
};

/// Constant 'GEAR_REVERSE'.
enum
{
  lgsvl_msgs__msg__VehicleControlData__GEAR_REVERSE = 2
};

/// Constant 'GEAR_PARKING'.
enum
{
  lgsvl_msgs__msg__VehicleControlData__GEAR_PARKING = 3
};

/// Constant 'GEAR_LOW'.
enum
{
  lgsvl_msgs__msg__VehicleControlData__GEAR_LOW = 4
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

// Struct defined in msg/VehicleControlData in the package lgsvl_msgs.
typedef struct lgsvl_msgs__msg__VehicleControlData
{
  std_msgs__msg__Header header;
  float acceleration_pct;
  float braking_pct;
  float target_wheel_angle;
  float target_wheel_angular_rate;
  uint8_t target_gear;
} lgsvl_msgs__msg__VehicleControlData;

// Struct for a sequence of lgsvl_msgs__msg__VehicleControlData.
typedef struct lgsvl_msgs__msg__VehicleControlData__Sequence
{
  lgsvl_msgs__msg__VehicleControlData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lgsvl_msgs__msg__VehicleControlData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__STRUCT_H_
