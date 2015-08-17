#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "common.hpp"

void initialize(char **str)
{
    //*str = (char *)malloc(sizeof(char) * VECTOR_SIZE);
    *str = new char[VECTOR_SIZE];
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
    char **test_str;
    char *str_ref = new char[VECTOR_SIZE];
    generateRandomSequence(str_ref);

    int array_size = (VECTOR_SIZE/WORD_SIZE) + 1;

    long ***str_vector = new long **[STRING_SIZE];
    long **v_str_ref = new long *[array_size];
    //long **vector2 = new long *[array_size];

    long *res = new long[array_size];
    long res2 = 0;

    for(int i = 0; i < array_size; i++)
    {
        v_str_ref[i] = new long[BITSIZE];
    }

    for(int j = 0; j < STRING_SIZE; j++)
    {
        str_vector[j] = new long *[array_size];
        for(int i = 0; i < array_size; i ++)
        {
            str_vector[j][i] = new long [BITSIZE];
            //vector2[i] = new long [BITSIZE];
            res[i] = 0;
        }
    }
    

    srand(100);

    //initialize(&str1);
    //initialize(&str2);
    //
    //Initialize strings
    test_str = new char *[STRING_SIZE];
    for(int i = 0; i < STRING_SIZE; i++)
    {
        test_str[i] = new char[VECTOR_SIZE];
    }
    //str1 = new char[VECTOR_SIZE];
    //str2 = new char[VECTOR_SIZE];

    print(str_ref);
    for(int i = 0; i < STRING_SIZE; i++)
    {
        generateSecondRandomSeq(str_ref, test_str[i]);
        //print(test_str[i]);
        //generateRandomSequence(test_str[i]);
        //print(test_str[i]);
        //test_str[i] = str1;
    }
    // generateRandomSequence(str1);
    // generateRandomSequence(str2);
    //print(test_str[10]);
    //print(test_str[15]);
    bitConvert(str_ref, v_str_ref);
    for(int i = 0; i < STRING_SIZE; i++)
    {
        bitConvert(test_str[i], str_vector[i]);
    }

    compare(v_str_ref,str_vector[10],res);
    res2 = simple_simd_compare(v_str_ref, str_vector[10]);


    int final = 0;
    for(int i = 0; i < array_size; i++)
    {
        final += popcnt(res[i]);
    }
    //int final = popcnt(res);
    //printf("%ld\n", res);
    printf("Number of ones:%d\n", final);
    printf("Test: %ld \n", res2);


    // BitBlock a,b,c;
    // a = mvmd<32>::fill4(0,-1,0,-1);
    // b = mvmd<32>::fill4(5,-1,0,0);
    // c = simd<32>::add(a,b);
    // print_register("a",a);
    // long testt = mvmd<32>::extract<3>(b);
    // std::cout << testt << std::endl;
    // print_register("b",b);
    // print_register("c",c);

    //Releasing memories
    // delete[] str1;
    // delete[] str2;
    delete[] res;
    for(int i = 0; i < array_size; i++)
    {
        delete[] str_vector[i];
        //delete[] vector2[i];
    }
    delete[] str_vector;

    return 0;
}
