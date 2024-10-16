#include "allocations.h"

#include <cstdio>
#include "const.h"
#include "utils.h"

/* Zadanie 1 */
void allocateTableAndFill(const int tableSize)
{
    if (tableSize <= 0)
    {
        printf("Table size has to be greater than 0!\n");
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

/* Zadanie 2 */
bool allocateTwoDimensionalTable(int*** pTable, const int tableSizeX, const int tableSizeY)
{
    if (tableSizeX <= 0 || tableSizeY <= 0 || pTable == NULL)
    {
        return false;
    }

    *pTable = new int*[tableSizeX];

    for (int i = 0; i < tableSizeX; i++)
    {
        (*pTable)[i] = new int[tableSizeY];
    }

    return true;
}

/* Zadanie 3 */
bool deallocateTwoDimensionalTable(int*** pTable, const int tableSizeX, const int tableSizeY)
{
    if (tableSizeX <= 0 || tableSizeY <= 0 || pTable == NULL)
    {
        return false;
    }

    for (int i = 0; i < tableSizeX; i++)
    {
        delete[] (*pTable)[i];
    }

    delete[] *pTable;

    return true;
}
