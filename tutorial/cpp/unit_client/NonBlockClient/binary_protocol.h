#ifndef _BINARYP_ROTOCOL_H_
#define _BINARYP_ROTOCOL_H_ 1

#include <boost/shared_ptr.hpp>
#include "./TBufferTransports.h"
#include "./protocol.h"

namespace apache {
namespace thrift {
namespace protocol {
using namespace apache::thrift::transport;
/**
 * The default binary protocol for thrift. Writes all data in a very basic
 * binary format, essentially just spitting out the raw bytes.
 *
 */

template <class ByteOrder_ = TNetworkBigEndian>
class TBinaryProtocolT : public TProtocol{
public:
  static const int32_t VERSION_MASK = ((int32_t)0xffff0000);
  static const int32_t VERSION_1 = ((int32_t)0x80010000);
  // VERSION_2 (0x80020000) was taken by TDenseProtocol (which has since been removed)

  TBinaryProtocolT(boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> trans)
    : TProtocol(trans),
      trans_(trans.get()),
      string_limit_(0),
      container_limit_(0),
      strict_read_(false),
      strict_write_(true) {}

  TBinaryProtocolT(boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> trans,
                   int32_t string_limit,
                   int32_t container_limit,
                   bool strict_read,
                   bool strict_write)
    : TProtocol(trans),
      trans_(trans.get()),
      string_limit_(string_limit),
      container_limit_(container_limit),
      strict_read_(strict_read),
      strict_write_(strict_write) {}

  void setStringSizeLimit(int32_t string_limit) { string_limit_ = string_limit; }

  void setContainerSizeLimit(int32_t container_limit) { container_limit_ = container_limit; }

  void setStrict(bool strict_read, bool strict_write) {
    strict_read_ = strict_read;
    strict_write_ = strict_write;
  }

  /**
   * Writing functions.
   */

  /*ol*/ uint32_t writeMessageBegin(const std::string& name,
                                    const TMessageType messageType,
                                    const int32_t seqid);

  /*ol*/ uint32_t writeMessageEnd();

  inline uint32_t writeStructBegin(const char* name);

  inline uint32_t writeStructEnd();

  inline uint32_t writeFieldBegin(const char* name, const TType fieldType, const int16_t fieldId);

  inline uint32_t writeFieldEnd();

  inline uint32_t writeFieldStop();

  inline uint32_t writeMapBegin(const TType keyType, const TType valType, const uint32_t size);

  inline uint32_t writeMapEnd();

  inline uint32_t writeListBegin(const TType elemType, const uint32_t size);

  inline uint32_t writeListEnd();

  inline uint32_t writeSetBegin(const TType elemType, const uint32_t size);

  inline uint32_t writeSetEnd();

  inline uint32_t writeBool(const bool value);

  inline uint32_t writeByte(const int8_t byte);

  inline uint32_t writeI16(const int16_t i16);

  inline uint32_t writeI32(const int32_t i32);

  inline uint32_t writeI64(const int64_t i64);

  inline uint32_t writeDouble(const double dub);

  template <typename StrType>
  inline uint32_t writeString(const StrType& str);

  inline uint32_t writeBinary(const std::string& str);

  /**
   * Reading functions
   */

  /*ol*/ uint32_t readMessageBegin(std::string& name, TMessageType& messageType, int32_t& seqid);

  /*ol*/ uint32_t readMessageEnd();

  inline uint32_t readStructBegin(std::string& name);

  inline uint32_t readStructEnd();

  inline uint32_t readFieldBegin(std::string& name, TType& fieldType, int16_t& fieldId);

  inline uint32_t readFieldEnd();

  inline uint32_t readMapBegin(TType& keyType, TType& valType, uint32_t& size);

  inline uint32_t readMapEnd();

  inline uint32_t readListBegin(TType& elemType, uint32_t& size);

  inline uint32_t readListEnd();

  inline uint32_t readSetBegin(TType& elemType, uint32_t& size);

  inline uint32_t readSetEnd();

  inline uint32_t readBool(bool& value);
  // Provide the default readBool() implementation for std::vector<bool>
 // using TVirtualProtocol<TBinaryProtocolT<TMemoryBuffer, ByteOrder_> >::readBool;
  inline uint32_t readBool(std::vector<bool>::reference value) {
    bool b = false;
    uint32_t ret = readBool(b);                     
    value = b;
    return ret;                                                                    
  }

  inline uint32_t readByte(int8_t& byte);

  inline uint32_t readI16(int16_t& i16);

  inline uint32_t readI32(int32_t& i32);

  inline uint32_t readI64(int64_t& i64);

  inline uint32_t readDouble(double& dub);

  template <typename StrType>
  inline uint32_t readString(StrType& str);

  inline uint32_t readBinary(std::string& str);

protected:
  template <typename StrType>
  uint32_t readStringBody(StrType& str, int32_t sz);

  TMemoryBuffer* trans_;

  int32_t string_limit_;
  int32_t container_limit_;

  // Enforce presence of version identifier
  bool strict_read_;
  bool strict_write_;
};

typedef TBinaryProtocolT<TNetworkBigEndian> TBinaryProtocol;
typedef TBinaryProtocolT<TNetworkLittleEndian> TLEBinaryProtocol;

}
}
} // apache::thrift::protocol

#include "./binary_protocol.tcc"

#endif // #ifndef _BINARY_PROTOCOL_H_
