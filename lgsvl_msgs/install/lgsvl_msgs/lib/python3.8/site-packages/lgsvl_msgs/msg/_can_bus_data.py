# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lgsvl_msgs:msg/CanBusData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CanBusData(type):
    """Metaclass of message 'CanBusData'."""

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
                'lgsvl_msgs.msg.CanBusData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__can_bus_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__can_bus_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__can_bus_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__can_bus_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__can_bus_data

            from geometry_msgs.msg import Quaternion
            if Quaternion.__class__._TYPE_SUPPORT is None:
                Quaternion.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

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
        return Metaclass_CanBusData.__constants['GEAR_NEUTRAL']

    @property
    def GEAR_DRIVE(self):
        """Message constant 'GEAR_DRIVE'."""
        return Metaclass_CanBusData.__constants['GEAR_DRIVE']

    @property
    def GEAR_REVERSE(self):
        """Message constant 'GEAR_REVERSE'."""
        return Metaclass_CanBusData.__constants['GEAR_REVERSE']

    @property
    def GEAR_PARKING(self):
        """Message constant 'GEAR_PARKING'."""
        return Metaclass_CanBusData.__constants['GEAR_PARKING']

    @property
    def GEAR_LOW(self):
        """Message constant 'GEAR_LOW'."""
        return Metaclass_CanBusData.__constants['GEAR_LOW']


