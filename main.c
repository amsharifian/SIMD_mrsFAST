#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitConvert.h"

void initialize(char **str)
{
  *str = (char *)malloc(sizeof(char) * VECTORSIZE);
  srand(100);
}

void generateRandomSequence(char *str)
{
  int r;
  for (size_t i = 0; i < VECTORSIZE; i++) {
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

void print(char *str)
{
  printf("%s\n", str);
}

long compare(long *in1, long *in2)
{
  long res = 0;
  long tmp = 0;
  for (size_t i = 0; i < BITSIZE; i++) {
    tmp = in1[i] ^ in2[i];
    res = tmp | res;
  }
  return res;
}

int popcnt(long comparision)
{
  int res = __builtin_popcountl(comparision);
}

int main()
{
  char *str1,*str2;
  long *vector1, *vector2;

  vector1 = (long *)malloc(sizeof(long)*BITSIZE);
  vector2 = (long *)malloc(sizeof(long)*BITSIZE);

  initialize(&str1);
  initialize(&str2);
  generateRandomSequence(str1);
  generateRandomSequence(str2);
  print(str1);
  print(str2);
  bitConvert(str1, vector1);
  bitConvert(str2, vector2);
  long res = compare(vector1,vector2);
  int final = popcnt(res);
  //printf("%ld\n", res);
  printf("Number of ones:%d\n", final);
  return 0;
}
