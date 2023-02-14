// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lgsvl_msgs:msg/CanBusData.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__CAN_BUS_DATA__STRUCT_H_
#define LGSVL_MSGS__MSG__DETAIL__CAN_BUS_DATA__STRUCT_H_

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
  lgsvl_msgs__msg__CanBusData__GEAR_NEUTRAL = 0
};

/// Constant 'GEAR_DRIVE'.
enum
{
  lgsvl_msgs__msg__CanBusData__GEAR_DRIVE = 1
};

/// Constant 'GEAR_REVERSE'.
enum
{
  lgsvl_msgs__msg__CanBusData__GEAR_REVERSE = 2
};

/// Constant 'GEAR_PARKING'.
enum
{
  lgsvl_msgs__msg__CanBusData__GEAR_PARKING = 3
};

/// Constant 'GEAR_LOW'.
enum
{
  lgsvl_msgs__msg__CanBusData__GEAR_LOW = 4
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__struct.h"
// Member 'linear_velocities'
#include "geometry_msgs/msg/detail/vector3__struct.h"

// Struct defined in msg/CanBusData in the package lgsvl_msgs.
typedef struct lgsvl_msgs__msg__CanBusData
{
  std_msgs__msg__Header header;
  float speed_mps;
  float throttle_pct;
  float brake_pct;
  float steer_pct;
  bool parking_brake_active;
  bool high_beams_active;
  bool low_beams_active;
  bool hazard_lights_active;
  bool fog_lights_active;
  bool left_turn_signal_active;
  bool right_turn_signal_active;
  bool wipers_active;
  bool reverse_gear_active;
  int8_t selected_gear;
  bool engine_active;
  float engine_rpm;
  double gps_latitude;
  double gps_longitude;
  double gps_altitude;
  geometry_msgs__msg__Quaternion orientation;
  geometry_msgs__msg__Vector3 linear_velocities;
} lgsvl_msgs__msg__CanBusData;

// Struct for a sequence of lgsvl_msgs__msg__CanBusData.
typedef struct lgsvl_msgs__msg__CanBusData__Sequence
{
  lgsvl_msgs__msg__CanBusData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lgsvl_msgs__msg__CanBusData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LGSVL_MSGS__MSG__DETAIL__CAN_BUS_DATA__STRUCT_H_
