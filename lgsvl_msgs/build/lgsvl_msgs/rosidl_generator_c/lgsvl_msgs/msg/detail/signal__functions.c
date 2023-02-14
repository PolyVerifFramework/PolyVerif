// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lgsvl_msgs:msg/Signal.idl
// generated code does not contain a copyright notice
#include "lgsvl_msgs/msg/detail/signal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `label`
#include "rosidl_runtime_c/string_functions.h"
// Member `bbox`
#include "lgsvl_msgs/msg/detail/bounding_box3_d__functions.h"

bool
lgsvl_msgs__msg__Signal__init(lgsvl_msgs__msg__Signal * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    lgsvl_msgs__msg__Signal__fini(msg);
    return false;
  }
  // id
  // label
  if (!rosidl_runtime_c__String__init(&msg->label)) {
    lgsvl_msgs__msg__Signal__fini(msg);
    return false;
  }
  // score
  // bbox
  if (!lgsvl_msgs__msg__BoundingBox3D__init(&msg->bbox)) {
    lgsvl_msgs__msg__Signal__fini(msg);
    return false;
  }
  return true;
}

void
lgsvl_msgs__msg__Signal__fini(lgsvl_msgs__msg__Signal * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // id
  // label
  rosidl_runtime_c__String__fini(&msg->label);
  // score
  // bbox
  lgsvl_msgs__msg__BoundingBox3D__fini(&msg->bbox);
}

lgsvl_msgs__msg__Signal *
lgsvl_msgs__msg__Signal__create()
{
  lgsvl_msgs__msg__Signal * msg = (lgsvl_msgs__msg__Signal *)malloc(sizeof(lgsvl_msgs__msg__Signal));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lgsvl_msgs__msg__Signal));
  bool success = lgsvl_msgs__msg__Signal__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
lgsvl_msgs__msg__Signal__destroy(lgsvl_msgs__msg__Signal * msg)
{
  if (msg) {
    lgsvl_msgs__msg__Signal__fini(msg);
  }
  free(msg);
}


bool
lgsvl_msgs__msg__Signal__Sequence__init(lgsvl_msgs__msg__Signal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  lgsvl_msgs__msg__Signal * data = NULL;
  if (size) {
    data = (lgsvl_msgs__msg__Signal *)calloc(size, sizeof(lgsvl_msgs__msg__Signal));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lgsvl_msgs__msg__Signal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lgsvl_msgs__msg__Signal__fini(&data[i - 1]);
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
lgsvl_msgs__msg__Signal__Sequence__fini(lgsvl_msgs__msg__Signal__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      lgsvl_msgs__msg__Signal__fini(&array->data[i]);
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

lgsvl_msgs__msg__Signal__Sequence *
lgsvl_msgs__msg__Signal__Sequence__create(size_t size)
{
  lgsvl_msgs__msg__Signal__Sequence * array = (lgsvl_msgs__msg__Signal__Sequence *)malloc(sizeof(lgsvl_msgs__msg__Signal__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = lgsvl_msgs__msg__Signal__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
lgsvl_msgs__msg__Signal__Sequence__destroy(lgsvl_msgs__msg__Signal__Sequence * array)
{
  if (array) {
    lgsvl_msgs__msg__Signal__Sequence__fini(array);
  }
  free(array);
}
