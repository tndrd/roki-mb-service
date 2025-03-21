#pragma once

#include <array>
#include <assert.h>
#include <memory.h>
#include <stdint.h>

namespace MbInterface {
namespace Messages {

struct IMUFrameMsg {
  struct TimestampT {
    uint32_t TimeS;
    uint32_t TimeNS;
  };

  struct QuaternionMsg {
    int16_t X;
    int16_t Y;
    int16_t Z;
    int16_t W;
  };

  QuaternionMsg Orientation;
  TimestampT Timestamp;

  uint8_t SensorID;

  void Serialize(uint8_t *ptr) const;
  static IMUFrameMsg Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct FrameContainerInfo {
  uint16_t First;
  uint16_t NumAv;
  uint16_t MaxFrames;
  uint8_t Active;

  void Serialize(uint8_t *ptr) const;
  static FrameContainerInfo Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct Empty {
  void Serialize(uint8_t *ptr) const;
  static Empty Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct Byte {
  uint8_t Value;

  void Serialize(uint8_t *ptr) const;
  static Byte Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct FrameNumber {
  uint16_t Seq;

  void Serialize(uint8_t *ptr) const;
  static FrameNumber Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct StrobeFilterConfig {
  uint8_t TargetDuration;
  uint8_t DurationThreshold;

  void Serialize(uint8_t *ptr) const;
  static StrobeFilterConfig Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct Version {
  uint8_t Major;
  uint8_t Minor;

  void Serialize(uint8_t *ptr) const;
  static Version Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct BodyQueueInfo {
  uint16_t Size;
  uint16_t Capacity;

  void Serialize(uint8_t *ptr) const;
  static BodyQueueInfo Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct PeriodMs {
  uint8_t Ms;

  void Serialize(uint8_t *ptr) const;
  static PeriodMs Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct BodyRequest {
  const uint8_t *Data;

  uint8_t RequestSize;
  uint8_t ResponceSize;

  void Serialize(uint8_t *ptr) const;
  static BodyRequest Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct BodyQueueRequest {
  uint8_t Pause;
  BodyRequest Request;

  void Serialize(uint8_t *ptr) const;
  static BodyQueueRequest Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct BodyResponce {
  const uint8_t *Data;
  uint8_t ResponceSize;

  void Serialize(uint8_t *ptr) const;
  static BodyResponce Deserialize(const uint8_t *ptr);
  size_t GetPackedSize() const;
};

struct BodyARQConfig {
  BodyResponce NACK; // zero-size means no ARQ
  Byte AttemptC;

  void Serialize(uint8_t* ptr) const;
  static BodyARQConfig Deserialize(const uint8_t * ptr);
  size_t GetPackedSize() const;
};

struct Word {
  uint16_t Value;

  void Serialize(uint8_t* ptr) const;
  static Word Deserialize(const uint8_t* ptr);
  size_t GetPackedSize() const;
};

struct DWord {
  uint32_t Value;

  void Serialize(uint8_t* ptr) const;
  static DWord Deserialize(const uint8_t* ptr);
  size_t GetPackedSize() const;
};

struct BodyUARTConfig {
  struct ParityVal {
    static constexpr uint8_t None = 0; 
    static constexpr uint8_t Even = 1; 
    static constexpr uint8_t Odd = 2; 
  };

  DWord Baudrate;
  Byte Parity;
  Byte ByteSize; // Including parity
  Byte StopBits;
  Word TimeoutMs;

  void Serialize(uint8_t* ptr) const;
  static BodyUARTConfig Deserialize(const uint8_t* ptr);
  size_t GetPackedSize() const;
};

} // namespace Messages
} // namespace MbInterface