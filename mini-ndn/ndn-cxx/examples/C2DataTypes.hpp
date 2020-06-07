#include <iostream>
#include <stdio.h>
#include <boost/noncopyable.hpp>

#define N_PAYLOAD_QTD 6

#typedef struct C2Data{
    std::string strLabel;
    int         nSizeBytes;
    void*       pPayload;
}C2DATA;


using namespace std{


class C2DataTypes : noncopyable{

    private:
        void* m_arrPayloads[N_PAYLOAD_QTD];

    public:
        C2DataTypes();
        ~C2DataTypes();

        C2DATA* generatePackage(int nType);
};


} // Close namespace std