#include"common.hpp"


// Comparing two converted string to vertical bit format
// @param [in] in1 First string
// @param [in] in2 Second string
// @param [out] res result of comparison

void compare(long **in1, long **in2, long *res)
{
    int array_size = (VECTOR_SIZE/WORD_SIZE) + 1;
    long *tmp = new long[array_size] ;
    std::fill(tmp, tmp+array_size, 0);

    for (int i = 0; i < array_size; i++) {
        for(int j = 0; j < BITSIZE; j++) {
            tmp[i] = in1[i][j] ^ in2[i][j];
            res[i] = tmp[i] | res[i];
        }
    }
    delete[] tmp;
}


