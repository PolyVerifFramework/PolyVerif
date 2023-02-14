// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from lgsvl_msgs:msg/DetectedRadarObjectArray.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__FUNCTIONS_H_
#define LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "lgsvl_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "lgsvl_msgs/msg/detail/detected_radar_object_array__struct.h"

/// Initialize msg/DetectedRadarObjectArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lgsvl_msgs__msg__DetectedRadarObjectArray
 * )) before or use
 * lgsvl_msgs__msg__DetectedRadarObjectArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
bool
lgsvl_msgs__msg__DetectedRadarObjectArray__init(lgsvl_msgs__msg__DetectedRadarObjectArray * msg);

/// Finalize msg/DetectedRadarObjectArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
void
lgsvl_msgs__msg__DetectedRadarObjectArray__fini(lgsvl_msgs__msg__DetectedRadarObjectArray * msg);

/// Create msg/DetectedRadarObjectArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lgsvl_msgs__msg__DetectedRadarObjectArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
lgsvl_msgs__msg__DetectedRadarObjectArray *
lgsvl_msgs__msg__DetectedRadarObjectArray__create();

/// Destroy msg/DetectedRadarObjectArray message.
/**
 * It calls
 * lgsvl_msgs__msg__DetectedRadarObjectArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
void
lgsvl_msgs__msg__DetectedRadarObjectArray__destroy(lgsvl_msgs__msg__DetectedRadarObjectArray * msg);


/// Initialize array of msg/DetectedRadarObjectArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * lgsvl_msgs__msg__DetectedRadarObjectArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
bool
lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence__init(lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence * array, size_t size);

/// Finalize array of msg/DetectedRadarObjectArray messages.
/**
 * It calls
 * lgsvl_msgs__msg__DetectedRadarObjectArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
void
lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence__fini(lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence * array);

/// Create array of msg/DetectedRadarObjectArray messages.
/**
 * It allocates the memory for the array and calls
 * lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence *
lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence__create(size_t size);

/// Destroy array of msg/DetectedRadarObjectArray messages.
/**
 * It calls
 * lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
void
lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence__destroy(lgsvl_msgs__msg__DetectedRadarObjectArray__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // LGSVL_MSGS__MSG__DETAIL__DETECTED_RADAR_OBJECT_ARRAY__FUNCTIONS_H_
