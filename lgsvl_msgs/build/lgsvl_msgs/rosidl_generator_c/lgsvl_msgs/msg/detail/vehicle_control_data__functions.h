// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from lgsvl_msgs:msg/VehicleControlData.idl
// generated code does not contain a copyright notice

#ifndef LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__FUNCTIONS_H_
#define LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "lgsvl_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "lgsvl_msgs/msg/detail/vehicle_control_data__struct.h"

/// Initialize msg/VehicleControlData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lgsvl_msgs__msg__VehicleControlData
 * )) before or use
 * lgsvl_msgs__msg__VehicleControlData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
bool
lgsvl_msgs__msg__VehicleControlData__init(lgsvl_msgs__msg__VehicleControlData * msg);

/// Finalize msg/VehicleControlData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
void
lgsvl_msgs__msg__VehicleControlData__fini(lgsvl_msgs__msg__VehicleControlData * msg);

/// Create msg/VehicleControlData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lgsvl_msgs__msg__VehicleControlData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
lgsvl_msgs__msg__VehicleControlData *
lgsvl_msgs__msg__VehicleControlData__create();

/// Destroy msg/VehicleControlData message.
/**
 * It calls
 * lgsvl_msgs__msg__VehicleControlData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
void
lgsvl_msgs__msg__VehicleControlData__destroy(lgsvl_msgs__msg__VehicleControlData * msg);


/// Initialize array of msg/VehicleControlData messages.
/**
 * It allocates the memory for the number of elements and calls
 * lgsvl_msgs__msg__VehicleControlData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
bool
lgsvl_msgs__msg__VehicleControlData__Sequence__init(lgsvl_msgs__msg__VehicleControlData__Sequence * array, size_t size);

/// Finalize array of msg/VehicleControlData messages.
/**
 * It calls
 * lgsvl_msgs__msg__VehicleControlData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
void
lgsvl_msgs__msg__VehicleControlData__Sequence__fini(lgsvl_msgs__msg__VehicleControlData__Sequence * array);

/// Create array of msg/VehicleControlData messages.
/**
 * It allocates the memory for the array and calls
 * lgsvl_msgs__msg__VehicleControlData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
lgsvl_msgs__msg__VehicleControlData__Sequence *
lgsvl_msgs__msg__VehicleControlData__Sequence__create(size_t size);

/// Destroy array of msg/VehicleControlData messages.
/**
 * It calls
 * lgsvl_msgs__msg__VehicleControlData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lgsvl_msgs
void
lgsvl_msgs__msg__VehicleControlData__Sequence__destroy(lgsvl_msgs__msg__VehicleControlData__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // LGSVL_MSGS__MSG__DETAIL__VEHICLE_CONTROL_DATA__FUNCTIONS_H_
