#include<iostream>
#include"sequence.hpp"

void generateRandomSequence(char *str)
{
    int r;
    for (int i = 0; i < VECTOR_SIZE; i++) {
        r = rand() % 4;
        switch (r) {
            case 0:
                {
                    str[i] = 'A';
                    break;
                }
            case 1:
                {
                    str[i] = 'C';
                    break;
                }
            case 2:
                {
                    str[i] = 'G';
                    break;
                }
            case 3:
                {
                    str[i] = 'T';
                    break;
                }
        }
    }
}


/// This function generate a secondary string base on an input string. The second string with 90% is identical with the first string
/// but with 10% it may different with the first one
/// @param [in] strin Input string
/// @param [out] strout Output string
//
void generateSecondRandomSeq(char *strin, char *strout)
{
    srand(time(NULL));
    int r;
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        //srand(time(NULL));
        r = rand() % 100;
        //std::cout << r << std::endl;
        
        if(r < 90)
        {
            strout[i] = strin[i];
        }
        else
        {
            r = rand() % 4;

            switch (r) {
                case 0:
                    {
                        strout[i] = 'A';
                        break;
                    }
                case 1:
                    {
                        strout[i] = 'C';
                        break;
                    }
                case 2:
                    {
                        strout[i] = 'G';
                        break;
                    }
                case 3:
                    {
                        strout[i] = 'T';
                        break;
                    }
            }
        }
    }
}
