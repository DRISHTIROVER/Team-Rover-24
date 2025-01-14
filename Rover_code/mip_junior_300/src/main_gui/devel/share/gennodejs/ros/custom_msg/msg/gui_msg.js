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

class gui_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.flag_ob_avoid_or_g2g = null;
      this.goal_no = null;
      this.distance = null;
      this.location_x = null;
      this.location_y = null;
    }
    else {
      if (initObj.hasOwnProperty('flag_ob_avoid_or_g2g')) {
        this.flag_ob_avoid_or_g2g = initObj.flag_ob_avoid_or_g2g
      }
      else {
        this.flag_ob_avoid_or_g2g = 0;
      }
      if (initObj.hasOwnProperty('goal_no')) {
        this.goal_no = initObj.goal_no
      }
      else {
        this.goal_no = 0;
      }
      if (initObj.hasOwnProperty('distance')) {
        this.distance = initObj.distance
      }
      else {
        this.distance = 0.0;
      }
      if (initObj.hasOwnProperty('location_x')) {
        this.location_x = initObj.location_x
      }
      else {
        this.location_x = 0.0;
      }
      if (initObj.hasOwnProperty('location_y')) {
        this.location_y = initObj.location_y
      }
      else {
        this.location_y = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type gui_msg
    // Serialize message field [flag_ob_avoid_or_g2g]
    bufferOffset = _serializer.int32(obj.flag_ob_avoid_or_g2g, buffer, bufferOffset);
    // Serialize message field [goal_no]
    bufferOffset = _serializer.int32(obj.goal_no, buffer, bufferOffset);
    // Serialize message field [distance]
    bufferOffset = _serializer.float64(obj.distance, buffer, bufferOffset);
    // Serialize message field [location_x]
    bufferOffset = _serializer.float64(obj.location_x, buffer, bufferOffset);
    // Serialize message field [location_y]
    bufferOffset = _serializer.float64(obj.location_y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type gui_msg
    let len;
    let data = new gui_msg(null);
    // Deserialize message field [flag_ob_avoid_or_g2g]
    data.flag_ob_avoid_or_g2g = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [goal_no]
    data.goal_no = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [distance]
    data.distance = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [location_x]
    data.location_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [location_y]
    data.location_y = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msg/gui_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fcfe2d5e2cb7ff83917cfec5609b532b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 flag_ob_avoid_or_g2g 
    int32 goal_no
    float64 distance
    float64 location_x
    float64 location_y
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new gui_msg(null);
    if (msg.flag_ob_avoid_or_g2g !== undefined) {
      resolved.flag_ob_avoid_or_g2g = msg.flag_ob_avoid_or_g2g;
    }
    else {
      resolved.flag_ob_avoid_or_g2g = 0
    }

    if (msg.goal_no !== undefined) {
      resolved.goal_no = msg.goal_no;
    }
    else {
      resolved.goal_no = 0
    }

    if (msg.distance !== undefined) {
      resolved.distance = msg.distance;
    }
    else {
      resolved.distance = 0.0
    }

    if (msg.location_x !== undefined) {
      resolved.location_x = msg.location_x;
    }
    else {
      resolved.location_x = 0.0
    }

    if (msg.location_y !== undefined) {
      resolved.location_y = msg.location_y;
    }
    else {
      resolved.location_y = 0.0
    }

    return resolved;
    }
};

module.exports = gui_msg;
