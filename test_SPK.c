#include <stdio.h>
#include "SpiceUsr.h"

SpiceDouble   et;
SpiceDouble   state[6],state_j2000[3],state_iau[3];
SpiceDouble   lt;
SpiceDouble   rotate[3][3];
SpiceDouble   moon_rad,moon_long,moon_lat;
SpiceDouble   mu=398600.435608;
SpiceDouble        elts[8];

int  main (){
//LOAD KERNEL
furnsh_c ( "/home/kingpc/asteroid/spice kernel data/ephemeris.furnsh" ); 

//GET THE EPHEMERIS OF MOON
str2et_c ( "2017 JAN 31 01:00", &et );
spkezr_c ( "MOON", et, "J2000", "NONE", "EARTH", state, &lt );
        printf( "2017 JAN 31 01:00=ET  %20.10f\n THE EPHEMERIS OF MOON   (J2000)\n", et       );
        printf( "J2000 x-position (km):   %20.10f\n", state[0] );
        printf( "J2000 y-position (km):   %20.10f\n", state[1] );
        printf( "J2000 z-position (km):   %20.10f\n", state[2] );
        printf( "J2000 x-velocity (km/s): %20.10f\n", state[3] );
        printf( "J2000 y-velocity (km/s): %20.10f\n", state[4] );
        printf( "J2000 z-velocity (km/s): %20.10f\n", state[5] );

// CONVERT FROM J2000 TO IAU_EARTH COORDINATE (ONLY POSITION)
//**********ECLIPJ2000(黄道坐标)
state_j2000[0]=state[0];
state_j2000[1]=state[1];
state_j2000[2]=state[2];
pxform_c ( "J2000", "IAU_Earth", et,    rotate     );
mxv_c(  rotate,   state_j2000,  state_iau  );
      printf( "\n CONVERT FROM J2000 TO IAU_EARTH \n" );
        printf( "IAU_Earth x-position (km):   %20.10f\n", state_iau[0] );
        printf( "IAU_Earth y-position (km):   %20.10f\n", state_iau[1] );
        printf( "IAU_Earth z-position (km):   %20.10f\n", state_iau[2] );

// CONVERT FROM RECTANGULAR COORDINATE TO SPHERE COORDINATE
reclat_c (state_iau,&moon_rad,&moon_long,&moon_lat);

       printf( "\n CONVERT FROM RECTANGULAR COORDINATE TO SPHERE COORDINATE \n" );
        printf( "IAU_Earth radius (km):   %20.10f\n", moon_rad );
        printf( "IAU_Earth longitude (rad):  %20.10f\n", moon_long);
        printf( "IAU_Earth latitude (rad):  %20.10f\n", moon_lat );

//COMPUTE TWO BODY ORBIT(J2000)
oscelt_c ( state, et, mu,elts );
 printf( "\n COMPUTE TWO BODY ORBIT(J2000) \n" );
printf( "RP      Perifocal distance:   %20.10f\n", elts[0]);
printf( "ECC     Eccentricity:  %20.10f\n",  elts[1]);
printf( "INC     Inclination(rad):  %20.10f\n",  elts[2]);
printf( "LNODE   Longitude of the ascending node(rad):   %20.10f\n", elts[3]);
printf( "ARGP    Argument of periapse(rad):  %20.10f\n",  elts[4]);
printf( "M0      Mean anomaly at epoch(rad):  %20.10f\n",  elts[5] );
printf( "T0      Epoch(rad):  %20.10f\n",  elts[6]);
printf( "MU      Gravitational parameter(rad):  %20.10f\n",  elts[7] );

//UNLOAD KERNEL       
unload_c ( "/home/kingpc/asteroid/spice kernel data/ephemeris.furnsh");
return 0;
}
