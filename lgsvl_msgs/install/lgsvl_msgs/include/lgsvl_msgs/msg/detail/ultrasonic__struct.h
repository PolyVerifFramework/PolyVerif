// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lgsvl_msgs:msg/Ultrasonic.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__ULTRASONIC__STRUCT_H_
#define LGSVL_MSGS__MSG__DETAIL__ULTRASONIC__STRUCT_H_

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

// Struct defined in msg/Ultrasonic in the package lgsvl_msgs.
typedef struct lgsvl_msgs__msg__Ultrasonic
{
  std_msgs__msg__Header header;
  float minimum_distance;
} lgsvl_msgs__msg__Ultrasonic;

// Struct for a sequence of lgsvl_msgs__msg__Ultrasonic.
typedef struct lgsvl_msgs__msg__Ultrasonic__Sequence
{
  lgsvl_msgs__msg__Ultrasonic * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lgsvl_msgs__msg__Ultrasonic__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LGSVL_MSGS__MSG__DETAIL__ULTRASONIC__STRUCT_H_
