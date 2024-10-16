#ifndef CTABLE_H
#define CTABLE_H

#include <string>

class CTable
{
    std::string name;
    int* pTable;
    int tableSize;

public:
    CTable();
    CTable(const std::string& name, int tableSize);
    CTable(const CTable& pOther);
    ~CTable();
    void setName(const std::string& name);
    bool setNewSize(int tableSize);
    CTable* pClone() const;
    void printInfo() const;
};

void modifyTable(CTable* pTable, int newTableSize);
void modifyTable(CTable table, int newTableSize);

#endif
