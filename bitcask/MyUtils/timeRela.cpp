#include"../pch.h"
#include"timeRela.h"
#include<sstream>
#include<stdexcept>

std::string getStrToday(){
    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream  ss;
	ss<< std::put_time(std::localtime(&t), "%F") ;
    return std::string(ss.str());
}

std::string getCurrentOfFormat(const char* format) {
    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream  ss;
	try {
		ss<< std::put_time(std::localtime(&t),format) ;
	}
	catch (std::exception& e) {
		throw std::runtime_error("format error");
	}
    return std::string(ss.str());
}
