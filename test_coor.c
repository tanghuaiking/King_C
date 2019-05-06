#include <stdio.h>
#include "SpiceUsr.h" 

SpiceDouble   istate[6];
SpiceDouble   ostate[6];

istate[0] = 1000.0;
istate[1] = 2000.0;
istate[2] = 3000.0;
istate[3] =   20.0;
istate[4] =  -40.0;
istate[6] =  -60.0;
int  main()
{
    xfmsta_c ( istate, "RECTANGULAR", 
                 "LATITUDINAL", " ", 
                 ostate );
    printf( "R     = %20.10f KM\n",    ostate[0] );
    printf( "LONG  = %20.10f RAD\n",   ostate[1] );
    printf( "LAT   = %20.10f RAD\n",   ostate[2] );
    printf( "DR    = %20.10f KM/S\n",  ostate[3] );
    printf( "DLONG = %20.10f RAD/S\n", ostate[4] );
    printf( "DLAT  = %20.10f RAD/S\n", ostate[5] );
    return 0;
}




