#include "common.hpp"


void bitConvert_8v(char *inputString, char **test, int str_len)
{
    int w_size = 8 * sizeof(char);
    int cnt;
    char tmp;
    int array_size = ((str_len - 1) / w_size) + 1;

    for(int i =0; i < array_size; i++)
    {
        for (int j = 0; j < w_size; j++) {
            cnt = i * w_size + j;
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


void bitConvert_16v(short int *inputString, short int **test, int str_len)
{
    int w_size = 8 * sizeof(short int);
    int cnt;
    char tmp;
    int array_size = str_len/w_size;

    for(int i =0; i < array_size; i++)
    {
        for (int j = 0; j < w_size; j++) {
            cnt = i * w_size + j;
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


void bitConvert_32v(char *inputString, long **test, int str_len)
{
    int w_size = 8 * sizeof(int);
    int cnt;
    char tmp;
    int array_size = ((str_len - 1) / w_size) + 1;


    for(int i =0; i < array_size; i++)
    {
        for (int j = 0; j < w_size; j++) {
            cnt = i * w_size + j;
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

void bitConvert_64v(char *inputString, long **test, int str_len)
{
    int w_size = 8 * sizeof(long);
    int cnt;
    char tmp;
    int array_size = str_len/w_size;

    for(int i =0; i < array_size; i++)
    {
        for (int j = 0; j < w_size; j++) {
            cnt = i * w_size + j;
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
