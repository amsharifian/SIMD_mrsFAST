#include"bitblock.hpp"
#include "idisa.hpp"

//#define BLOCK_SIZE 256


int main()
{
    //    int res = 0;

    BitBlock a,b,res1,res2;
    a = mvmd<32>::fill4(10,512,15,11);
    b = mvmd<32>::fill4(1,2,1,1);

    //res = simd_or(a,b);
    res1 = simd<2>::add(a,b);

    res2 = simd<4>::add(a,b);
    //printf("%d \n",res);
    print_register("a",a);
    print_register("b",b);
    print_register("res1",res1);
    print_register("res2",res2);
    return 0;
}
