#include "ctable.h"

#include <string>
#include <cstdio>
#include "const.h"

CTable::CTable()
{
    this->name = DEFAULT_CTABLE_NAME;
    this->tableSize = DEFAULT_CTABLE_SIZE;
    this->pTable = new int[this->tableSize];

    printf("bezp: %s\n", this->name.c_str());
}

CTable::CTable(const std::string& name, const int tableSize)
{
    this->name = name;
    this->tableSize = tableSize;
    this->pTable = new int[this->tableSize];

    printf("parametr: %s\n", this->name.c_str());
}

CTable::CTable(const CTable& pOther)
{
    this->name = pOther.name + "_copy";
    this->tableSize = pOther.tableSize;
    this->pTable = new int[this->tableSize];

    for (int i = 0; i < this->tableSize; i++)
    {
        this->pTable[i] = pOther.pTable[i];
    }

    printf("kopiuj: %s\n", this->name.c_str());
}

CTable::~CTable()
{
    delete[] this->pTable;

    printf("usuwam: %s\n", this->name.c_str());
}

void CTable::setName(const std::string& name)
{
    this->name = name;
}

bool CTable::setNewSize(const int tableSize)
{
    if (tableSize <= 0)
    {
        return false;
    }

    int* pNewSizedTable = new int[tableSize];

    const int numberOfValuesToCopy = std::min(this->tableSize, tableSize);

    for (int i = 0; i < numberOfValuesToCopy; i++)
    {
        pNewSizedTable[i] = this->pTable[i];
    }

    delete[] this->pTable;
    this->pTable = pNewSizedTable;

    this->tableSize = tableSize;

    return true;
}

CTable* CTable::pClone() const
{
    return new CTable(*this);
}

void CTable::printInfo() const
{
    printf("CTable name: %s\n", this->name.c_str());
    printf("tableSize: %d\n", this->tableSize);
}

void modifyTable(CTable *pTable, const int newTableSize)
{
    pTable->setNewSize(newTableSize);
}

void modifyTable(CTable table, const int newTableSize)
{
    table.setNewSize(newTableSize);
}
