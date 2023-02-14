// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lgsvl_msgs:msg/CanBusData.idl
// generated code does not contain a copyright notice
#include "lgsvl_msgs/msg/detail/can_bus_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `orientation`
#include "geometry_msgs/msg/detail/quaternion__functions.h"
// Member `linear_velocities`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
lgsvl_msgs__msg__CanBusData__init(lgsvl_msgs__msg__CanBusData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    lgsvl_msgs__msg__CanBusData__fini(msg);
    return false;
  }
  // speed_mps
  // throttle_pct
  // brake_pct
  // steer_pct
  // parking_brake_active
  // high_beams_active
  // low_beams_active
  // hazard_lights_active
  // fog_lights_active
  // left_turn_signal_active
  // right_turn_signal_active
  // wipers_active
  // reverse_gear_active
  // selected_gear
  // engine_active
  // engine_rpm
  // gps_latitude
  // gps_longitude
  // gps_altitude
  // orientation
  if (!geometry_msgs__msg__Quaternion__init(&msg->orientation)) {
    lgsvl_msgs__msg__CanBusData__fini(msg);
    return false;
  }
  // linear_velocities
  if (!geometry_msgs__msg__Vector3__init(&msg->linear_velocities)) {
    lgsvl_msgs__msg__CanBusData__fini(msg);
    return false;
  }
  return true;
}

void
lgsvl_msgs__msg__CanBusData__fini(lgsvl_msgs__msg__CanBusData * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // speed_mps
  // throttle_pct
  // brake_pct
  // steer_pct
  // parking_brake_active
  // high_beams_active
  // low_beams_active
  // hazard_lights_active
  // fog_lights_active
  // left_turn_signal_active
  // right_turn_signal_active
  // wipers_active
  // reverse_gear_active
  // selected_gear
  // engine_active
  // engine_rpm
  // gps_latitude
  // gps_longitude
  // gps_altitude
  // orientation
  geometry_msgs__msg__Quaternion__fini(&msg->orientation);
  // linear_velocities
  geometry_msgs__msg__Vector3__fini(&msg->linear_velocities);
}

lgsvl_msgs__msg__CanBusData *
lgsvl_msgs__msg__CanBusData__create()
{
  lgsvl_msgs__msg__CanBusData * msg = (lgsvl_msgs__msg__CanBusData *)malloc(sizeof(lgsvl_msgs__msg__CanBusData));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lgsvl_msgs__msg__CanBusData));
  bool success = lgsvl_msgs__msg__CanBusData__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
lgsvl_msgs__msg__CanBusData__destroy(lgsvl_msgs__msg__CanBusData * msg)
{
  if (msg) {
    lgsvl_msgs__msg__CanBusData__fini(msg);
  }
  free(msg);
}


bool
lgsvl_msgs__msg__CanBusData__Sequence__init(lgsvl_msgs__msg__CanBusData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  lgsvl_msgs__msg__CanBusData * data = NULL;
  if (size) {
    data = (lgsvl_msgs__msg__CanBusData *)calloc(size, sizeof(lgsvl_msgs__msg__CanBusData));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lgsvl_msgs__msg__CanBusData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lgsvl_msgs__msg__CanBusData__fini(&data[i - 1]);
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
lgsvl_msgs__msg__CanBusData__Sequence__fini(lgsvl_msgs__msg__CanBusData__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      lgsvl_msgs__msg__CanBusData__fini(&array->data[i]);
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

lgsvl_msgs__msg__CanBusData__Sequence *
lgsvl_msgs__msg__CanBusData__Sequence__create(size_t size)
{
  lgsvl_msgs__msg__CanBusData__Sequence * array = (lgsvl_msgs__msg__CanBusData__Sequence *)malloc(sizeof(lgsvl_msgs__msg__CanBusData__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = lgsvl_msgs__msg__CanBusData__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
lgsvl_msgs__msg__CanBusData__Sequence__destroy(lgsvl_msgs__msg__CanBusData__Sequence * array)
{
  if (array) {
    lgsvl_msgs__msg__CanBusData__Sequence__fini(array);
  }
  free(array);
}
