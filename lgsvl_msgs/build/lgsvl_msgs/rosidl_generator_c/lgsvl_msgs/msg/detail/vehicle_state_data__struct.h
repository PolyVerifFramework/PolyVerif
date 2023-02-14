// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lgsvl_msgs:msg/VehicleStateData.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__VEHICLE_STATE_DATA__STRUCT_H_
#define LGSVL_MSGS__MSG__DETAIL__VEHICLE_STATE_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'BLINKERS_OFF'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__BLINKERS_OFF = 0
};

/// Constant 'BLINKERS_LEFT'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__BLINKERS_LEFT = 1
};

/// Constant 'BLINKERS_RIGHT'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__BLINKERS_RIGHT = 2
};

/// Constant 'BLINKERS_HAZARD'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__BLINKERS_HAZARD = 3
};

/// Constant 'HEADLIGHTS_OFF'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__HEADLIGHTS_OFF = 0
};

/// Constant 'HEADLIGHTS_LOW'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__HEADLIGHTS_LOW = 1
};

/// Constant 'HEADLIGHTS_HIGH'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__HEADLIGHTS_HIGH = 2
};

/// Constant 'WIPERS_OFF'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__WIPERS_OFF = 0
};

/// Constant 'WIPERS_LOW'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__WIPERS_LOW = 1
};

/// Constant 'WIPERS_MED'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__WIPERS_MED = 2
};

/// Constant 'WIPERS_HIGH'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__WIPERS_HIGH = 3
};

/// Constant 'GEAR_NEUTRAL'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__GEAR_NEUTRAL = 0
};

/// Constant 'GEAR_DRIVE'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__GEAR_DRIVE = 1
};

/// Constant 'GEAR_REVERSE'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__GEAR_REVERSE = 2
};

/// Constant 'GEAR_PARKING'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__GEAR_PARKING = 3
};

/// Constant 'GEAR_LOW'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__GEAR_LOW = 4
};

/// Constant 'VEHICLE_MODE_COMPLETE_MANUAL'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__VEHICLE_MODE_COMPLETE_MANUAL = 0
};

/// Constant 'VEHICLE_MODE_COMPLETE_AUTO_DRIVE'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__VEHICLE_MODE_COMPLETE_AUTO_DRIVE = 1
};

/// Constant 'VEHICLE_MODE_AUTO_STEER_ONLY'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__VEHICLE_MODE_AUTO_STEER_ONLY = 2
};

/// Constant 'VEHICLE_MODE_AUTO_SPEED_ONLY'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__VEHICLE_MODE_AUTO_SPEED_ONLY = 3
};

/// Constant 'VEHICLE_MODE_EMERGENCY_MODE'.
enum
{
  lgsvl_msgs__msg__VehicleStateData__VEHICLE_MODE_EMERGENCY_MODE = 4
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

// Struct defined in msg/VehicleStateData in the package lgsvl_msgs.
typedef struct lgsvl_msgs__msg__VehicleStateData
{
  std_msgs__msg__Header header;
  uint8_t blinker_state;
  uint8_t headlight_state;
  uint8_t wiper_state;
  uint8_t current_gear;
  uint8_t vehicle_mode;
  bool hand_brake_active;
  bool horn_active;
  bool autonomous_mode_active;
} lgsvl_msgs__msg__VehicleStateData;

// Struct for a sequence of lgsvl_msgs__msg__VehicleStateData.
typedef struct lgsvl_msgs__msg__VehicleStateData__Sequence
{
  lgsvl_msgs__msg__VehicleStateData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lgsvl_msgs__msg__VehicleStateData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LGSVL_MSGS__MSG__DETAIL__VEHICLE_STATE_DATA__STRUCT_H_
