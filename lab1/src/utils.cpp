#include "utils.h"

#include <cstdio>

void printIntTable(const int* pTable, const int tableSize)
{
    for (int i = 0; i < tableSize; i++)
    {
        printf("%d ", pTable[i]);
    }

    printf("\n");
}
