#include "C2DataTypes.hpp"

#include <list>

#define N_ITERATIONS 30
#define N_POOLSIZE   60

using namespace std;

int main(int nArgc, char** ppArgv)
{
    C2DataTypes     DataTypes;
    C2DATA*         pData;
    int             nIndex;
    list<C2DATA*>   lstData;

    // cout << "C2Data Label=" + pData->strLabel + "; Size=" + to_string(pData->nSizeBytes) + "; pPayload=" + pData->pPayload << endl;

    for(nIndex = 0; nIndex < N_ITERATIONS; nIndex++){
        pData = DataTypes.generatePackageFromPool(N_POOLSIZE);
        printf("C2Data[%d] Label= %s; Size= %d; pPayload= %p\n", nIndex, pData->strLabel.c_str(), pData->nSizeBytes, pData->pPayload);
        lstData.push_back(pData);
    }



    return 1;
}