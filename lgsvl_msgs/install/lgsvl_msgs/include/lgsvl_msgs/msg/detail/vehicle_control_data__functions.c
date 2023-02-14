// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lgsvl_msgs:msg/VehicleControlData.idl
// generated code does not contain a copyright notice
#include "lgsvl_msgs/msg/detail/vehicle_control_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
lgsvl_msgs__msg__VehicleControlData__init(lgsvl_msgs__msg__VehicleControlData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    lgsvl_msgs__msg__VehicleControlData__fini(msg);
    return false;
  }
  // acceleration_pct
  // braking_pct
  // target_wheel_angle
  // target_wheel_angular_rate
  // target_gear
  return true;
}

void
lgsvl_msgs__msg__VehicleControlData__fini(lgsvl_msgs__msg__VehicleControlData * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // acceleration_pct
  // braking_pct
  // target_wheel_angle
  // target_wheel_angular_rate
  // target_gear
}

lgsvl_msgs__msg__VehicleControlData *
lgsvl_msgs__msg__VehicleControlData__create()
{
  lgsvl_msgs__msg__VehicleControlData * msg = (lgsvl_msgs__msg__VehicleControlData *)malloc(sizeof(lgsvl_msgs__msg__VehicleControlData));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lgsvl_msgs__msg__VehicleControlData));
  bool success = lgsvl_msgs__msg__VehicleControlData__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
lgsvl_msgs__msg__VehicleControlData__destroy(lgsvl_msgs__msg__VehicleControlData * msg)
{
  if (msg) {
    lgsvl_msgs__msg__VehicleControlData__fini(msg);
  }
  free(msg);
}


bool
lgsvl_msgs__msg__VehicleControlData__Sequence__init(lgsvl_msgs__msg__VehicleControlData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  lgsvl_msgs__msg__VehicleControlData * data = NULL;
  if (size) {
    data = (lgsvl_msgs__msg__VehicleControlData *)calloc(size, sizeof(lgsvl_msgs__msg__VehicleControlData));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lgsvl_msgs__msg__VehicleControlData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lgsvl_msgs__msg__VehicleControlData__fini(&data[i - 1]);
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
lgsvl_msgs__msg__VehicleControlData__Sequence__fini(lgsvl_msgs__msg__VehicleControlData__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      lgsvl_msgs__msg__VehicleControlData__fini(&array->data[i]);
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

lgsvl_msgs__msg__VehicleControlData__Sequence *
lgsvl_msgs__msg__VehicleControlData__Sequence__create(size_t size)
{
  lgsvl_msgs__msg__VehicleControlData__Sequence * array = (lgsvl_msgs__msg__VehicleControlData__Sequence *)malloc(sizeof(lgsvl_msgs__msg__VehicleControlData__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = lgsvl_msgs__msg__VehicleControlData__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
lgsvl_msgs__msg__VehicleControlData__Sequence__destroy(lgsvl_msgs__msg__VehicleControlData__Sequence * array)
{
  if (array) {
    lgsvl_msgs__msg__VehicleControlData__Sequence__fini(array);
  }
  free(array);
}
