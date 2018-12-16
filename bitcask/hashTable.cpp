#include "hashTable.h"



hashTable::hashTable(int tableSize){
	table = new size_t[tableSize]();
}


hashTable::~hashTable(){
	delete[] table;
}
