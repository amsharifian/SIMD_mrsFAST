#ifndef __SIMDCOMPARE__
#define __SIMDCOMPARE__

#include"common.hpp"

void fill(char *array, int len, int val);
void fill(short int *array, int len, int val);
void fill(int *array, int len, int val);
void fill(long *array, int len, int val);

extern "C" long simple_simd_compare(long **str1, long **str2);
extern "C" void simd_compare_8v(long ***vector_str, long **ref_str, int len, int error);
extern "C" void simd_compare_16v(long ***vector_str, long **ref_str, int len, int error);
extern "C" void simd_compare_32v(long ***vector_str, long **ref_str, int len, int error);
extern "C" void simd_compare_64v(long ***vector_str, long **ref_str, int len, int error);
#endif
