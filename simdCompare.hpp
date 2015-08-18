#ifndef __SIMDCOMPARE__
#define __SIMDCOMPARE__

#include"common.hpp"

long simple_simd_compare(long **str1, long **str2);
void simd_compare_32v(long ***vector_str, long **ref_str, int len, int error);

#endif
