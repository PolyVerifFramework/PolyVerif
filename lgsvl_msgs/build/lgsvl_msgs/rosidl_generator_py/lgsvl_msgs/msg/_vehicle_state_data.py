# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lgsvl_msgs:msg/VehicleStateData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VehicleStateData(type):
    """Metaclass of message 'VehicleStateData'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'BLINKERS_OFF': 0,
        'BLINKERS_LEFT': 1,
        'BLINKERS_RIGHT': 2,
        'BLINKERS_HAZARD': 3,
        'HEADLIGHTS_OFF': 0,
        'HEADLIGHTS_LOW': 1,
        'HEADLIGHTS_HIGH': 2,
        'WIPERS_OFF': 0,
        'WIPERS_LOW': 1,
        'WIPERS_MED': 2,
        'WIPERS_HIGH': 3,
        'GEAR_NEUTRAL': 0,
        'GEAR_DRIVE': 1,
        'GEAR_REVERSE': 2,
        'GEAR_PARKING': 3,
        'GEAR_LOW': 4,
        'VEHICLE_MODE_COMPLETE_MANUAL': 0,
        'VEHICLE_MODE_COMPLETE_AUTO_DRIVE': 1,
        'VEHICLE_MODE_AUTO_STEER_ONLY': 2,
        'VEHICLE_MODE_AUTO_SPEED_ONLY': 3,
        'VEHICLE_MODE_EMERGENCY_MODE': 4,
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
                'lgsvl_msgs.msg.VehicleStateData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vehicle_state_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vehicle_state_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vehicle_state_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vehicle_state_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vehicle_state_data

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'BLINKERS_OFF': cls.__constants['BLINKERS_OFF'],
            'BLINKERS_LEFT': cls.__constants['BLINKERS_LEFT'],
            'BLINKERS_RIGHT': cls.__constants['BLINKERS_RIGHT'],
            'BLINKERS_HAZARD': cls.__constants['BLINKERS_HAZARD'],
            'HEADLIGHTS_OFF': cls.__constants['HEADLIGHTS_OFF'],
            'HEADLIGHTS_LOW': cls.__constants['HEADLIGHTS_LOW'],
            'HEADLIGHTS_HIGH': cls.__constants['HEADLIGHTS_HIGH'],
            'WIPERS_OFF': cls.__constants['WIPERS_OFF'],
            'WIPERS_LOW': cls.__constants['WIPERS_LOW'],
            'WIPERS_MED': cls.__constants['WIPERS_MED'],
            'WIPERS_HIGH': cls.__constants['WIPERS_HIGH'],
            'GEAR_NEUTRAL': cls.__constants['GEAR_NEUTRAL'],
            'GEAR_DRIVE': cls.__constants['GEAR_DRIVE'],
            'GEAR_REVERSE': cls.__constants['GEAR_REVERSE'],
            'GEAR_PARKING': cls.__constants['GEAR_PARKING'],
            'GEAR_LOW': cls.__constants['GEAR_LOW'],
            'VEHICLE_MODE_COMPLETE_MANUAL': cls.__constants['VEHICLE_MODE_COMPLETE_MANUAL'],
            'VEHICLE_MODE_COMPLETE_AUTO_DRIVE': cls.__constants['VEHICLE_MODE_COMPLETE_AUTO_DRIVE'],
            'VEHICLE_MODE_AUTO_STEER_ONLY': cls.__constants['VEHICLE_MODE_AUTO_STEER_ONLY'],
            'VEHICLE_MODE_AUTO_SPEED_ONLY': cls.__constants['VEHICLE_MODE_AUTO_SPEED_ONLY'],
            'VEHICLE_MODE_EMERGENCY_MODE': cls.__constants['VEHICLE_MODE_EMERGENCY_MODE'],
        }

    @property
    def BLINKERS_OFF(self):
        """Message constant 'BLINKERS_OFF'."""
        return Metaclass_VehicleStateData.__constants['BLINKERS_OFF']

    @property
    def BLINKERS_LEFT(self):
        """Message constant 'BLINKERS_LEFT'."""
        return Metaclass_VehicleStateData.__constants['BLINKERS_LEFT']

    @property
    def BLINKERS_RIGHT(self):
        """Message constant 'BLINKERS_RIGHT'."""
        return Metaclass_VehicleStateData.__constants['BLINKERS_RIGHT']

    @property
    def BLINKERS_HAZARD(self):
        """Message constant 'BLINKERS_HAZARD'."""
        return Metaclass_VehicleStateData.__constants['BLINKERS_HAZARD']

    @property
    def HEADLIGHTS_OFF(self):
        """Message constant 'HEADLIGHTS_OFF'."""
        return Metaclass_VehicleStateData.__constants['HEADLIGHTS_OFF']

    @property
    def HEADLIGHTS_LOW(self):
        """Message constant 'HEADLIGHTS_LOW'."""
        return Metaclass_VehicleStateData.__constants['HEADLIGHTS_LOW']

    @property
    def HEADLIGHTS_HIGH(self):
        """Message constant 'HEADLIGHTS_HIGH'."""
        return Metaclass_VehicleStateData.__constants['HEADLIGHTS_HIGH']

    @property
    def WIPERS_OFF(self):
        """Message constant 'WIPERS_OFF'."""
        return Metaclass_VehicleStateData.__constants['WIPERS_OFF']

    @property
    def WIPERS_LOW(self):
        """Message constant 'WIPERS_LOW'."""
        return Metaclass_VehicleStateData.__constants['WIPERS_LOW']

    @property
    def WIPERS_MED(self):
        """Message constant 'WIPERS_MED'."""
        return Metaclass_VehicleStateData.__constants['WIPERS_MED']

    @property
    def WIPERS_HIGH(self):
        """Message constant 'WIPERS_HIGH'."""
        return Metaclass_VehicleStateData.__constants['WIPERS_HIGH']

    @property
    def GEAR_NEUTRAL(self):
        """Message constant 'GEAR_NEUTRAL'."""
        return Metaclass_VehicleStateData.__constants['GEAR_NEUTRAL']

    @property
    def GEAR_DRIVE(self):
        """Message constant 'GEAR_DRIVE'."""
        return Metaclass_VehicleStateData.__constants['GEAR_DRIVE']

    @property
    def GEAR_REVERSE(self):
        """Message constant 'GEAR_REVERSE'."""
        return Metaclass_VehicleStateData.__constants['GEAR_REVERSE']

    @property
    def GEAR_PARKING(self):
        """Message constant 'GEAR_PARKING'."""
        return Metaclass_VehicleStateData.__constants['GEAR_PARKING']

    @property
    def GEAR_LOW(self):
        """Message constant 'GEAR_LOW'."""
        return Metaclass_VehicleStateData.__constants['GEAR_LOW']

    @property
    def VEHICLE_MODE_COMPLETE_MANUAL(self):
        """Message constant 'VEHICLE_MODE_COMPLETE_MANUAL'."""
        return Metaclass_VehicleStateData.__constants['VEHICLE_MODE_COMPLETE_MANUAL']

    @property
    def VEHICLE_MODE_COMPLETE_AUTO_DRIVE(self):
        """Message constant 'VEHICLE_MODE_COMPLETE_AUTO_DRIVE'."""
        return Metaclass_VehicleStateData.__constants['VEHICLE_MODE_COMPLETE_AUTO_DRIVE']

    @property
    def VEHICLE_MODE_AUTO_STEER_ONLY(self):
        """Message constant 'VEHICLE_MODE_AUTO_STEER_ONLY'."""
        return Metaclass_VehicleStateData.__constants['VEHICLE_MODE_AUTO_STEER_ONLY']

    @property
    def VEHICLE_MODE_AUTO_SPEED_ONLY(self):
        """Message constant 'VEHICLE_MODE_AUTO_SPEED_ONLY'."""
        return Metaclass_VehicleStateData.__constants['VEHICLE_MODE_AUTO_SPEED_ONLY']

    @property
    def VEHICLE_MODE_EMERGENCY_MODE(self):
        """Message constant 'VEHICLE_MODE_EMERGENCY_MODE'."""
        return Metaclass_VehicleStateData.__constants['VEHICLE_MODE_EMERGENCY_MODE']


class VehicleStateData(metaclass=Metaclass_VehicleStateData):
    """
    Message class 'VehicleStateData'.

    Constants:
      BLINKERS_OFF
      BLINKERS_LEFT
      BLINKERS_RIGHT
      BLINKERS_HAZARD
      HEADLIGHTS_OFF
      HEADLIGHTS_LOW
      HEADLIGHTS_HIGH
      WIPERS_OFF
      WIPERS_LOW
      WIPERS_MED
      WIPERS_HIGH
      GEAR_NEUTRAL
      GEAR_DRIVE
      GEAR_REVERSE
      GEAR_PARKING
      GEAR_LOW
      VEHICLE_MODE_COMPLETE_MANUAL
      VEHICLE_MODE_COMPLETE_AUTO_DRIVE
      VEHICLE_MODE_AUTO_STEER_ONLY
      VEHICLE_MODE_AUTO_SPEED_ONLY
      VEHICLE_MODE_EMERGENCY_MODE
    """

    __slots__ = [
        '_header',
        '_blinker_state',
        '_headlight_state',
        '_wiper_state',
        '_current_gear',
        '_vehicle_mode',
        '_hand_brake_active',
        '_horn_active',
        '_autonomous_mode_active',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'blinker_state': 'uint8',
        'headlight_state': 'uint8',
        'wiper_state': 'uint8',
        'current_gear': 'uint8',
        'vehicle_mode': 'uint8',
        'hand_brake_active': 'boolean',
        'horn_active': 'boolean',
        'autonomous_mode_active': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.blinker_state = kwargs.get('blinker_state', int())
        self.headlight_state = kwargs.get('headlight_state', int())
        self.wiper_state = kwargs.get('wiper_state', int())
        self.current_gear = kwargs.get('current_gear', int())
        self.vehicle_mode = kwargs.get('vehicle_mode', int())
        self.hand_brake_active = kwargs.get('hand_brake_active', bool())
        self.horn_active = kwargs.get('horn_active', bool())
        self.autonomous_mode_active = kwargs.get('autonomous_mode_active', bool())

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
        if self.blinker_state != other.blinker_state:
            return False
        if self.headlight_state != other.headlight_state:
            return False
        if self.wiper_state != other.wiper_state:
            return False
        if self.current_gear != other.current_gear:
            return False
        if self.vehicle_mode != other.vehicle_mode:
            return False
        if self.hand_brake_active != other.hand_brake_active:
            return False
        if self.horn_active != other.horn_active:
            return False
        if self.autonomous_mode_active != other.autonomous_mode_active:
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
    def blinker_state(self):
        """Message field 'blinker_state'."""
        return self._blinker_state

    @blinker_state.setter
    def blinker_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'blinker_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'blinker_state' field must be an unsigned integer in [0, 255]"
        self._blinker_state = value

    @property
    def headlight_state(self):
        """Message field 'headlight_state'."""
        return self._headlight_state

    @headlight_state.setter
    def headlight_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'headlight_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'headlight_state' field must be an unsigned integer in [0, 255]"
        self._headlight_state = value

    @property
    def wiper_state(self):
        """Message field 'wiper_state'."""
        return self._wiper_state

    @wiper_state.setter
    def wiper_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'wiper_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'wiper_state' field must be an unsigned integer in [0, 255]"
        self._wiper_state = value

    @property
    def current_gear(self):
        """Message field 'current_gear'."""
        return self._current_gear

    @current_gear.setter
    def current_gear(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_gear' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'current_gear' field must be an unsigned integer in [0, 255]"
        self._current_gear = value

    @property
    def vehicle_mode(self):
        """Message field 'vehicle_mode'."""
        return self._vehicle_mode

    @vehicle_mode.setter
    def vehicle_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vehicle_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'vehicle_mode' field must be an unsigned integer in [0, 255]"
        self._vehicle_mode = value

    @property
    def hand_brake_active(self):
        """Message field 'hand_brake_active'."""
        return self._hand_brake_active

    @hand_brake_active.setter
    def hand_brake_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hand_brake_active' field must be of type 'bool'"
        self._hand_brake_active = value

    @property
    def horn_active(self):
        """Message field 'horn_active'."""
        return self._horn_active

    @horn_active.setter
    def horn_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'horn_active' field must be of type 'bool'"
        self._horn_active = value

    @property
    def autonomous_mode_active(self):
        """Message field 'autonomous_mode_active'."""
        return self._autonomous_mode_active

    @autonomous_mode_active.setter
    def autonomous_mode_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'autonomous_mode_active' field must be of type 'bool'"
        self._autonomous_mode_active = value
