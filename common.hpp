#ifndef __COMMON__
#define __COMMON__

#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<time.h>
#include <string.h>
#include"simd-lib/bitblock.hpp"
#include"bitConvert.hpp"
#include"sequence.hpp"
#include"simdCompare.hpp"
#include"simd-lib/idisa.hpp"
#include"compare.hpp"
#include"readFile.hpp"

#define WORD_SIZE 32
#define VECTOR_SIZE 100
#define BITSIZE 3     
#define STRING_SIZE 20
#define ERROR_THERSHOLD 5
#endif
