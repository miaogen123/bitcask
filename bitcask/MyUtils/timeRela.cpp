#ifdef _WIN32
	#include"..\pch.h"
#elif __linux__
	#include"../pch.h"
#endif
#include"timeRela.h"
#include<time.h>
#include<sstream>
#include<stdexcept>

std::string getStrToday(){
    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream  ss;
	ss<< std::put_time(std::localtime(&t), "%F") ;
    return std::string(ss.str());
}

//windows 下log的append 不一定是atomic的，windows不支持posix
std::string getCurrentOfFormat(const char* format) {
    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream  ss;
	tm buf;
	try {
		//localtime is not a thread-safe function
		//windows下报错
		//localtime_s(&buf, &t);
		//ss<< std::put_time(&buf,"%F %T") ;

		ss<< std::put_time(std::localtime(&t), "%F %T") ;
	}
	catch (std::exception e) {
		throw std::runtime_error("format error");
	}
    return std::string(ss.str());
}
