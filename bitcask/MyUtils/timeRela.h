#pragma once
#include<iomanip>
#include<time.h>
#include<chrono>


// like 2016-11-23
std::string getStrToday();
// like 2016-11-12 23:23:12
std::string getCurrentOfFormat(const char* format);
