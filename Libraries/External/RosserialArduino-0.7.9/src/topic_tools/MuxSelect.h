#ifndef _ROS_SERVICE_MuxSelect_h
#define _ROS_SERVICE_MuxSelect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ArduinoIncludes.h"

namespace topic_tools
{

#ifdef ESP8266
    static const char MUXSELECT[] = "topic_tools/MuxSelect";
#else
    static const char MUXSELECT[] PROGMEM = "topic_tools/MuxSelect";
#endif

  class MuxSelectRequest : public ros::Msg
  {
    public:
      typedef const char* _topic_type;
      _topic_type topic;

    MuxSelectRequest():
      topic("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic = strlen(this->topic);
      varToArr(outbuffer + offset, length_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic;
      arrToVar(length_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
     return offset;
    }

    const char * getType(){ return MUXSELECT; };
    #ifdef ESP8266
        const char * getMD5() { return  ("d8f94bae31b356b24d0427f80426d0c3");};
    #else
        const char * getMD5() { return  PSTR("d8f94bae31b356b24d0427f80426d0c3");};
    #endif

  };

  class MuxSelectResponse : public ros::Msg
  {
    public:
      typedef const char* _prev_topic_type;
      _prev_topic_type prev_topic;

    MuxSelectResponse():
      prev_topic("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_prev_topic = strlen(this->prev_topic);
      varToArr(outbuffer + offset, length_prev_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->prev_topic, length_prev_topic);
      offset += length_prev_topic;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_prev_topic;
      arrToVar(length_prev_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_prev_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_prev_topic-1]=0;
      this->prev_topic = (char *)(inbuffer + offset-1);
      offset += length_prev_topic;
     return offset;
    }

    const char * getType(){ return MUXSELECT; };
    #ifdef ESP8266
        const char * getMD5() { return  ("3db0a473debdbafea387c9e49358c320");};
    #else
        const char * getMD5() { return  PSTR("3db0a473debdbafea387c9e49358c320");};
    #endif

  };

  class MuxSelect {
    public:
    typedef MuxSelectRequest Request;
    typedef MuxSelectResponse Response;
  };

}
#endif