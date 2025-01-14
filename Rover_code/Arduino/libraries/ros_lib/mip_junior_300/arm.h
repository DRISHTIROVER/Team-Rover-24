#ifndef _ROS_mip_junior_300_arm_h
#define _ROS_mip_junior_300_arm_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mip_junior_300
{

  class arm : public ros::Msg
  {
    public:
      typedef float _j1_pwm_type;
      _j1_pwm_type j1_pwm;
      typedef float _j2_pwm_type;
      _j2_pwm_type j2_pwm;
      typedef int64_t _j1_dir_type;
      _j1_dir_type j1_dir;
      typedef int64_t _j2_dir_type;
      _j2_dir_type j2_dir;

    arm():
      j1_pwm(0),
      j2_pwm(0),
      j1_dir(0),
      j2_dir(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->j1_pwm);
      offset += serializeAvrFloat64(outbuffer + offset, this->j2_pwm);
      union {
        int64_t real;
        uint64_t base;
      } u_j1_dir;
      u_j1_dir.real = this->j1_dir;
      *(outbuffer + offset + 0) = (u_j1_dir.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_j1_dir.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_j1_dir.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_j1_dir.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_j1_dir.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_j1_dir.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_j1_dir.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_j1_dir.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->j1_dir);
      union {
        int64_t real;
        uint64_t base;
      } u_j2_dir;
      u_j2_dir.real = this->j2_dir;
      *(outbuffer + offset + 0) = (u_j2_dir.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_j2_dir.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_j2_dir.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_j2_dir.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_j2_dir.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_j2_dir.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_j2_dir.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_j2_dir.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->j2_dir);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->j1_pwm));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->j2_pwm));
      union {
        int64_t real;
        uint64_t base;
      } u_j1_dir;
      u_j1_dir.base = 0;
      u_j1_dir.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_j1_dir.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_j1_dir.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_j1_dir.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_j1_dir.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_j1_dir.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_j1_dir.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_j1_dir.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->j1_dir = u_j1_dir.real;
      offset += sizeof(this->j1_dir);
      union {
        int64_t real;
        uint64_t base;
      } u_j2_dir;
      u_j2_dir.base = 0;
      u_j2_dir.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_j2_dir.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_j2_dir.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_j2_dir.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_j2_dir.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_j2_dir.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_j2_dir.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_j2_dir.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->j2_dir = u_j2_dir.real;
      offset += sizeof(this->j2_dir);
     return offset;
    }

    virtual const char * getType() override { return "mip_junior_300/arm"; };
    virtual const char * getMD5() override { return "49bbe853220892f0d458a11f0829875d"; };

  };

}
#endif
