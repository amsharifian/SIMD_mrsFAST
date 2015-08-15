#include"simdCompare.hpp"


/// This function compares two converted string in vertical manner
/// @param [in] str1 First string
/// @param [in] str2 Second string
/// @param [out] fres FinalResult which shows final comparison
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

    /*
     * According to the vector size we can figure out that how we should fill our simd
     * Also we now that the length of string would varies from 1 charecter to 128 charecter not more!
     */

    if(VECTOR_SIZE < 33)
    {
        //if the length of the charecter is less or equal to 32 then we now that our string has been fited to an 1D array
        //so what the funtion copy the same value to the SIMD registers

        simd_s1[0] = mvmd<128>::fill(str1[0][0]);
        simd_s1[1] = mvmd<128>::fill(str1[0][1]);
        simd_s1[2] = mvmd<128>::fill(str1[0][2]);

        simd_s2[0] = mvmd<128>::fill(str2[0][0]);
        simd_s2[1] = mvmd<128>::fill(str2[0][1]);
        simd_s2[2] = mvmd<128>::fill(str2[0][2]);
    }
    else if(VECTOR_SIZE < 65)
    {
        //If the length of the charecter is more than 32 bit but is less than 64 so then we know that the string has been fited
        //in an 2D array with length of 2, so we need to fill our register with two 32 bit variable

        simd_s1[0] = mvmd<64>::fill2(str1[0][0],str1[1][0]);
        simd_s1[1] = mvmd<64>::fill2(str1[0][1],str1[1][1]);
        simd_s1[2] = mvmd<64>::fill2(str1[0][2],str1[1][2]);

        simd_s2[0] = mvmd<64>::fill2(str2[0][0],str2[1][0]);
        simd_s2[1] = mvmd<64>::fill2(str2[0][1],str2[1][1]);
        simd_s2[2] = mvmd<64>::fill2(str2[0][2],str2[1][2]);
    }

    else if(VECTOR_SIZE < 129)
    {
        if(VECTOR_SIZE <97)
        {
            simd_s1[0] = mvmd<32>::fill4(str1[0][0], str1[1][0], str1[2][0],0);
            simd_s1[1] = mvmd<32>::fill4(str1[0][1], str1[1][1], str1[2][1],0);
            simd_s1[2] = mvmd<32>::fill4(str1[0][2], str1[1][2], str1[2][2],0);

            simd_s2[0] = mvmd<32>::fill4(str2[0][0], str2[1][0], str1[2][0],0);
            simd_s2[0] = mvmd<32>::fill4(str2[0][1], str2[1][1], str2[2][1],0);
            simd_s2[0] = mvmd<32>::fill4(str2[0][2], str2[1][2], str2[2][2],0);
        }

        else
        {
            simd_s1[0] = mvmd<32>::fill4(str1[0][0], str1[1][0], str1[2][0],str1[3][0]);
            simd_s1[1] = mvmd<32>::fill4(str1[0][1], str1[1][1], str1[2][1],str1[3][1]);
            simd_s1[2] = mvmd<32>::fill4(str1[0][2], str1[1][2], str1[2][2],str1[3][2]);

            simd_s2[0] = mvmd<32>::fill4(str2[0][0], str2[1][0], str1[2][0], str2[3][0]);
            simd_s2[0] = mvmd<32>::fill4(str2[0][1], str2[1][1], str2[2][1], str2[3][1]);
            simd_s2[0] = mvmd<32>::fill4(str2[0][1], str2[1][1], str2[2][1], str2[3][2]);

        }
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

int recompute_index(bool *flag, int *index, int len)
{
    int i = 0;
    int k = 0;
    for(int j = 0; j < len; j++)
    {
        i = j;
        while(flag[i] && i < len)
            i++;
        index[j] = i;
        if (i < len)
            k++;
    }
    return k;
}

/*
 * Optimized version of SIMD - 32bit version
 */

void simd_compare_32v(long ***str, long **conststr, int count, int len, int error_thershold)
{
    int valid = 0;

    int array_size = (VECTOR_SIZE/WORD_SIZE) + 1;

    bool *flag = new bool[len];
    int *index = new int[len];
    int *err_count = new int[len];

    int tmp_value[4];

    for(int i = 0; i < len; i++)
    {
        flag = 0;
        err_count[i] = 0;
    }
    valid = recompute_index(flag,index,len);

    std::fill(flag, flag + len, 0);

    BitBlock regTarget, regConstant;
    BitBlock r_tmp, r_err_count, r_poptmp;
    BitBlock r_err_thershold, r_res_thershold, r_res_compare;
    r_err_thershold = mvmd<32>::fill4(error_thershold,error_thershold,error_thershold,error_thershold);
    r_res_compare = mvmd<128>::fill(0);


    for (int k = 0; k < 3; k++)
    {
        for(int j = 0; j < array_size; j++)
        {
            for (int i = 0; i < len; i+4)
            {
                if (valid >= 4)
                {
                    //Copying 32bit form Reads to the SIMD registers and duplicating 32bits from const char
                    // 
                    // --------------------------------------------------
                    // |    read1   |   read2   |   read3   |   read4   |
                    // --------------------------------------------------
                    //
                    //                          XOR
                    // 
                    // --------------------------------------------------
                    // |    const1  |   const1  |   const1  |   const1  |
                    // --------------------------------------------------
                    //
                    //

                    regTarget = mvmd<32>::fill4(str[i+index[i]][j][k],str[i+index[i]][j][k],str[i+index[i]][j][k],str[i+3][j][k]);
                    regConstant = mvmd<32>::fill4(conststr[j][k], conststr[j][k], conststr[j][k], conststr[j][k]);

                    r_tmp = simd_xor(regTarget, regConstant);
                    r_poptmp = simd<32>::popcount(r_tmp);

                    r_err_count = mvmd<32>::fill4(err_count[i+index[i]], err_count[i+index[i]], err_count[i+index[i]], err_count[i+index[i]]);
                    r_err_count = simd<32>::add(r_err_count, r_poptmp);

                    r_err_thershold = mvmd<32>::fill4(error_thershold, error_thershold, error_thershold, error_thershold);


                    r_res_compare = simd<32>::gt(r_err_count, r_err_thershold);

                    tmp_value[0] = mvmd<32>::extract<0>(r_res_compare);
                    tmp_value[1] = mvmd<32>::extract<1>(r_res_compare);
                    tmp_value[2] = mvmd<32>::extract<2>(r_res_compare);
                    tmp_value[3] = mvmd<32>::extract<3>(r_res_compare);
                }
            }

        }
    }
}

