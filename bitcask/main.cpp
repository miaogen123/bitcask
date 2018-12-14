// bitcask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MyUtils\DebugMode.h"
#include <iostream>
#include "bitcask.h"


#ifndef DEBUG

int main()
{
	return 0;
}

#else

#include<thread>
#include"MyUtils\myutils.h"


void TestPut() {
	static bitcask a;

	const int circleTimes = 10;
	for (int i = 0; i < circleTimes; i++) {
		auto key = getRandStr(8);
		auto value = getRandStr(40);
		a.put(key, value);
	}
	return;
}


int main()
{
	//test multi-thread put
	const int threadCount= 5;
	std::thread p[threadCount];

	for (int i = 0; i < threadCount; i++) {
		std::thread a(TestPut);
		p[i] = std::move(a);
	}
	for (int i = 0; i < threadCount; i++) {
		p[i].join();
	}
	return 0;
}

#endif // DEBUG
