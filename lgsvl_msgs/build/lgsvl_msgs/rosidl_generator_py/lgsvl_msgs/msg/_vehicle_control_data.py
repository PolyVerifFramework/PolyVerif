# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lgsvl_msgs:msg/VehicleControlData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VehicleControlData(type):
    """Metaclass of message 'VehicleControlData'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'GEAR_NEUTRAL': 0,
        'GEAR_DRIVE': 1,
        'GEAR_REVERSE': 2,
        'GEAR_PARKING': 3,
        'GEAR_LOW': 4,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('lgsvl_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'lgsvl_msgs.msg.VehicleControlData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vehicle_control_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vehicle_control_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vehicle_control_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vehicle_control_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vehicle_control_data

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'GEAR_NEUTRAL': cls.__constants['GEAR_NEUTRAL'],
            'GEAR_DRIVE': cls.__constants['GEAR_DRIVE'],
            'GEAR_REVERSE': cls.__constants['GEAR_REVERSE'],
            'GEAR_PARKING': cls.__constants['GEAR_PARKING'],
            'GEAR_LOW': cls.__constants['GEAR_LOW'],
        }

    @property
    def GEAR_NEUTRAL(self):
        """Message constant 'GEAR_NEUTRAL'."""
        return Metaclass_VehicleControlData.__constants['GEAR_NEUTRAL']

    @property
    def GEAR_DRIVE(self):
        """Message constant 'GEAR_DRIVE'."""
        return Metaclass_VehicleControlData.__constants['GEAR_DRIVE']

    @property
    def GEAR_REVERSE(self):
        """Message constant 'GEAR_REVERSE'."""
        return Metaclass_VehicleControlData.__constants['GEAR_REVERSE']

    @property
    def GEAR_PARKING(self):
        """Message constant 'GEAR_PARKING'."""
        return Metaclass_VehicleControlData.__constants['GEAR_PARKING']

    @property
    def GEAR_LOW(self):
        """Message constant 'GEAR_LOW'."""
        return Metaclass_VehicleControlData.__constants['GEAR_LOW']


class VehicleControlData(metaclass=Metaclass_VehicleControlData):
    """
    Message class 'VehicleControlData'.

    Constants:
      GEAR_NEUTRAL
      GEAR_DRIVE
      GEAR_REVERSE
      GEAR_PARKING
      GEAR_LOW
    """

    __slots__ = [
        '_header',
        '_acceleration_pct',
        '_braking_pct',
        '_target_wheel_angle',
        '_target_wheel_angular_rate',
        '_target_gear',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'acceleration_pct': 'float',
        'braking_pct': 'float',
        'target_wheel_angle': 'float',
        'target_wheel_angular_rate': 'float',
        'target_gear': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.acceleration_pct = kwargs.get('acceleration_pct', float())
        self.braking_pct = kwargs.get('braking_pct', float())
        self.target_wheel_angle = kwargs.get('target_wheel_angle', float())
        self.target_wheel_angular_rate = kwargs.get('target_wheel_angular_rate', float())
        self.target_gear = kwargs.get('target_gear', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.acceleration_pct != other.acceleration_pct:
            return False
        if self.braking_pct != other.braking_pct:
            return False
        if self.target_wheel_angle != other.target_wheel_angle:
            return False
        if self.target_wheel_angular_rate != other.target_wheel_angular_rate:
            return False
        if self.target_gear != other.target_gear:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @property
    def acceleration_pct(self):
        """Message field 'acceleration_pct'."""
        return self._acceleration_pct

    @acceleration_pct.setter
    def acceleration_pct(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'acceleration_pct' field must be of type 'float'"
        self._acceleration_pct = value

    @property
    def braking_pct(self):
        """Message field 'braking_pct'."""
        return self._braking_pct

    @braking_pct.setter
    def braking_pct(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'braking_pct' field must be of type 'float'"
        self._braking_pct = value

    @property
    def target_wheel_angle(self):
        """Message field 'target_wheel_angle'."""
        return self._target_wheel_angle

    @target_wheel_angle.setter
    def target_wheel_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_wheel_angle' field must be of type 'float'"
        self._target_wheel_angle = value

    @property
    def target_wheel_angular_rate(self):
        """Message field 'target_wheel_angular_rate'."""
        return self._target_wheel_angular_rate

    @target_wheel_angular_rate.setter
    def target_wheel_angular_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_wheel_angular_rate' field must be of type 'float'"
        self._target_wheel_angular_rate = value

    @property
    def target_gear(self):
        """Message field 'target_gear'."""
        return self._target_gear

    @target_gear.setter
    def target_gear(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'target_gear' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'target_gear' field must be an unsigned integer in [0, 255]"
        self._target_gear = value
