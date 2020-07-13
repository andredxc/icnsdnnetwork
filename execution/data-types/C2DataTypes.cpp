#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "C2DataTypes.hpp"
// #include <boost/noncopyable.hpp>


// --------------------------------------------------------------------------------
//  C2DataTypes
//
//
// --------------------------------------------------------------------------------
C2DataTypes::C2DataTypes()
{
    // Allocate possible payloads
    m_arrPayloads[0] = (void*)malloc(N_PAYLOAD0_SIZE);
    m_arrPayloads[1] = (void*)malloc(N_PAYLOAD1_SIZE);
    m_arrPayloads[2] = (void*)malloc(N_PAYLOAD2_SIZE);
    m_arrPayloads[3] = (void*)malloc(N_PAYLOAD3_SIZE);
    m_arrPayloads[4] = (void*)malloc(N_PAYLOAD4_SIZE);
    m_arrPayloads[5] = (void*)malloc(N_PAYLOAD5_SIZE);
}

// --------------------------------------------------------------------------------
//  ~C2DataTypes
//
//
// --------------------------------------------------------------------------------
C2DataTypes::~C2DataTypes()
{
    int i;
    // Allocate possible payloads
    for(i = 0; i < N_PAYLOAD_QTD; i++){
        free(m_arrPayloads[i]);
    }
}

// --------------------------------------------------------------------------------
//  generatePackage
//
//
// --------------------------------------------------------------------------------
C2DATA* C2DataTypes::generatePackage(int nType, std::string strPackageName)
{
    C2DATA* pC2Data;

    if(nType >= 0 && nType < N_PAYLOAD_QTD)
    {
        pC2Data = (C2DATA*)malloc(sizeof(C2DATA));
        pC2Data->strLabel = strPackageName;
        pC2Data->pPayload = m_arrPayloads[nType];

        switch(nType){
            case 0:
                pC2Data->nSizeBytes = N_PAYLOAD0_SIZE; break;
            case 1:
                pC2Data->nSizeBytes = N_PAYLOAD1_SIZE; break;
            case 2:
                pC2Data->nSizeBytes = N_PAYLOAD2_SIZE; break;
            case 3:
                pC2Data->nSizeBytes = N_PAYLOAD3_SIZE; break;
            case 4:
                pC2Data->nSizeBytes = N_PAYLOAD4_SIZE; break;
            case 5:
                pC2Data->nSizeBytes = N_PAYLOAD5_SIZE; break;
            default:
                free(pC2Data);
                pC2Data = NULL;
                std::cout << "Error, data type unknown nType=" << nType << std::endl;
        }
    }
    else
    {
        std::cout << "Error, package type known: nType=" + std::to_string(nType) << std::endl;
        pC2Data = NULL;
    }
    return pC2Data;
}

// --------------------------------------------------------------------------------
//  generatePackageFromPool
//
//
// --------------------------------------------------------------------------------
C2DATA* C2DataTypes::generatePackageFromPool(int nPoolSize)
{
    int         nPackageType;
    int         nPackagesPerType;
    int         nPackageID;
    std::string strPackageName;

    if (nPoolSize % N_PAYLOAD_QTD != 0)
    {
        std::cout << "Error, nPoolSize not evenly distributed with N_PAYLOAD_QTD" << std::endl;
    }
    // Determine which package it is
    nPackagesPerType = nPoolSize / N_PAYLOAD_QTD;
    nPackageID       = rand() % nPackagesPerType;
    nPackageType     = rand() % N_PAYLOAD_QTD;
    strPackageName   = "C2Data-" + std::to_string(nPackageID) + "-Type" + std::to_string(nPackageType);

    return generatePackage(nPackageType, strPackageName);
}

// --------------------------------------------------------------------------------
//  generatePackageFromInterest
//
//
// --------------------------------------------------------------------------------
C2DATA* C2DataTypes::generatePackageFromInterest(std::string strInterest)
{
    int nPackageType;
    int nID;
    C2DATA* pData;

    sscanf(strInterest.c_str(), "C2Data-%d-Type%d", &nID, &nPackageType);

    pData = generatePackage(nPackageType, strInterest);
    return pData;
}

int main(int nArgc, char** ppArgv)
{
    // C2DataTypes     DataTypes;
    // C2DATA*         pData;
    // int             nIndex;
    // list<C2DATA*>   lstData;

    // cout << "C2Data Label=" + pData->strLabel + "; Size=" + to_string(pData->nSizeBytes) + "; pPayload=" + pData->pPayload << endl;

    // for(nIndex = 0; nIndex < N_ITERATIONS; nIndex++){
    //     pData = DataTypes.generatePackageFromPool(N_POOLSIZE);
    //     printf("C2Data[%d] Label= %s; Size= %d; pPayload= %p\n", nIndex, pData->strLabel.c_str(), pData->nSizeBytes, pData->pPayload);
    //     lstData.push_back(pData);
    // }



    return 1;
}
