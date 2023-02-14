// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lgsvl_msgs:msg/DetectedRadarObject.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__STRUCT_H_
#define LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'STATE_MOVING'.
enum
{
  lgsvl_msgs__msg__DetectedRadarObject__STATE_MOVING = 0
};

/// Constant 'STATE_STATIONARY'.
enum
{
  lgsvl_msgs__msg__DetectedRadarObject__STATE_STATIONARY = 1
};

// Include directives for member types
// Member 'sensor_aim'
// Member 'sensor_right'
// Member 'sensor_velocity'
// Member 'object_velocity'
// Member 'object_relative_velocity'
// Member 'object_collider_size'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'sensor_position'
// Member 'object_position'
// Member 'object_relative_position'
#include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in msg/DetectedRadarObject in the package lgsvl_msgs.
typedef struct lgsvl_msgs__msg__DetectedRadarObject
{
  int32_t id;
  geometry_msgs__msg__Vector3 sensor_aim;
  geometry_msgs__msg__Vector3 sensor_right;
  geometry_msgs__msg__Point sensor_position;
  geometry_msgs__msg__Vector3 sensor_velocity;
  double sensor_angle;
  geometry_msgs__msg__Point object_position;
  geometry_msgs__msg__Vector3 object_velocity;
  geometry_msgs__msg__Point object_relative_position;
  geometry_msgs__msg__Vector3 object_relative_velocity;
  geometry_msgs__msg__Vector3 object_collider_size;
  uint8_t object_state;
  bool new_detection;
} lgsvl_msgs__msg__DetectedRadarObject;

// Struct for a sequence of lgsvl_msgs__msg__DetectedRadarObject.
typedef struct lgsvl_msgs__msg__DetectedRadarObject__Sequence
{
  lgsvl_msgs__msg__DetectedRadarObject * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lgsvl_msgs__msg__DetectedRadarObject__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT__STRUCT_H_
