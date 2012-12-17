"""autogenerated by genpy from hubo_ros_msgs/HuboHandCommand.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class HuboHandCommand(genpy.Message):
  _md5sum = "866b2feb73aeeddf8529bc2bbe447b0d"
  _type = "hubo_ros_msgs/HuboHandCommand"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float64 thumb
float64 index
float64 middle
float64 ring
float64 pinky

"""
  __slots__ = ['thumb','index','middle','ring','pinky']
  _slot_types = ['float64','float64','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       thumb,index,middle,ring,pinky

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(HuboHandCommand, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.thumb is None:
        self.thumb = 0.
      if self.index is None:
        self.index = 0.
      if self.middle is None:
        self.middle = 0.
      if self.ring is None:
        self.ring = 0.
      if self.pinky is None:
        self.pinky = 0.
    else:
      self.thumb = 0.
      self.index = 0.
      self.middle = 0.
      self.ring = 0.
      self.pinky = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_5d.pack(_x.thumb, _x.index, _x.middle, _x.ring, _x.pinky))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 40
      (_x.thumb, _x.index, _x.middle, _x.ring, _x.pinky,) = _struct_5d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_5d.pack(_x.thumb, _x.index, _x.middle, _x.ring, _x.pinky))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 40
      (_x.thumb, _x.index, _x.middle, _x.ring, _x.pinky,) = _struct_5d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_5d = struct.Struct("<5d")
