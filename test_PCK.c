#include <stdio.h>
#include "SpiceUsr.h"


      SpiceDouble   et;
      SpiceDouble   mat[3][3];
      SpiceDouble   radii[3];
      SpiceInt      n;


int main()
       {
         furnsh_c ( "/home/kingpc/asteroid/spice kernel data/ephemeris.furnsh" );
         bodvrd_c ( "MARS", "RADII", 3, &n, radii );
         printf ( "[%f,", radii[0] );
         printf ( "%f,", radii[1] );
         printf ( "%f]\n", radii[2] );
         str2et_c ( "2005-DEC-28 12:00", &et );
         pxform_c ( "J2000", "IAU_MARS", et, mat );
         //printf ( "%f\n", et );
         
unload_c ( "/home/kingpc/asteroid/spice kernel data/ephemeris.furnsh");
         return 0;
       }
