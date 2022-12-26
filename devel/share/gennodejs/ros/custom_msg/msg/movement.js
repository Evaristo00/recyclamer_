// Auto-generated. Do not edit!

// (in-package custom_msg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class movement {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.angle = null;
      this.distance = null;
    }
    else {
      if (initObj.hasOwnProperty('angle')) {
        this.angle = initObj.angle
      }
      else {
        this.angle = new std_msgs.msg.Float64();
      }
      if (initObj.hasOwnProperty('distance')) {
        this.distance = initObj.distance
      }
      else {
        this.distance = new std_msgs.msg.Float64();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type movement
    // Serialize message field [angle]
    bufferOffset = std_msgs.msg.Float64.serialize(obj.angle, buffer, bufferOffset);
    // Serialize message field [distance]
    bufferOffset = std_msgs.msg.Float64.serialize(obj.distance, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type movement
    let len;
    let data = new movement(null);
    // Deserialize message field [angle]
    data.angle = std_msgs.msg.Float64.deserialize(buffer, bufferOffset);
    // Deserialize message field [distance]
    data.distance = std_msgs.msg.Float64.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msg/movement';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8d9d131ce4cf4580f59de99ac7adc6df';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #Header header
    std_msgs/Float64 angle
    std_msgs/Float64 distance
    
    
    
    ================================================================================
    MSG: std_msgs/Float64
    float64 data
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new movement(null);
    if (msg.angle !== undefined) {
      resolved.angle = std_msgs.msg.Float64.Resolve(msg.angle)
    }
    else {
      resolved.angle = new std_msgs.msg.Float64()
    }

    if (msg.distance !== undefined) {
      resolved.distance = std_msgs.msg.Float64.Resolve(msg.distance)
    }
    else {
      resolved.distance = new std_msgs.msg.Float64()
    }

    return resolved;
    }
};

module.exports = movement;
