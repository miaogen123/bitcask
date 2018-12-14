#pragma once
#include <assert.h>

#define DEBUG	1
#if DEBUG
#define CDebug(x)	 std::cout<<(x)<<std::endl;
#else
#define CDebug(x)	//x
#endif

#if DEBUG
#define ASSERT(x) assert(x)
#else
#define ASSERT(x) //x
#endif

