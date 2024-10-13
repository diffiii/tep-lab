#include "allocations.h"

#include <cstdio>
#include "const.h"
#include "utils.h"

void allocateTableAndFill(const int tableSize)
{
    if (tableSize <= 0)
    {
        printf("Table size has to be greater than 0!");
    }
    else
    {
        int* pTable = new int[tableSize];

        for (int i = 0; i < tableSize; i++)
        {
            pTable[i] = FILL_VALUE;
        }

        printIntTable(pTable, tableSize);

        delete[] pTable;
    }
}

bool allocateTwoDimensionalTable(int*** pTable, const int cols, const int rows)
{
    if (cols <= 0 || rows <= 0)
    {
        return false;
    }

    *pTable = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        (*pTable)[i] = new int[cols];
    }

    return true;
}

bool deallocateTwoDimensionalTable(int*** pTable, const int cols, const int rows)
{
    if (cols <= 0 || rows <= 0)
    {
        return false;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] (*pTable)[i];
    }

    delete[] *pTable;

    return true;
}
