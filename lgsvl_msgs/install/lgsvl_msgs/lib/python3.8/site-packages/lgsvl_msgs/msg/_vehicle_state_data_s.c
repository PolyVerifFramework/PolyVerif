// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from lgsvl_msgs:msg/VehicleStateData.idl
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
#include "lgsvl_msgs/msg/detail/vehicle_state_data__struct.h"
#include "lgsvl_msgs/msg/detail/vehicle_state_data__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool lgsvl_msgs__msg__vehicle_state_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[52];
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
    assert(strncmp("lgsvl_msgs.msg._vehicle_state_data.VehicleStateData", full_classname_dest, 51) == 0);
  }
  lgsvl_msgs__msg__VehicleStateData * ros_message = _ros_message;
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
  {  // blinker_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "blinker_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->blinker_state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // headlight_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "headlight_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->headlight_state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // wiper_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "wiper_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->wiper_state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // current_gear
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_gear");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->current_gear = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // vehicle_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "vehicle_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vehicle_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // hand_brake_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "hand_brake_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->hand_brake_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // horn_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "horn_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->horn_active = (Py_True == field);
    Py_DECREF(field);
  }
  {  // autonomous_mode_active
    PyObject * field = PyObject_GetAttrString(_pymsg, "autonomous_mode_active");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->autonomous_mode_active = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * lgsvl_msgs__msg__vehicle_state_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of VehicleStateData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("lgsvl_msgs.msg._vehicle_state_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "VehicleStateData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  lgsvl_msgs__msg__VehicleStateData * ros_message = (lgsvl_msgs__msg__VehicleStateData *)raw_ros_message;
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
  {  // blinker_state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->blinker_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "blinker_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // headlight_state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->headlight_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "headlight_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // wiper_state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->wiper_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "wiper_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_gear
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->current_gear);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_gear", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vehicle_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->vehicle_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vehicle_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hand_brake_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->hand_brake_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hand_brake_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // horn_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->horn_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "horn_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // autonomous_mode_active
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->autonomous_mode_active ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "autonomous_mode_active", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
