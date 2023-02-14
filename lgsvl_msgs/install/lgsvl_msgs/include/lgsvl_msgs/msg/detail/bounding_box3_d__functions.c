// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lgsvl_msgs:msg/BoundingBox3D.idl
// generated code does not contain a copyright notice
#include "lgsvl_msgs/msg/detail/bounding_box3_d__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `size`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
lgsvl_msgs__msg__BoundingBox3D__init(lgsvl_msgs__msg__BoundingBox3D * msg)
{
  if (!msg) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Pose__init(&msg->position)) {
    lgsvl_msgs__msg__BoundingBox3D__fini(msg);
    return false;
  }
  // size
  if (!geometry_msgs__msg__Vector3__init(&msg->size)) {
    lgsvl_msgs__msg__BoundingBox3D__fini(msg);
    return false;
  }
  return true;
}

void
lgsvl_msgs__msg__BoundingBox3D__fini(lgsvl_msgs__msg__BoundingBox3D * msg)
{
  if (!msg) {
    return;
  }
  // position
  geometry_msgs__msg__Pose__fini(&msg->position);
  // size
  geometry_msgs__msg__Vector3__fini(&msg->size);
}

lgsvl_msgs__msg__BoundingBox3D *
lgsvl_msgs__msg__BoundingBox3D__create()
{
  lgsvl_msgs__msg__BoundingBox3D * msg = (lgsvl_msgs__msg__BoundingBox3D *)malloc(sizeof(lgsvl_msgs__msg__BoundingBox3D));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lgsvl_msgs__msg__BoundingBox3D));
  bool success = lgsvl_msgs__msg__BoundingBox3D__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
lgsvl_msgs__msg__BoundingBox3D__destroy(lgsvl_msgs__msg__BoundingBox3D * msg)
{
  if (msg) {
    lgsvl_msgs__msg__BoundingBox3D__fini(msg);
  }
  free(msg);
}


bool
lgsvl_msgs__msg__BoundingBox3D__Sequence__init(lgsvl_msgs__msg__BoundingBox3D__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  lgsvl_msgs__msg__BoundingBox3D * data = NULL;
  if (size) {
    data = (lgsvl_msgs__msg__BoundingBox3D *)calloc(size, sizeof(lgsvl_msgs__msg__BoundingBox3D));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lgsvl_msgs__msg__BoundingBox3D__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lgsvl_msgs__msg__BoundingBox3D__fini(&data[i - 1]);
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
lgsvl_msgs__msg__BoundingBox3D__Sequence__fini(lgsvl_msgs__msg__BoundingBox3D__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      lgsvl_msgs__msg__BoundingBox3D__fini(&array->data[i]);
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

lgsvl_msgs__msg__BoundingBox3D__Sequence *
lgsvl_msgs__msg__BoundingBox3D__Sequence__create(size_t size)
{
  lgsvl_msgs__msg__BoundingBox3D__Sequence * array = (lgsvl_msgs__msg__BoundingBox3D__Sequence *)malloc(sizeof(lgsvl_msgs__msg__BoundingBox3D__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = lgsvl_msgs__msg__BoundingBox3D__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
lgsvl_msgs__msg__BoundingBox3D__Sequence__destroy(lgsvl_msgs__msg__BoundingBox3D__Sequence * array)
{
  if (array) {
    lgsvl_msgs__msg__BoundingBox3D__Sequence__fini(array);
  }
  free(array);
}
