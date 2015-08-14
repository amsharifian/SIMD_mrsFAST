#include"simdCompare.hpp"

long simple_simd_compare(long **str1, long **str2)
{
    BitBlock simd_s1 [3];
    BitBlock simd_s2 [3];

    BitBlock res, temp, pop;

    long fres; 

    res = mvmd<128>::fill(0);
    temp = mvmd<128>::fill(0);
    pop = mvmd<128>::fill(0);

    //Initializing SIMD registers
    for(int i = 0; i < 3; i ++)
    {
        simd_s1[i] = mvmd<128>::fill(0);
        simd_s2[i] = mvmd<128>::fill(0);
    }

    if(VECTORSIZE < 33)
    {
        simd_s1[0] = mvmd<128>::fill(str1[0][0]);
        simd_s1[1] = mvmd<128>::fill(str1[0][1]);
        simd_s1[2] = mvmd<128>::fill(str1[0][2]);

        simd_s2[0] = mvmd<128>::fill(str2[0][0]);
        simd_s2[1] = mvmd<128>::fill(str2[0][1]);
        simd_s2[2] = mvmd<128>::fill(str2[0][2]);
    }
    else if(VECTORSIZE < 65)
    {
        simd_s1[0] = mvmd<64>::fill2(str1[0][0],str1[1][0]);
        simd_s1[1] = mvmd<64>::fill2(str1[0][1],str1[1][1]);
        simd_s1[2] = mvmd<64>::fill2(str1[0][2],str1[1][2]);

        simd_s2[0] = mvmd<64>::fill2(str2[0][0],str2[1][0]);
        simd_s2[1] = mvmd<64>::fill2(str2[0][1],str2[1][1]);
        simd_s2[2] = mvmd<64>::fill2(str2[0][2],str2[1][2]);
    }

    for(int i = 0; i < 3; i++)
    {
        temp = simd_xor(simd_s1[i], simd_s2[i]);
        res = simd_or(res,temp);
    }

    pop = simd<128>::popcount(res);

    fres = convert(pop);

    return fres;
}
