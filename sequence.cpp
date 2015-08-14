#include"sequence.hpp"

void generateRandomSequence(char *str)
{
    int r;
    for (int i = 0; i < VECTORSIZE; i++) {
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


