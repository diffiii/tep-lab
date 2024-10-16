#include <cstdlib>

#include "allocations.h"
#include "ctable.h"

int main()
{
    allocateTableAndFill(-1);
    allocateTableAndFill(10);

    int** pTwoDimensionalTable;
    allocateTwoDimensionalTable(&pTwoDimensionalTable, 5, 3);
    deallocateTwoDimensionalTable(&pTwoDimensionalTable, 5, 3);

    CTable ctableDefault;
    const CTable *pCTableParameters = new CTable("test", 5);
    CTable ctableCopy(ctableDefault);

    ctableDefault.setName("new name");

    const CTable* pCTableClone = pCTableParameters->pClone();
    pCTableClone->printInfo();

    modifyTable(&ctableCopy, 10);
    ctableCopy.printInfo();

    modifyTable(ctableCopy, 8);
    ctableCopy.printInfo();

    delete pCTableParameters;
    delete pCTableClone;

    return EXIT_SUCCESS;
}
