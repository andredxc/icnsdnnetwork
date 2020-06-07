#include "C2DataTypes.hpp"

#include <stdlib.h>

#define N_PAYLOAD0_SIZE 10
#define N_PAYLOAD1_SIZE 10
#define N_PAYLOAD2_SIZE 10
#define N_PAYLOAD3_SIZE 10
#define N_PAYLOAD4_SIZE 10
#define N_PAYLOAD5_SIZE 10


C2DataTypes::C2DataTypes(string strOrig, string strDest, int nType)
{
    // Allocate possible payloads
    m_arrPayloads[0] = (void*)malloc(N_PAYLOAD0_SIZE);
    m_arrPayloads[1] = (void*)malloc(N_PAYLOAD1_SIZE);
    m_arrPayloads[2] = (void*)malloc(N_PAYLOAD2_SIZE);
    m_arrPayloads[3] = (void*)malloc(N_PAYLOAD3_SIZE);
    m_arrPayloads[4] = (void*)malloc(N_PAYLOAD4_SIZE);
    m_arrPayloads[5] = (void*)malloc(N_PAYLOAD5_SIZE);
}

C2DATA* C2DataTypes::generatePackage(int nType)
{
    C2DATA* pC2Data;

    pC2Data = (void*)malloc(sizeof(pC2Data));

    switch(nType){
        case 1:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[0];
            pC2Data->nSizeBytes = N_PAYLOAD0_SIZE;
            break;
        case 2:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[1];
            pC2Data->nSizeBytes = N_PAYLOAD1_SIZE;
            break;
        case 3:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[2];
            pC2Data->nSizeBytes = N_PAYLOAD2_SIZE;
            break;
        case 4:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[3];
            pC2Data->nSizeBytes = N_PAYLOAD3_SIZE;
            break;
        case 5:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[4];
            pC2Data->nSizeBytes = N_PAYLOAD4_SIZE;
            break;
        case 6:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[5];
            pC2Data->nSizeBytes = N_PAYLOAD5_SIZE;
            break;
        default:
            free(pC2Data);
            pC2Data = NULL;
            std::cout << "Error, data type unknown nType=" << nType << std::endl;
    }
    return pC2Data;
}




int    size();
void*  payload();
string label();
