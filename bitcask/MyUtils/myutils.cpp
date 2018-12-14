#include "myutils.h"
#include<chrono>
//#include<unistd.h>


int getRandomInt()
{
	//errror
	//std::default_random_engine e(std::chrono::high_resolution_clock::to_time_t(std::chrono::high_resolution_clock::now())+static_cast<long long>((&temp))&65535 );


	std::default_random_engine e(clock());
	std::uniform_int_distribution<unsigned int> uig;
	return uig(e);

	//srand(std::chrono::high_resolution_clock::to_time_t(std::chrono::high_resolution_clock::now()));
	//return static_cast<int>(rand());
}


//generate the str in range of a-z &A-Z
std::string getRandStr(int length){
    std::random_device rd; 
    std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis (65, 122);
    std::string retStr;
    for (int i=0;i<length;i++){
        auto chaAscii=dis(gen);
        if(90<chaAscii&&chaAscii<97)
            chaAscii+=7;
        retStr.push_back(static_cast<char>(chaAscii));
    }
    return retStr;
}
