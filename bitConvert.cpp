#include "common.hpp"

void bitConvert(char * inputString, long **test)
{
    int cnt;
    char tmp;
    int array_size = VECTOR_SIZE/WORD_SIZE;

    for(int i =0; i < array_size; i++)
    {
        for (int j = 0; j < WORD_SIZE; j++) {
            cnt = i * WORD_SIZE + j;
            tmp = inputString[cnt];
            switch (tmp) {
                case 'A':
                    {
                        test[i][0] = test[i][0] << 1;
                        test[i][1] = test[i][1] << 1;
                        test[i][2] = test[i][2] << 1;
                        test[i][2] = test[i][2] | 1;
                        break;

                    }
                case 'C':
                    {
                        test[i][0] = test[i][0] << 1;
                        test[i][1] = test[i][1] << 1;
                        test[i][1] = test[i][1] | 1;
                        test[i][2] = test[i][2] << 1;
                        break;

                    }
                case 'G':
                    {
                        test[i][0] = test[i][0] << 1;
                        test[i][1] = test[i][1] << 1;
                        test[i][1] = test[i][1] | 1;
                        test[i][2] = test[i][2] << 1;
                        test[i][2] = test[i][2] | 1;
                        break;

                    }
                case 'T':
                    {
                        test[i][0] = test[i][0] << 1;
                        test[i][0] = test[i][0] | 1;
                        test[i][1] = test[i][1] << 1;
                        test[i][2] = test[i][2] << 1;
                        break;

                    }
                default:
                    break;

            }

        }

    }

}
