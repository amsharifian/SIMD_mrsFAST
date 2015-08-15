#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "common.hpp"

void initialize(char **str)
{
    *str = (char *)malloc(sizeof(char) * VECTOR_SIZE);
}

void print(char *str)
{
    printf("%s\n", str);
}

int popcnt(long comparision)
{
    int res = __builtin_popcountl(comparision);
    return res;
}

int main()
{
    char *str1,*str2;
    int array_size = (VECTOR_SIZE/WORD_SIZE) + 1;

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

    srand(100);

    initialize(&str1);
    initialize(&str2);
    generateRandomSequence(str1);
    generateRandomSequence(str2);
    print(str1);
    print(str2);
    bitConvert(str1, vector1);
    bitConvert(str2, vector2);
    compare(vector1,vector2,res);
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


    BitBlock a,b,c;
    a = mvmd<32>::fill4(0,-1,0,-1);
    b = mvmd<32>::fill4(5,-1,0,0);
    c = simd<32>::add(a,b);
    print_register("a",a);
    long testt = mvmd<32>::extract<3>(b);
    std::cout << testt << std::endl;
    print_register("b",b);
    print_register("c",c);

    //Releasing memories
    delete[] str1;
    delete[] str2;
    delete[] res;
    for(int i = 0; i < array_size; i++)
    {
        delete[] vector1[i];
        delete[] vector2[i];
    }
    delete[] vector1;
    delete[] vector2;

    return 0;
}
