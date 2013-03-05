"""autogenerated by genpy from hubo_ros/HuboHand.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import hubo_ros.msg

class HuboHand(genpy.Message):
  _md5sum = "dfd31cdc3f67d0c6f51804ccff860aaf"
  _type = "hubo_ros/HuboHand"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """HuboJointState thumb
HuboJointState index
HuboJointState middle
HuboJointState ring
HuboJointState pinky

================================================================================
MSG: hubo_ros/HuboJointState
string name
float64 commanded
float64 position
float64 velocity
float64 current
float64 temperature
int32 active
int32 zeroed

"""
  __slots__ = ['thumb','index','middle','ring','pinky']
  _slot_types = ['hubo_ros/HuboJointState','hubo_ros/HuboJointState','hubo_ros/HuboJointState','hubo_ros/HuboJointState','hubo_ros/HuboJointState']

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
      super(HuboHand, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.thumb is None:
        self.thumb = hubo_ros.msg.HuboJointState()
      if self.index is None:
        self.index = hubo_ros.msg.HuboJointState()
      if self.middle is None:
        self.middle = hubo_ros.msg.HuboJointState()
      if self.ring is None:
        self.ring = hubo_ros.msg.HuboJointState()
      if self.pinky is None:
        self.pinky = hubo_ros.msg.HuboJointState()
    else:
      self.thumb = hubo_ros.msg.HuboJointState()
      self.index = hubo_ros.msg.HuboJointState()
      self.middle = hubo_ros.msg.HuboJointState()
      self.ring = hubo_ros.msg.HuboJointState()
      self.pinky = hubo_ros.msg.HuboJointState()

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
      _x = self.thumb.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_5d2i.pack(_x.thumb.commanded, _x.thumb.position, _x.thumb.velocity, _x.thumb.current, _x.thumb.temperature, _x.thumb.active, _x.thumb.zeroed))
      _x = self.index.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_5d2i.pack(_x.index.commanded, _x.index.position, _x.index.velocity, _x.index.current, _x.index.temperature, _x.index.active, _x.index.zeroed))
      _x = self.middle.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_5d2i.pack(_x.middle.commanded, _x.middle.position, _x.middle.velocity, _x.middle.current, _x.middle.temperature, _x.middle.active, _x.middle.zeroed))
      _x = self.ring.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_5d2i.pack(_x.ring.commanded, _x.ring.position, _x.ring.velocity, _x.ring.current, _x.ring.temperature, _x.ring.active, _x.ring.zeroed))
      _x = self.pinky.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_5d2i.pack(_x.pinky.commanded, _x.pinky.position, _x.pinky.velocity, _x.pinky.current, _x.pinky.temperature, _x.pinky.active, _x.pinky.zeroed))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.thumb is None:
        self.thumb = hubo_ros.msg.HuboJointState()
      if self.index is None:
        self.index = hubo_ros.msg.HuboJointState()
      if self.middle is None:
        self.middle = hubo_ros.msg.HuboJointState()
      if self.ring is None:
        self.ring = hubo_ros.msg.HuboJointState()
      if self.pinky is None:
        self.pinky = hubo_ros.msg.HuboJointState()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.thumb.name = str[start:end].decode('utf-8')
      else:
        self.thumb.name = str[start:end]
      _x = self
      start = end
      end += 48
      (_x.thumb.commanded, _x.thumb.position, _x.thumb.velocity, _x.thumb.current, _x.thumb.temperature, _x.thumb.active, _x.thumb.zeroed,) = _struct_5d2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.index.name = str[start:end].decode('utf-8')
      else:
        self.index.name = str[start:end]
      _x = self
      start = end
      end += 48
      (_x.index.commanded, _x.index.position, _x.index.velocity, _x.index.current, _x.index.temperature, _x.index.active, _x.index.zeroed,) = _struct_5d2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.middle.name = str[start:end].decode('utf-8')
      else:
        self.middle.name = str[start:end]
      _x = self
      start = end
      end += 48
      (_x.middle.commanded, _x.middle.position, _x.middle.velocity, _x.middle.current, _x.middle.temperature, _x.middle.active, _x.middle.zeroed,) = _struct_5d2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.ring.name = str[start:end].decode('utf-8')
      else:
        self.ring.name = str[start:end]
      _x = self
      start = end
      end += 48
      (_x.ring.commanded, _x.ring.position, _x.ring.velocity, _x.ring.current, _x.ring.temperature, _x.ring.active, _x.ring.zeroed,) = _struct_5d2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.pinky.name = str[start:end].decode('utf-8')
      else:
        self.pinky.name = str[start:end]
      _x = self
      start = end
      end += 48
      (_x.pinky.commanded, _x.pinky.position, _x.pinky.velocity, _x.pinky.current, _x.pinky.temperature, _x.pinky.active, _x.pinky.zeroed,) = _struct_5d2i.unpack(str[start:end])
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
      _x = self.thumb.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_5d2i.pack(_x.thumb.commanded, _x.thumb.position, _x.thumb.velocity, _x.thumb.current, _x.thumb.temperature, _x.thumb.active, _x.thumb.zeroed))
      _x = self.index.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_5d2i.pack(_x.index.commanded, _x.index.position, _x.index.velocity, _x.index.current, _x.index.temperature, _x.index.active, _x.index.zeroed))
      _x = self.middle.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_5d2i.pack(_x.middle.commanded, _x.middle.position, _x.middle.velocity, _x.middle.current, _x.middle.temperature, _x.middle.active, _x.middle.zeroed))
      _x = self.ring.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_5d2i.pack(_x.ring.commanded, _x.ring.position, _x.ring.velocity, _x.ring.current, _x.ring.temperature, _x.ring.active, _x.ring.zeroed))
      _x = self.pinky.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_5d2i.pack(_x.pinky.commanded, _x.pinky.position, _x.pinky.velocity, _x.pinky.current, _x.pinky.temperature, _x.pinky.active, _x.pinky.zeroed))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.thumb is None:
        self.thumb = hubo_ros.msg.HuboJointState()
      if self.index is None:
        self.index = hubo_ros.msg.HuboJointState()
      if self.middle is None:
        self.middle = hubo_ros.msg.HuboJointState()
      if self.ring is None:
        self.ring = hubo_ros.msg.HuboJointState()
      if self.pinky is None:
        self.pinky = hubo_ros.msg.HuboJointState()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.thumb.name = str[start:end].decode('utf-8')
      else:
        self.thumb.name = str[start:end]
      _x = self
      start = end
      end += 48
      (_x.thumb.commanded, _x.thumb.position, _x.thumb.velocity, _x.thumb.current, _x.thumb.temperature, _x.thumb.active, _x.thumb.zeroed,) = _struct_5d2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.index.name = str[start:end].decode('utf-8')
      else:
        self.index.name = str[start:end]
      _x = self
      start = end
      end += 48
      (_x.index.commanded, _x.index.position, _x.index.velocity, _x.index.current, _x.index.temperature, _x.index.active, _x.index.zeroed,) = _struct_5d2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.middle.name = str[start:end].decode('utf-8')
      else:
        self.middle.name = str[start:end]
      _x = self
      start = end
      end += 48
      (_x.middle.commanded, _x.middle.position, _x.middle.velocity, _x.middle.current, _x.middle.temperature, _x.middle.active, _x.middle.zeroed,) = _struct_5d2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.ring.name = str[start:end].decode('utf-8')
      else:
        self.ring.name = str[start:end]
      _x = self
      start = end
      end += 48
      (_x.ring.commanded, _x.ring.position, _x.ring.velocity, _x.ring.current, _x.ring.temperature, _x.ring.active, _x.ring.zeroed,) = _struct_5d2i.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.pinky.name = str[start:end].decode('utf-8')
      else:
        self.pinky.name = str[start:end]
      _x = self
      start = end
      end += 48
      (_x.pinky.commanded, _x.pinky.position, _x.pinky.velocity, _x.pinky.current, _x.pinky.temperature, _x.pinky.active, _x.pinky.zeroed,) = _struct_5d2i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_5d2i = struct.Struct("<5d2i")