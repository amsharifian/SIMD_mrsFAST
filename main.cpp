#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "common.hpp"

void initialize(char **str)
{
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
    int w_size;
    w_size = 8 * (sizeof(char));

    int passed = 0;
    char **test_str;

    //Generating reference string
    char *str_ref = new char[VECTOR_SIZE];
    generateRandomSequence(str_ref);

    //Measuring size of array needed for saving a string.
    //For instance if size of string is 40 then we need an arrya with size two or we need two integer to save the string
    //array_size is size of that array
    int array_size = ((VECTOR_SIZE - 1)/WORD_SIZE) + 1;

    //Defining vector of strings for testing. STRING_SIZE means size of our dataset.
    //According to the size of array_size we define second dimension of the array and 
    //since we are saving our charecters with three bits so last dimension is just 3
    // str_vector: vector of strings
    // v_str_ref : converted version of refference string
    long ***str_vector = new long **[STRING_SIZE];
    long **v_str_ref = new long *[array_size];

    //Returned value of normal version
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
            res[i] = 0;
        }
    }


    srand(100);

    test_str = new char *[STRING_SIZE];
    for(int i = 0; i < STRING_SIZE; i++)
    {
        test_str[i] = new char[VECTOR_SIZE];
    }

    print(str_ref);
    for(int i = 0; i < STRING_SIZE; i++)
    {
        generateSecondRandomSeq(str_ref, test_str[i]);
        print(test_str[i]);
    }
    bitConvert_32(str_ref, v_str_ref);
    for(int i = 0; i < STRING_SIZE; i++)
    {
        bitConvert_32(test_str[i], str_vector[i]);
    }

    for(int p = 0; p < STRING_SIZE; p++)
    {
        //compare(v_str_ref,str_vector[p],res);
        res2 = simple_simd_compare(v_str_ref, str_vector[p]);
        //res2 = 0;
        std::cout << "String " << p << ":" << res2 << std::endl;
        if(res2 < ERROR_THERSHOLD)
        {
            passed++;
        }
    }


    // int final = 0;
    // for(int i = 0; i < array_size; i++)
    // {
    //     final += popcnt(res[i]);
    // }
    //printf("Number of ones:%d\n", final);
    printf("# passed strings: %d \n", passed);


    //Testing SIMD Optimized
    simd_compare_32v(str_vector, v_str_ref,STRING_SIZE, ERROR_THERSHOLD);


    //TODO add your function here

    std::cout << "shrot int: " << sizeof(short int) << std::endl;
    std::cout << "int: " << sizeof(int) << std::endl;
    std::cout << "long: " <<sizeof(long) << std::endl;
    std::cout << "char: " << sizeof(char) << std::endl;
    //Freeing memory
    delete[] str_ref;   
    delete[] res;
    for(int i = 0; i < STRING_SIZE; i++)
    {
        for(int j = 0; j < array_size; j++)
        {
            delete[] str_vector[i][j];
        }
        delete[] str_vector[i];
    }
    delete[] str_vector;

    for(int i = 0; i < array_size; i++)
    {
        delete[] v_str_ref[i];
    }
    delete[] v_str_ref;
    for(int i = 0; i < STRING_SIZE; i++)
    {
        delete[] test_str[i];
    }
    delete[] test_str;


    return 0;
}
