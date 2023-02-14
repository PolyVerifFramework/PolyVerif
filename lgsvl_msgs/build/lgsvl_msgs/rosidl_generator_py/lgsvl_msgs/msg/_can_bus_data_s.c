// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from lgsvl_msgs:msg/CanBusData.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "lgsvl_msgs/msg/detail/can_bus_data__struct.h"
#include "lgsvl_msgs/msg/detail/can_bus_data__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__quaternion__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__quaternion__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__vector3__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__vector3__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool lgsvl_msgs__msg__can_bus_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("lgsvl_msgs.msg._can_bus_data.CanBusData", full_classname_dest, 39) == 0);
  }
  lgsvl_msgs__msg__CanBusData * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // speed_mps
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_mps");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_mps = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // throttle_pct
    PyObject * field = PyObject_GetAttrString(_pymsg, "throttle_pct");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->throttle_pct = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // brake_pct
    PyObject * field = PyObject_GetAttrString(_pymsg, "brake_pct");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->brake_pct = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // steer_pct
    PyObject * field = PyObject_GetAttrString(_pymsg, "steer_pct");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->steer_pct = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // parking_brake_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "parking_brake_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->parking_brake_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // high_beams_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "high_beams_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->high_beams_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // low_beams_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "low_beams_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->low_beams_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // hazard_lights_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "hazard_lights_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hazard_lights_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // fog_lights_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "fog_lights_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->fog_lights_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // left_turn_signal_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_turn_signal_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->left_turn_signal_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // right_turn_signal_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_turn_signal_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->right_turn_signal_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // wipers_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "wipers_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->wipers_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // reverse_gear_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "reverse_gear_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->reverse_gear_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // selected_gear
    PyObject * field = PyObject_GetAttrString(_pymsg, "selected_gear");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->selected_gear = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // engine_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "engine_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->engine_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // engine_rpm
    PyObject * field = PyObject_GetAttrString(_pymsg, "engine_rpm");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->engine_rpm = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gps_latitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps_latitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gps_latitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gps_longitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps_longitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gps_longitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gps_altitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "gps_altitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gps_altitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orientation
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__quaternion__convert_from_py(field, &ros_message->orientation)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // linear_velocities
    PyObject * field = PyObject_GetAttrString(_pymsg, "linear_velocities");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__vector3__convert_from_py(field, &ros_message->linear_velocities)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * lgsvl_msgs__msg__can_bus_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CanBusData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("lgsvl_msgs.msg._can_bus_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CanBusData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  lgsvl_msgs__msg__CanBusData * ros_message = (lgsvl_msgs__msg__CanBusData *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_mps
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_mps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_mps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // throttle_pct
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->throttle_pct);
    {
      int rc = PyObject_SetAttrString(_pymessage, "throttle_pct", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // brake_pct
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->brake_pct);
    {
      int rc = PyObject_SetAttrString(_pymessage, "brake_pct", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steer_pct
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->steer_pct);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steer_pct", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // parking_brake_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->parking_brake_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "parking_brake_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // high_beams_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->high_beams_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "high_beams_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // low_beams_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->low_beams_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "low_beams_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hazard_lights_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hazard_lights_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hazard_lights_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fog_lights_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->fog_lights_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fog_lights_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_turn_signal_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->left_turn_signal_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_turn_signal_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_turn_signal_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->right_turn_signal_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_turn_signal_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // wipers_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->wipers_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "wipers_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reverse_gear_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->reverse_gear_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reverse_gear_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // selected_gear
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->selected_gear);
    {
      int rc = PyObject_SetAttrString(_pymessage, "selected_gear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // engine_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->engine_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "engine_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // engine_rpm
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->engine_rpm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "engine_rpm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gps_latitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gps_latitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps_latitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gps_longitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gps_longitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps_longitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gps_altitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gps_altitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gps_altitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation
    PyObject * field = NULL;
    field = geometry_msgs__msg__quaternion__convert_to_py(&ros_message->orientation);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // linear_velocities
    PyObject * field = NULL;
    field = geometry_msgs__msg__vector3__convert_to_py(&ros_message->linear_velocities);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "linear_velocities", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
