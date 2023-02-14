// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lgsvl_msgs:msg/DetectedRadarObjectArray.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__STRUCT_H_
#define LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'objects'
#include "lgsvl_msgs/msg/detail/detected_radar_object__struct.h"

// Struct defined in msg/DetectedRadarObjectArray in the package lgsvl_msgs.
typedef struct lgsvl_msgs__msg__DetectedRadarObjectArray
{
  std_msgs__msg__Header header;
  lgsvl_msgs__msg__DetectedRadarObject__Sequence objects;
} lgsvl_msgs__msg__DetectedRadarObjectArray;

// Struct for a sequence of lgsvl_msgs__msg__DetectedRadarObjectArray.
typedef struct lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence
{
  lgsvl_msgs__msg__DetectedRadarObjectArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__STRUCT_H_
