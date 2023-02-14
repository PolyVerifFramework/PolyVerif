// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lgsvl_msgs:msg/DetectedRadarObject.idl
// generated code does not contain a copyright notice
#include "lgsvl_msgs/msg/detail/detected_radar_object__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `sensor_aim`
// Member `sensor_right`
// Member `sensor_velocity`
// Member `object_velocity`
// Member `object_relative_velocity`
// Member `object_collider_size`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `sensor_position`
// Member `object_position`
// Member `object_relative_position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
lgsvl_msgs__msg__DetectedRadarObject__init(lgsvl_msgs__msg__DetectedRadarObject * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // sensor_aim
  if (!geometry_msgs__msg__Vector3__init(&msg->sensor_aim)) {
    lgsvl_msgs__msg__DetectedRadarObject__fini(msg);
    return false;
  }
  // sensor_right
  if (!geometry_msgs__msg__Vector3__init(&msg->sensor_right)) {
    lgsvl_msgs__msg__DetectedRadarObject__fini(msg);
    return false;
  }
  // sensor_position
  if (!geometry_msgs__msg__Point__init(&msg->sensor_position)) {
    lgsvl_msgs__msg__DetectedRadarObject__fini(msg);
    return false;
  }
  // sensor_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->sensor_velocity)) {
    lgsvl_msgs__msg__DetectedRadarObject__fini(msg);
    return false;
  }
  // sensor_angle
  // object_position
  if (!geometry_msgs__msg__Point__init(&msg->object_position)) {
    lgsvl_msgs__msg__DetectedRadarObject__fini(msg);
    return false;
  }
  // object_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->object_velocity)) {
    lgsvl_msgs__msg__DetectedRadarObject__fini(msg);
    return false;
  }
  // object_relative_position
  if (!geometry_msgs__msg__Point__init(&msg->object_relative_position)) {
    lgsvl_msgs__msg__DetectedRadarObject__fini(msg);
    return false;
  }
  // object_relative_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->object_relative_velocity)) {
    lgsvl_msgs__msg__DetectedRadarObject__fini(msg);
    return false;
  }
  // object_collider_size
  if (!geometry_msgs__msg__Vector3__init(&msg->object_collider_size)) {
    lgsvl_msgs__msg__DetectedRadarObject__fini(msg);
    return false;
  }
  // object_state
  // new_detection
  return true;
}

void
lgsvl_msgs__msg__DetectedRadarObject__fini(lgsvl_msgs__msg__DetectedRadarObject * msg)
{
  if (!msg) {
    return;
  }
  // id
  // sensor_aim
  geometry_msgs__msg__Vector3__fini(&msg->sensor_aim);
  // sensor_right
  geometry_msgs__msg__Vector3__fini(&msg->sensor_right);
  // sensor_position
  geometry_msgs__msg__Point__fini(&msg->sensor_position);
  // sensor_velocity
  geometry_msgs__msg__Vector3__fini(&msg->sensor_velocity);
  // sensor_angle
  // object_position
  geometry_msgs__msg__Point__fini(&msg->object_position);
  // object_velocity
  geometry_msgs__msg__Vector3__fini(&msg->object_velocity);
  // object_relative_position
  geometry_msgs__msg__Point__fini(&msg->object_relative_position);
  // object_relative_velocity
  geometry_msgs__msg__Vector3__fini(&msg->object_relative_velocity);
  // object_collider_size
  geometry_msgs__msg__Vector3__fini(&msg->object_collider_size);
  // object_state
  // new_detection
}

lgsvl_msgs__msg__DetectedRadarObject *
lgsvl_msgs__msg__DetectedRadarObject__create()
{
  lgsvl_msgs__msg__DetectedRadarObject * msg = (lgsvl_msgs__msg__DetectedRadarObject *)malloc(sizeof(lgsvl_msgs__msg__DetectedRadarObject));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lgsvl_msgs__msg__DetectedRadarObject));
  bool success = lgsvl_msgs__msg__DetectedRadarObject__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
lgsvl_msgs__msg__DetectedRadarObject__destroy(lgsvl_msgs__msg__DetectedRadarObject * msg)
{
  if (msg) {
    lgsvl_msgs__msg__DetectedRadarObject__fini(msg);
  }
  free(msg);
}


bool
lgsvl_msgs__msg__DetectedRadarObject__Sequence__init(lgsvl_msgs__msg__DetectedRadarObject__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  lgsvl_msgs__msg__DetectedRadarObject * data = NULL;
  if (size) {
    data = (lgsvl_msgs__msg__DetectedRadarObject *)calloc(size, sizeof(lgsvl_msgs__msg__DetectedRadarObject));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lgsvl_msgs__msg__DetectedRadarObject__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lgsvl_msgs__msg__DetectedRadarObject__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
lgsvl_msgs__msg__DetectedRadarObject__Sequence__fini(lgsvl_msgs__msg__DetectedRadarObject__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      lgsvl_msgs__msg__DetectedRadarObject__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

lgsvl_msgs__msg__DetectedRadarObject__Sequence *
lgsvl_msgs__msg__DetectedRadarObject__Sequence__create(size_t size)
{
  lgsvl_msgs__msg__DetectedRadarObject__Sequence * array = (lgsvl_msgs__msg__DetectedRadarObject__Sequence *)malloc(sizeof(lgsvl_msgs__msg__DetectedRadarObject__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = lgsvl_msgs__msg__DetectedRadarObject__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
lgsvl_msgs__msg__DetectedRadarObject__Sequence__destroy(lgsvl_msgs__msg__DetectedRadarObject__Sequence * array)
{
  if (array) {
    lgsvl_msgs__msg__DetectedRadarObject__Sequence__fini(array);
  }
  free(array);
}
