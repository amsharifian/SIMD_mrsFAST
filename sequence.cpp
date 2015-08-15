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
    int r;
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        srand(time(NULL));
        //r = rand() % 100;

        if(r < 90)
        {
            strin[i] = strout[i];
        }
        else
        {
            r = rand() % 4;

            switch (r) {
                case 0:
                    {
                        strin[i] = 'A';
                        break;
                    }
                case 1:
                    {
                        strin[i] = 'C';
                        break;
                    }
                case 2:
                    {
                        strin[i] = 'G';
                        break;
                    }
                case 3:
                    {
                        strin[i] = 'T';
                        break;
                    }
            }
        }
    }
}
