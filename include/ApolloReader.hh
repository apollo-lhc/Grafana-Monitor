#ifndef __APOLLO__READER__HH__
#define __APOLLO__READER__HH__

#include <string>
#include <vector>
#include <freeipmi/api/ipmi-api.h>

class ApolloReader {

public:

  ApolloReader(char *hostname_, uint8_t deviceAddr);
  
  std::vector<uint8_t> GetHeader();

  std::vector<uint8_t> GetData();

  // board fields
  std::string GetBoardManufacturer();
  std::string GetBoardName();
  std::string GetBoardSerial();
  std::string GetBoardPartNumber();
  std::string GetFruFileId();
  // product info fields
  std::string GetProductManufacturer();
  std::string GetProductName();
  std::string GetProductPartNumber();
  std::string GetProductVersion();
  std::string GetProductSerial();
  std::string GetAssetTag();
  
private:

  void Read();
  void ReadHeader();
  void ReadInternalUse();
  void ReadChassisInfo();
  void ReadBoardArea();
  std::string ReadBoardField(uint8_t field_type_and_length, uint8_t field_index);
  void ReadProductInfo();
  std::string ReadProductField(uint8_t field_type_and_length, uint8_t field_index);
  void ReadMultiRecord();

  
  int ReadInformationLength(ipmi_ctx_t ipmiContext);

  int informationLength;
  int total_bytes_used;
  
  char *hostname;
  
  uint8_t deviceAccessAddress;
  
  std::vector<uint8_t> header;
  // fields for data stored in header
  uint8_t headerFormatVersion;
  uint8_t internalUseStartingOffset;
  uint8_t chassisInfoStartingOffset;
  uint8_t boardStartingOffset;
  uint8_t productInfoStartingOffset;
  uint8_t multiRecordStartingOffset;
  uint8_t pad;
  uint8_t commonHeaderChecksum;

  // raw hex data from the blade
  std::vector<uint8_t> data;
  // sub vectors for each info region
  std::vector<uint8_t> internalUseData;
  std::vector<uint8_t> chassisData;
  std::vector<uint8_t> boardData;
  std::vector<uint8_t> productInfoData;
  std::vector<uint8_t> multiRecordData;

  // board fields
  std::string boardManufacturer;
  std::string boardName;
  std::string boardSerial;
  std::string boardPartNumber;
  std::string fruFileId;
  // product fields
  std::string productManufacturer;
  std::string productName;
  std::string productPartNumber;
  std::string productVersion;
  std::string productSerial;
  std::string assetTag;
};
#endif