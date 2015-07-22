#include "bitConvert.h"

long *bitConvert(char * inputString, long *test)
{
  int i, j;
  char tmp;

  for (j = 0; j < VECTORSIZE; j++) {
    tmp = inputString[j];
    switch (tmp) {
      case 'A':
      {
        test[0] = test[0] << 1;
        test[1] = test[1] << 1;
        test[2] = test[2] << 1;
        break;
      }
      case 'C':
      {
        test[0] = test[0] << 1;
        test[1] = test[1] << 1;
        test[2] = test[2] << 1;
        test[2] = test[2] | 1;
        break;
      }
      case 'G':
      {
        test[0] = test[0] << 1;
        test[1] = test[1] << 1;
        test[1] = test[1] | 1;
        test[2] = test[2] << 1;
        break;
      }
      case 'T':
      {
        test[0] = test[0] << 1;
        test[1] = test[1] << 1;
        test[1] = test[1] | 1;
        test[2] = test[2] << 1;
        test[2] = test[2] | 1;
        break;
      }
      default:
        break;
    }
  }
  return test;
}
