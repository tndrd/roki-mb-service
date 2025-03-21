#pragma once

#include "roki-mb-service/MbMessages.hpp"

namespace MbInterface {
struct MbService {
public:
  struct ProcedureID {
    using Type = uint8_t;
    static constexpr Type GetIMUFrame = 0;
    static constexpr Type GetBodyFrame = 1;

    static constexpr Type GetIMUContainerInfo = 2;
    static constexpr Type GetBodyContainerInfo = 3;

    static constexpr Type ResetStrobeContainers = 4;

    static constexpr Type SetIMUStrobeOffset = 6;
    static constexpr Type SetBodyStrobeOffset = 7;

    static constexpr Type GetIMULatest = 8;

    static constexpr Type GetStrobeWidth = 9;
    static constexpr Type ConfigureStrobeFilter = 10;

    static constexpr Type GetVersion = 11;

    static constexpr Type BodySendForward = 12;
    static constexpr Type BodySendQueue = 13;
    static constexpr Type GetBodyQueueInfo = 14;
    static constexpr Type SetBodyQueuePeriod = 15;
    static constexpr Type ResetBodyQueue = 16;

    static constexpr Type ConfigureBodyUART = 17;
    
    static constexpr Type EnableBodyARQ = 18;
    static constexpr Type DisableBodyARQ = 19;

    static constexpr Type SetBodyStrobeCallback = 20;
    static constexpr Type ResetBodyStrobeCallback = 21;

    static uint8_t Serialize(Type id);
    static Type Deserialize(uint8_t val);
  };

  struct ErrorCodes {
    using Type = uint8_t;
    static constexpr Type Success = 0;

    static constexpr Type FrameUnavailable = 1;
    static constexpr Type UnknownProcedure = 2;
    static constexpr Type BadRequest = 3;
    static constexpr Type BadStrobeOffset = 4;
    static constexpr Type BodyTimeout = 5;
    static constexpr Type BodyNACK = 6;
    static constexpr Type BodyUnknownError = 7;
    static constexpr Type BadBodyQueuePeriod = 8;
    static constexpr Type BodyQueueFull = 9;

    static constexpr Type NACK = 255;
    static constexpr Type BodyNotInit = 10;

    static uint8_t Serialize(Type err);
    static Type Deserialize(uint8_t val);
    static const char *GetDescription(Type err);
  };

  struct Procedures {
    struct Procedure {
      using Service = MbService;
    };

    struct GetIMUFrame : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::GetIMUFrame;

      using RequestType = Messages::FrameNumber;
      using ResponceType = Messages::IMUFrameMsg;
    };

    struct GetBodyFrame : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::GetBodyFrame;

      using RequestType = Messages::FrameNumber;
      using ResponceType = Messages::BodyResponce;
    };

    struct GetIMUContainerInfo : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::GetIMUContainerInfo;

      using RequestType = Messages::Empty;
      using ResponceType = Messages::FrameContainerInfo;
    };

    struct GetBodyContainerInfo : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::GetBodyContainerInfo;

      using RequestType = Messages::Empty;
      using ResponceType = Messages::FrameContainerInfo;
    };

    struct GetIMULatest : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::GetIMULatest;

      using RequestType = Messages::Empty;
      using ResponceType = Messages::IMUFrameMsg;
    };

    struct ResetStrobeContainers : public Procedure {
      static constexpr ProcedureID::Type ID =
          ProcedureID::ResetStrobeContainers;

      using RequestType = Messages::Empty;
      using ResponceType = Messages::Empty;
    };

    struct SetIMUStrobeOffset : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::SetIMUStrobeOffset;

      using RequestType = Messages::Byte;
      using ResponceType = Messages::Empty;
    };

    struct SetBodyStrobeOffset : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::SetBodyStrobeOffset;

      using RequestType = Messages::Byte;
      using ResponceType = Messages::Empty;
    };

    struct GetStrobeWidth : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::GetStrobeWidth;

      using RequestType = Messages::Empty;
      using ResponceType = Messages::Byte;
    };

    struct ConfigureStrobeFilter : public Procedure {
      static constexpr ProcedureID::Type ID =
          ProcedureID::ConfigureStrobeFilter;

      using RequestType = Messages::StrobeFilterConfig;
      using ResponceType = Messages::Empty;
    };

    struct GetVersion : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::GetVersion;

      using RequestType = Messages::Empty;
      using ResponceType = Messages::Version;
    };

    struct BodySendForward : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::BodySendForward;

      using RequestType = Messages::BodyRequest;
      using ResponceType = Messages::BodyResponce;
    };

    struct BodySendQueue : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::BodySendQueue;

      using RequestType = Messages::BodyQueueRequest;
      using ResponceType = Messages::Empty;
    };

    struct GetBodyQueueInfo : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::GetBodyQueueInfo;

      using RequestType = Messages::Empty;
      using ResponceType = Messages::BodyQueueInfo;
    };

    struct SetBodyQueuePeriod : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::SetBodyQueuePeriod;

      using RequestType = Messages::PeriodMs;
      using ResponceType = Messages::Empty;
    };

    struct ResetBodyQueue : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::ResetBodyQueue;

      using RequestType = Messages::Empty;
      using ResponceType = Messages::Empty;
    };

    struct ConfigureBodyUART : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::ConfigureBodyUART;

      using RequestType = Messages::BodyUARTConfig;
      using ResponceType = Messages::Empty;
    };

    struct EnableBodyARQ : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::EnableBodyARQ;

      using RequestType = Messages::BodyARQConfig;
      using ResponceType = Messages::Empty;
    };

    struct DisableBodyARQ : public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::DisableBodyARQ;

      using RequestType = Messages::Empty;
      using ResponceType = Messages::Empty;
    };

    struct SetBodyStrobeCallback: public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::SetBodyStrobeCallback;

      using RequestType = Messages::BodyRequest;
      using ResponceType = Messages::Empty;
    };

    struct ResetBodyStrobeCallback: public Procedure {
      static constexpr ProcedureID::Type ID = ProcedureID::ResetBodyStrobeCallback;

      using RequestType = Messages::Empty;
      using ResponceType = Messages::Empty;
    };

  };
};
} // namespace MbInterface
