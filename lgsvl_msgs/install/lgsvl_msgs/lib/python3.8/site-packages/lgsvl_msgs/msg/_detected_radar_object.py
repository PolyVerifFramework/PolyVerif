# generated from rosidl_generator_py/resource/_idl.py.em
# with input from lgsvl_msgs:msg/DetectedRadarObject.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectedRadarObject(type):
    """Metaclass of message 'DetectedRadarObject'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'STATE_MOVING': 0,
        'STATE_STATIONARY': 1,
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
                'lgsvl_msgs.msg.DetectedRadarObject')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__detected_radar_object
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__detected_radar_object
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__detected_radar_object
            cls._TYPE_SUPPORT = module.type_support_msg__msg__detected_radar_object
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__detected_radar_object

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'STATE_MOVING': cls.__constants['STATE_MOVING'],
            'STATE_STATIONARY': cls.__constants['STATE_STATIONARY'],
        }

    @property
    def STATE_MOVING(self):
        """Message constant 'STATE_MOVING'."""
        return Metaclass_DetectedRadarObject.__constants['STATE_MOVING']

    @property
    def STATE_STATIONARY(self):
        """Message constant 'STATE_STATIONARY'."""
        return Metaclass_DetectedRadarObject.__constants['STATE_STATIONARY']


class DetectedRadarObject(metaclass=Metaclass_DetectedRadarObject):
    """
    Message class 'DetectedRadarObject'.

    Constants:
      STATE_MOVING
      STATE_STATIONARY
    """

    __slots__ = [
        '_id',
        '_sensor_aim',
        '_sensor_right',
        '_sensor_position',
        '_sensor_velocity',
        '_sensor_angle',
        '_object_position',
        '_object_velocity',
        '_object_relative_position',
        '_object_relative_velocity',
        '_object_collider_size',
        '_object_state',
        '_new_detection',
    ]

    _fields_and_field_types = {
        'id': 'int32',
        'sensor_aim': 'geometry_msgs/Vector3',
        'sensor_right': 'geometry_msgs/Vector3',
        'sensor_position': 'geometry_msgs/Point',
        'sensor_velocity': 'geometry_msgs/Vector3',
        'sensor_angle': 'double',
        'object_position': 'geometry_msgs/Point',
        'object_velocity': 'geometry_msgs/Vector3',
        'object_relative_position': 'geometry_msgs/Point',
        'object_relative_velocity': 'geometry_msgs/Vector3',
        'object_collider_size': 'geometry_msgs/Vector3',
        'object_state': 'uint8',
        'new_detection': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        from geometry_msgs.msg import Vector3
        self.sensor_aim = kwargs.get('sensor_aim', Vector3())
        from geometry_msgs.msg import Vector3
        self.sensor_right = kwargs.get('sensor_right', Vector3())
        from geometry_msgs.msg import Point
        self.sensor_position = kwargs.get('sensor_position', Point())
        from geometry_msgs.msg import Vector3
        self.sensor_velocity = kwargs.get('sensor_velocity', Vector3())
        self.sensor_angle = kwargs.get('sensor_angle', float())
        from geometry_msgs.msg import Point
        self.object_position = kwargs.get('object_position', Point())
        from geometry_msgs.msg import Vector3
        self.object_velocity = kwargs.get('object_velocity', Vector3())
        from geometry_msgs.msg import Point
        self.object_relative_position = kwargs.get('object_relative_position', Point())
        from geometry_msgs.msg import Vector3
        self.object_relative_velocity = kwargs.get('object_relative_velocity', Vector3())
        from geometry_msgs.msg import Vector3
        self.object_collider_size = kwargs.get('object_collider_size', Vector3())
        self.object_state = kwargs.get('object_state', int())
        self.new_detection = kwargs.get('new_detection', bool())

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
        if self.id != other.id:
            return False
        if self.sensor_aim != other.sensor_aim:
            return False
        if self.sensor_right != other.sensor_right:
            return False
        if self.sensor_position != other.sensor_position:
            return False
        if self.sensor_velocity != other.sensor_velocity:
            return False
        if self.sensor_angle != other.sensor_angle:
            return False
        if self.object_position != other.object_position:
            return False
        if self.object_velocity != other.object_velocity:
            return False
        if self.object_relative_position != other.object_relative_position:
            return False
        if self.object_relative_velocity != other.object_relative_velocity:
            return False
        if self.object_collider_size != other.object_collider_size:
            return False
        if self.object_state != other.object_state:
            return False
        if self.new_detection != other.new_detection:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'id' field must be an integer in [-2147483648, 2147483647]"
        self._id = value

    @property
    def sensor_aim(self):
        """Message field 'sensor_aim'."""
        return self._sensor_aim

    @sensor_aim.setter
    def sensor_aim(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'sensor_aim' field must be a sub message of type 'Vector3'"
        self._sensor_aim = value

    @property
    def sensor_right(self):
        """Message field 'sensor_right'."""
        return self._sensor_right

    @sensor_right.setter
    def sensor_right(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'sensor_right' field must be a sub message of type 'Vector3'"
        self._sensor_right = value

    @property
    def sensor_position(self):
        """Message field 'sensor_position'."""
        return self._sensor_position

    @sensor_position.setter
    def sensor_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'sensor_position' field must be a sub message of type 'Point'"
        self._sensor_position = value

    @property
    def sensor_velocity(self):
        """Message field 'sensor_velocity'."""
        return self._sensor_velocity

    @sensor_velocity.setter
    def sensor_velocity(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'sensor_velocity' field must be a sub message of type 'Vector3'"
        self._sensor_velocity = value

    @property
    def sensor_angle(self):
        """Message field 'sensor_angle'."""
        return self._sensor_angle

    @sensor_angle.setter
    def sensor_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'sensor_angle' field must be of type 'float'"
        self._sensor_angle = value

    @property
    def object_position(self):
        """Message field 'object_position'."""
        return self._object_position

    @object_position.setter
    def object_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'object_position' field must be a sub message of type 'Point'"
        self._object_position = value

    @property
    def object_velocity(self):
        """Message field 'object_velocity'."""
        return self._object_velocity

    @object_velocity.setter
    def object_velocity(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'object_velocity' field must be a sub message of type 'Vector3'"
        self._object_velocity = value

    @property
    def object_relative_position(self):
        """Message field 'object_relative_position'."""
        return self._object_relative_position

    @object_relative_position.setter
    def object_relative_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'object_relative_position' field must be a sub message of type 'Point'"
        self._object_relative_position = value

    @property
    def object_relative_velocity(self):
        """Message field 'object_relative_velocity'."""
        return self._object_relative_velocity

    @object_relative_velocity.setter
    def object_relative_velocity(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'object_relative_velocity' field must be a sub message of type 'Vector3'"
        self._object_relative_velocity = value

    @property
    def object_collider_size(self):
        """Message field 'object_collider_size'."""
        return self._object_collider_size

    @object_collider_size.setter
    def object_collider_size(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'object_collider_size' field must be a sub message of type 'Vector3'"
        self._object_collider_size = value

    @property
    def object_state(self):
        """Message field 'object_state'."""
        return self._object_state

    @object_state.setter
    def object_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'object_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'object_state' field must be an unsigned integer in [0, 255]"
        self._object_state = value

    @property
    def new_detection(self):
        """Message field 'new_detection'."""
        return self._new_detection

    @new_detection.setter
    def new_detection(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'new_detection' field must be of type 'bool'"
        self._new_detection = value
