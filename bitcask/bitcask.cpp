#include <iostream>
#include "bitcask.h"
#ifdef _WIN32
	#include "MyUtils\hash.h"
	#include "MyUtils\timeRela.h"
#elif __linux__
	#include "MyUtils/hash.h"
	#include "MyUtils/timeRela.h"
#endif




bitcask::bitcask(){
	//TODO::重建索引表
	//TODO::确定当前的文件，走到了那个文件 
	fileToLog.open("bitcask.0", std::fstream::app|std::fstream::app);
	if (!fileToLog.is_open()) {
		throw std::runtime_error("construct error, file may be occupied");
	}
	//1024^3=1073741824 | 1024^2=1048576
	hashTable.reserve(1048576);
	hashTable.resize(1048576);
	//TODO:这里是可以优化的
	size_t tmp = 1;
	tmp <<= 20;
	tmp = tmp - 1;
	valueToAnd = tmp;
}

std::string bitcask::get(std::string key) const{
	return std::string();
}

int bitcask::put(const std::string& key, const std::string& value){
	//TODO::添加CRC冗余
	auto timestamp = getCurrentOfFormat("%F %T");
	auto keySize = std::to_string(key.size());
	auto valueSize = std::to_string(value.size());
	auto hashKey = BKDRHash(key.c_str());
	//TODO:;这里需要加上fileID
	auto ptrLoc=fileToLog.tellp();
	hashTable[hashKey&valueToAnd] = std::to_string(value.size()) + " " + std::to_string(ptrLoc);
	//TODO::多线程下windows需要加锁
	//while (writeFlag.test_and_set());
	fileToLog << timestamp + " " + keySize + " " + valueSize + " " + key + " " + value << std::endl;
	//writeFlag.clear(); 
	return true;
}

int bitcask::del(std::string key)
{
	return 0;
}


bitcask::~bitcask()
{
	fileToLog.close();
}
