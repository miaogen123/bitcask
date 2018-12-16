#pragma once
#include<vector>
#include<fstream>
#include<atomic>
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
	int put(const std::string& key, const std::string& value);
	//Lazy-删除key/value
	int del(std::string key);
	~bitcask();

private:
	//多线程的同步流
	//TODO::linux下不需要, 因为linux下底层有相关实现
	std::atomic_flag writeFlag = ATOMIC_FLAG_INIT;
	//log文件流
	std::ofstream fileToLog;
	//log文件最大是10M
	const long long LogSize= 10485760;
	size_t valueToAnd;
	std::vector<std::string> hashTable;
};

