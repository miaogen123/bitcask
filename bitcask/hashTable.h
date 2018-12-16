#pragma once
//留待以后使用，之前建这个类是想到围绕hashTable会有一些操作，但现在想不起来是那些了
//以后需要的时候在改这个地方吧
#include<array>
class hashTable
{
public:
	//1024^3=1073741824 | 1024^2=1048576
	hashTable(int tableSize=1048576);
	~hashTable();
private:
	//使用size_t array与hash的结果类型保持一致
	size_t *table;
};

