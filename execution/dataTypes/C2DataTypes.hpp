#include <iostream>
#include <stdio.h>
#include <boost/noncopyable.hpp>

#define N_PAYLOAD_QTD 6

typedef struct c2_data{
    std::string strLabel;
    int         nSizeBytes;
    void*       pPayload;
}C2DATA;


class C2DataTypes : noncopyable
{

    private:
        void* m_arrPayloads[N_PAYLOAD_QTD];

    public:
        C2DataTypes();
        ~C2DataTypes();

        C2DATA* generatePackage(int nType, std::string strPackageName);
        C2DATA* generatePackageFromPool(int nPoolSize);
};
