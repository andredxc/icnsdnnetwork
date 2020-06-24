#include <iostream>
#include <stdio.h>
// #include <boost/noncopyable.hpp>

#define N_PAYLOAD_QTD   6
#define N_PAYLOAD0_SIZE 1
#define N_PAYLOAD1_SIZE 10
#define N_PAYLOAD2_SIZE 20
#define N_PAYLOAD3_SIZE 30
#define N_PAYLOAD4_SIZE 40
#define N_PAYLOAD5_SIZE 50

typedef struct c2_data{
  std::string strLabel;
  int         nSizeBytes;
  void*       pPayload;
}C2DATA;


class C2DataTypes
{
  private:
    void* m_arrPayloads[N_PAYLOAD_QTD];

  public:
    C2DataTypes();
    ~C2DataTypes();

    C2DATA* generatePackage(int nType, std::string strPackageName);
    C2DATA* generatePackageFromPool(int nPoolSize);
    C2DATA* generatePackageFromInterest(std::string strInterest);
};
