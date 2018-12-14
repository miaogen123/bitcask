#include <iostream>
#include "bitcask.h"
#include"MyUtils\timeRela.h"


bitcask::bitcask(){
	//TODO::重建索引表
	//TODO::确定当前的文件，走到了那个文件 
	fileToLog.open("bitcask.0", std::fstream::app|std::fstream::app);
	if (!fileToLog.is_open()) {
		throw std::runtime_error("construct error, file may be occupied");
	}
}

std::string bitcask::get(std::string key) const{
	return std::string();
}

int bitcask::put(std::string key, std::string value){
	//TODO::添加CRC冗余
	auto timestamp = getCurrentOfFormat("%F %T");
	auto keySize = std::to_string(key.size());
	auto valueSize = std::to_string(value.size());
	while (writeFlag.test_and_set());
	fileToLog << timestamp + " " + keySize + " " + valueSize + " " + key + " " + value << std::endl;
	writeFlag.clear(); 
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
