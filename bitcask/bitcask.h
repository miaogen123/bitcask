#pragma once
#include<fstream>
#include<string>

//TODO::实现基于bloom filter的查找
//TODO::实现基于hash table 的查找


class bitcask
{
public:
	bitcask();
	//获取key/value
	std::string get(std::string key)const;
	//写入key/value
	int put(std::string key, std::string value);
	//删除key/value
	int del(std::string key);
	~bitcask();

private:
	//log文件流
	std::ofstream fileToLog;
	//log文件最大是10M
	const long long LogSize= 10485760;
};

