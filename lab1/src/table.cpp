#include "table.h"

#include <string>
#include <cstdio>
#include <limits.h>
#include "const.h"

Table::Table()
{
    this->name = DEFAULT_CTABLE_NAME;
    this->tableSize = DEFAULT_CTABLE_SIZE;
    this->pTable = new int[this->tableSize];

    printf("bezp: %s\n", this->name.c_str());
}

Table::Table(const std::string& name, const int tableSize)
{
    if (tableSize >= 1) {
        this->name = name;
        this->tableSize = tableSize;
        this->pTable = new int[this->tableSize];

        printf("parametr: %s\n", this->name.c_str());
    }
}

Table::Table(const Table& pOther)
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

Table::~Table()
{
    delete[] this->pTable;

    printf("usuwam: %s\n", this->name.c_str());
}

void Table::setName(const std::string& name)
{
    this->name = name;
}

bool Table::setNewSize(const int tableSize)
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

Table* Table::pClone() const
{
    return new Table(*this);
}

bool Table::doubleSize()
{
    if (this->tableSize >= INT_MAX / 2)
    {
        return false;
    }

    delete this->pTable;

    this->tableSize *= 2;
    this->pTable = new int[this->tableSize];

    return true;
}

void Table::printInfo() const
{
    printf("CTable name: %s\n", this->name.c_str());
    printf("tableSize: %d\n", this->tableSize);
}

void modifyTable(Table *pTable, const int newTableSize)
{
    pTable->setNewSize(newTableSize);
}

void modifyTable(Table table, const int newTableSize)
{
    table.setNewSize(newTableSize);
}
