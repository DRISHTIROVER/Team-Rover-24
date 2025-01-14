// Auto-generated. Do not edit!

// (in-package custom_msg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ultrasonic_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.r1 = null;
      this.r2 = null;
      this.r3 = null;
      this.r4 = null;
      this.r5 = null;
    }
    else {
      if (initObj.hasOwnProperty('r1')) {
        this.r1 = initObj.r1
      }
      else {
        this.r1 = 0.0;
      }
      if (initObj.hasOwnProperty('r2')) {
        this.r2 = initObj.r2
      }
      else {
        this.r2 = 0.0;
      }
      if (initObj.hasOwnProperty('r3')) {
        this.r3 = initObj.r3
      }
      else {
        this.r3 = 0.0;
      }
      if (initObj.hasOwnProperty('r4')) {
        this.r4 = initObj.r4
      }
      else {
        this.r4 = 0.0;
      }
      if (initObj.hasOwnProperty('r5')) {
        this.r5 = initObj.r5
      }
      else {
        this.r5 = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ultrasonic_msg
    // Serialize message field [r1]
    bufferOffset = _serializer.float32(obj.r1, buffer, bufferOffset);
    // Serialize message field [r2]
    bufferOffset = _serializer.float32(obj.r2, buffer, bufferOffset);
    // Serialize message field [r3]
    bufferOffset = _serializer.float32(obj.r3, buffer, bufferOffset);
    // Serialize message field [r4]
    bufferOffset = _serializer.float32(obj.r4, buffer, bufferOffset);
    // Serialize message field [r5]
    bufferOffset = _serializer.float32(obj.r5, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ultrasonic_msg
    let len;
    let data = new ultrasonic_msg(null);
    // Deserialize message field [r1]
    data.r1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [r2]
    data.r2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [r3]
    data.r3 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [r4]
    data.r4 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [r5]
    data.r5 = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msg/ultrasonic_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e6539a993ae760db074e494e04960752';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 r1
    float32 r2
    float32 r3
    float32 r4
    float32 r5
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ultrasonic_msg(null);
    if (msg.r1 !== undefined) {
      resolved.r1 = msg.r1;
    }
    else {
      resolved.r1 = 0.0
    }

    if (msg.r2 !== undefined) {
      resolved.r2 = msg.r2;
    }
    else {
      resolved.r2 = 0.0
    }

    if (msg.r3 !== undefined) {
      resolved.r3 = msg.r3;
    }
    else {
      resolved.r3 = 0.0
    }

    if (msg.r4 !== undefined) {
      resolved.r4 = msg.r4;
    }
    else {
      resolved.r4 = 0.0
    }

    if (msg.r5 !== undefined) {
      resolved.r5 = msg.r5;
    }
    else {
      resolved.r5 = 0.0
    }

    return resolved;
    }
};

module.exports = ultrasonic_msg;
