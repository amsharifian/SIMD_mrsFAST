#ifndef __BITVECTOR__
#define __BITVECTOR__

extern "C" void bitConvert_8v(char * inputString, char **vector, int str_len);
extern "C" void bitConvert_16v(char * inputString, short int **vector, int str_len);
extern "C" void bitConvert_32v(char * inputString, long **vector, int str_len);
extern "C" void bitConvert_64v(char * inputString, long **vector, int str_len);

#endif