class CanBusData(metaclass=Metaclass_CanBusData):
    """
    Message class 'CanBusData'.

    Constants:
      GEAR_NEUTRAL
      GEAR_DRIVE
      GEAR_REVERSE
      GEAR_PARKING
      GEAR_LOW
    """

    __slots__ = [
        '_header',
        '_speed_mps',
        '_throttle_pct',
        '_brake_pct',
        '_steer_pct',
        '_parking_brake_active',
        '_high_beams_active',
        '_low_beams_active',
        '_hazard_lights_active',
        '_fog_lights_active',
        '_left_turn_signal_active',
        '_right_turn_signal_active',
        '_wipers_active',
        '_reverse_gear_active',
        '_selected_gear',
        '_engine_active',
        '_engine_rpm',
        '_gps_latitude',
        '_gps_longitude',
        '_gps_altitude',
        '_orientation',
        '_linear_velocities',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'speed_mps': 'float',
        'throttle_pct': 'float',
        'brake_pct': 'float',
        'steer_pct': 'float',
        'parking_brake_active': 'boolean',
        'high_beams_active': 'boolean',
        'low_beams_active': 'boolean',
        'hazard_lights_active': 'boolean',
        'fog_lights_active': 'boolean',
        'left_turn_signal_active': 'boolean',
        'right_turn_signal_active': 'boolean',
        'wipers_active': 'boolean',
        'reverse_gear_active': 'boolean',
        'selected_gear': 'int8',
        'engine_active': 'boolean',
        'engine_rpm': 'float',
        'gps_latitude': 'double',
        'gps_longitude': 'double',
        'gps_altitude': 'double',
        'orientation': 'geometry_msgs/Quaternion',
        'linear_velocities': 'geometry_msgs/Vector3',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Quaternion'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.speed_mps = kwargs.get('speed_mps', float())
        self.throttle_pct = kwargs.get('throttle_pct', float())
        self.brake_pct = kwargs.get('brake_pct', float())
        self.steer_pct = kwargs.get('steer_pct', float())
        self.parking_brake_active = kwargs.get('parking_brake_active', bool())
        self.high_beams_active = kwargs.get('high_beams_active', bool())
        self.low_beams_active = kwargs.get('low_beams_active', bool())
        self.hazard_lights_active = kwargs.get('hazard_lights_active', bool())
        self.fog_lights_active = kwargs.get('fog_lights_active', bool())
        self.left_turn_signal_active = kwargs.get('left_turn_signal_active', bool())
        self.right_turn_signal_active = kwargs.get('right_turn_signal_active', bool())
        self.wipers_active = kwargs.get('wipers_active', bool())
        self.reverse_gear_active = kwargs.get('reverse_gear_active', bool())
        self.selected_gear = kwargs.get('selected_gear', int())
        self.engine_active = kwargs.get('engine_active', bool())
        self.engine_rpm = kwargs.get('engine_rpm', float())
        self.gps_latitude = kwargs.get('gps_latitude', float())
        self.gps_longitude = kwargs.get('gps_longitude', float())
        self.gps_altitude = kwargs.get('gps_altitude', float())
        from geometry_msgs.msg import Quaternion
        self.orientation = kwargs.get('orientation', Quaternion())
        from geometry_msgs.msg import Vector3
        self.linear_velocities = kwargs.get('linear_velocities', Vector3())

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
        if self.speed_mps != other.speed_mps:
            return False
        if self.throttle_pct != other.throttle_pct:
            return False
        if self.brake_pct != other.brake_pct:
            return False
        if self.steer_pct != other.steer_pct:
            return False
        if self.parking_brake_active != other.parking_brake_active:
            return False
        if self.high_beams_active != other.high_beams_active:
            return False
        if self.low_beams_active != other.low_beams_active:
            return False
        if self.hazard_lights_active != other.hazard_lights_active:
            return False
        if self.fog_lights_active != other.fog_lights_active:
            return False
        if self.left_turn_signal_active != other.left_turn_signal_active:
            return False
        if self.right_turn_signal_active != other.right_turn_signal_active:
            return False
        if self.wipers_active != other.wipers_active:
            return False
        if self.reverse_gear_active != other.reverse_gear_active:
            return False
        if self.selected_gear != other.selected_gear:
            return False
        if self.engine_active != other.engine_active:
            return False
        if self.engine_rpm != other.engine_rpm:
            return False
        if self.gps_latitude != other.gps_latitude:
            return False
        if self.gps_longitude != other.gps_longitude:
            return False
        if self.gps_altitude != other.gps_altitude:
            return False
        if self.orientation != other.orientation:
            return False
        if self.linear_velocities != other.linear_velocities:
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
    def speed_mps(self):
        """Message field 'speed_mps'."""
        return self._speed_mps

    @speed_mps.setter
    def speed_mps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed_mps' field must be of type 'float'"
        self._speed_mps = value

    @property
    def throttle_pct(self):
        """Message field 'throttle_pct'."""
        return self._throttle_pct

    @throttle_pct.setter
    def throttle_pct(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'throttle_pct' field must be of type 'float'"
        self._throttle_pct = value

    @property
    def brake_pct(self):
        """Message field 'brake_pct'."""
        return self._brake_pct

    @brake_pct.setter
    def brake_pct(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'brake_pct' field must be of type 'float'"
        self._brake_pct = value

    @property
    def steer_pct(self):
        """Message field 'steer_pct'."""
        return self._steer_pct

    @steer_pct.setter
    def steer_pct(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'steer_pct' field must be of type 'float'"
        self._steer_pct = value

    @property
    def parking_brake_active(self):
        """Message field 'parking_brake_active'."""
        return self._parking_brake_active

    @parking_brake_active.setter
    def parking_brake_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'parking_brake_active' field must be of type 'bool'"
        self._parking_brake_active = value

    @property
    def high_beams_active(self):
        """Message field 'high_beams_active'."""
        return self._high_beams_active

    @high_beams_active.setter
    def high_beams_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'high_beams_active' field must be of type 'bool'"
        self._high_beams_active = value

    @property
    def low_beams_active(self):
        """Message field 'low_beams_active'."""
        return self._low_beams_active

    @low_beams_active.setter
    def low_beams_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'low_beams_active' field must be of type 'bool'"
        self._low_beams_active = value

    @property
    def hazard_lights_active(self):
        """Message field 'hazard_lights_active'."""
        return self._hazard_lights_active

    @hazard_lights_active.setter
    def hazard_lights_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'hazard_lights_active' field must be of type 'bool'"
        self._hazard_lights_active = value

    @property
    def fog_lights_active(self):
        """Message field 'fog_lights_active'."""
        return self._fog_lights_active

    @fog_lights_active.setter
    def fog_lights_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'fog_lights_active' field must be of type 'bool'"
        self._fog_lights_active = value

    @property
    def left_turn_signal_active(self):
        """Message field 'left_turn_signal_active'."""
        return self._left_turn_signal_active

    @left_turn_signal_active.setter
    def left_turn_signal_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'left_turn_signal_active' field must be of type 'bool'"
        self._left_turn_signal_active = value

    @property
    def right_turn_signal_active(self):
        """Message field 'right_turn_signal_active'."""
        return self._right_turn_signal_active

    @right_turn_signal_active.setter
    def right_turn_signal_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'right_turn_signal_active' field must be of type 'bool'"
        self._right_turn_signal_active = value

    @property
    def wipers_active(self):
        """Message field 'wipers_active'."""
        return self._wipers_active

    @wipers_active.setter
    def wipers_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'wipers_active' field must be of type 'bool'"
        self._wipers_active = value

    @property
    def reverse_gear_active(self):
        """Message field 'reverse_gear_active'."""
        return self._reverse_gear_active

    @reverse_gear_active.setter
    def reverse_gear_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'reverse_gear_active' field must be of type 'bool'"
        self._reverse_gear_active = value

    @property
    def selected_gear(self):
        """Message field 'selected_gear'."""
        return self._selected_gear

    @selected_gear.setter
    def selected_gear(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'selected_gear' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'selected_gear' field must be an integer in [-128, 127]"
        self._selected_gear = value

    @property
    def engine_active(self):
        """Message field 'engine_active'."""
        return self._engine_active

    @engine_active.setter
    def engine_active(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'engine_active' field must be of type 'bool'"
        self._engine_active = value

    @property
    def engine_rpm(self):
        """Message field 'engine_rpm'."""
        return self._engine_rpm

    @engine_rpm.setter
    def engine_rpm(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'engine_rpm' field must be of type 'float'"
        self._engine_rpm = value

    @property
    def gps_latitude(self):
        """Message field 'gps_latitude'."""
        return self._gps_latitude

    @gps_latitude.setter
    def gps_latitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gps_latitude' field must be of type 'float'"
        self._gps_latitude = value

    @property
    def gps_longitude(self):
        """Message field 'gps_longitude'."""
        return self._gps_longitude

    @gps_longitude.setter
    def gps_longitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gps_longitude' field must be of type 'float'"
        self._gps_longitude = value

    @property
    def gps_altitude(self):
        """Message field 'gps_altitude'."""
        return self._gps_altitude

    @gps_altitude.setter
    def gps_altitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gps_altitude' field must be of type 'float'"
        self._gps_altitude = value

    @property
    def orientation(self):
        """Message field 'orientation'."""
        return self._orientation

    @orientation.setter
    def orientation(self, value):
        if __debug__:
            from geometry_msgs.msg import Quaternion
            assert \
                isinstance(value, Quaternion), \
                "The 'orientation' field must be a sub message of type 'Quaternion'"
        self._orientation = value

    @property
    def linear_velocities(self):
        """Message field 'linear_velocities'."""
        return self._linear_velocities

    @linear_velocities.setter
    def linear_velocities(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'linear_velocities' field must be a sub message of type 'Vector3'"
        self._linear_velocities = value
