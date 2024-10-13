#ifndef ALLOCATIONS_H
#define ALLOCATIONS_H

void allocateTableAndFill(int tableSize);
bool allocateTwoDimensionalTable(int*** pTable, int cols, int rows);
bool deallocateTwoDimensionalTable(int*** pTable, int cols, int rows);

#endif
