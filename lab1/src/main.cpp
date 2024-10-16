#include <cstdlib>

#include <cstdio>
#include "allocations.h"
#include "table.h"

int main()
{
    allocateTableAndFill(-1);
    allocateTableAndFill(10);

    int** pTwoDimensionalTable;
    allocateTwoDimensionalTable(&pTwoDimensionalTable, 5, 3);
    deallocateTwoDimensionalTable(&pTwoDimensionalTable, 5, 3);

    printf("%s\n", allocateTwoDimensionalTable(&pTwoDimensionalTable, 5, 3) ? "true" : "false");
    printf("%s\n", deallocateTwoDimensionalTable(&pTwoDimensionalTable, 5, 3) ? "true" : "false");

    Table tableDefault;
    const Table *pTableParameters = new Table("test", 5);
    Table tableCopy(tableDefault);

    tableDefault.setName("new name");

    const Table* pCTableClone = pTableParameters->pClone();
    pCTableClone->printInfo();

    modifyTable(&tableCopy, 10);
    tableCopy.printInfo();

    modifyTable(tableCopy, 8);
    tableCopy.printInfo();

    delete pTableParameters;
    delete pCTableClone;

    tableDefault.printInfo();
    printf("%s\n", tableDefault.doubleSize() ? "true" : "false");
    tableDefault.printInfo();

    return EXIT_SUCCESS;
}
