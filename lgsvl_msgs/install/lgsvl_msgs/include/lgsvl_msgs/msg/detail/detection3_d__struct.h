// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lgsvl_msgs:msg/Detection3D.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTION3_D__STRUCT_H_
#define LGSVL_MSGS__MSG__DETAIL__DETECTION3_D__STRUCT_H_

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
// Member 'label'
#include "rosidl_runtime_c/string.h"
// Member 'bbox'
#include "lgsvl_msgs/msg/detail/bounding_box3_d__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__struct.h"

// Struct defined in msg/Detection3D in the package lgsvl_msgs.
typedef struct lgsvl_msgs__msg__Detection3D
{
  std_msgs__msg__Header header;
  uint32_t id;
  rosidl_runtime_c__String label;
  float score;
  lgsvl_msgs__msg__BoundingBox3D bbox;
  geometry_msgs__msg__Twist velocity;
} lgsvl_msgs__msg__Detection3D;

// Struct for a sequence of lgsvl_msgs__msg__Detection3D.
typedef struct lgsvl_msgs__msg__Detection3D__Sequence
{
  lgsvl_msgs__msg__Detection3D * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lgsvl_msgs__msg__Detection3D__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTION3_D__STRUCT_H_
