#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "common.hpp"

void initialize(char **str)
{
    *str = (char *)malloc(sizeof(char) * VECTORSIZE);
    srand(100);
}

void print(char *str)
{
    printf("%s\n", str);
}

long *compare(long **in1, long **in2)
{
    int array_size = (VECTORSIZE/WORD_SIZE) + 1;
    long *res = new long[array_size] ;
    long *tmp = new long[array_size] ;
    std::fill(res, res+array_size, 0);
    std::fill(res, res+array_size, 0);

    for (int i = 0; i < array_size; i++) {
        for(int j = 0; j < BITSIZE; j++) {
            tmp[i] = in1[i][j] ^ in2[i][j];
            res[i] = tmp[i] | res[i];
        }
    }
    return res;
}

int popcnt(long comparision)
{
    int res = __builtin_popcountl(comparision);
    return res;
}

int main()
{
    char *str1,*str2;
    int array_size = (VECTORSIZE/WORD_SIZE) + 1;

    long **vector1 = new long *[array_size];
    long **vector2 = new long *[array_size];

    long *res = new long[array_size];
    long res2 = 0;

    for(int i = 0; i < array_size; i ++)
    {
        vector1[i] = new long [BITSIZE];
        vector2[i] = new long [BITSIZE];
        res[i] = 0;
    }

    //vector1 = (long *)malloc(sizeof(long)*BITSIZE*( (VECTORSIZE/WORD_SIZE) + 1));
    //vector2 = (long *)malloc(sizeof(long)*BITSIZE*( (VECTORSIZE/WORD_SIZE) + 1));
    //vector1 = new long [array_size][BITSIZE];
    //vector2 = new long [array_size][BITSIZE];

    initialize(&str1);
    initialize(&str2);
    generateRandomSequence(str1);
    generateRandomSequence(str2);
    print(str1);
    print(str2);
    bitConvert(str1, vector1);
    bitConvert(str2, vector2);
    res = compare(vector1,vector2);
    res2 = simple_simd_compare(vector1, vector2);

    int final = 0;
    for(int i = 0; i < array_size; i++)
    {
        final += popcnt(res[i]);
    }
    //int final = popcnt(res);
    //printf("%ld\n", res);
    printf("Number of ones:%d\n", final);
    printf("Test: %ld \n", res2);
    return 0;
}
