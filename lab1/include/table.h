#pragma once

#ifndef CTABLE_H
#define CTABLE_H

#include <string>

/* Zadanie 4 */
class Table
{
public:
    Table();
    Table(const std::string& name, int tableSize);
    Table(const Table& pOther);
    ~Table();
    void setName(const std::string& name);
    bool setNewSize(int tableSize);
    Table* pClone() const;
    bool doubleSize();
    void printInfo() const;

private:
    std::string name;
    int tableSize;
    int* pTable;
};

void modifyTable(Table* pTable, int newTableSize);
void modifyTable(Table table, int newTableSize);

#endif
