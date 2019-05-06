#include <stdio.h>
#include "SpiceUsr.h"    

int main()
{
    SpiceDouble   mat1[3][3]={1,0,1,0,0,0,0,0,1};
    SpiceDouble   mat2[3][3]={70,0,0,0,0,0,0,0,1};
    SpiceDouble   mat3[3][3];
    SpiceDouble   q[4];
    mxm_c( mat1, mat2, mat3 );
    printf( " %20.10f\n", mat3[0][0]);
    printf( " %20.10f\n", mat3[0][2]);
    return 0;
}
