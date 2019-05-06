#include <stdio.h>
#include "SpiceUsr.h"

SpiceDouble   et;
double  JD=2459766.575682;
SpiceChar     utc[32];


int  main (){
    //LOAD KERNEL
    furnsh_c ( "/home/kingpc/asteroid/spice kernel data/ephemeris.furnsh" );  
    //JD to ET      
    et=unitim_c(JD,"JED", "ET" );
    printf ( "JD:2459766.575682=\nET:%f\n", et );

    //ET to UTC
    timout_c ( et, "YYYY Mon DD:MN:SC.### ::RND", 32, utc ); 
    printf ( "\nJD:2459766.575682=\nUTC:%s\n", utc  );

    //convert UTC to ET 
    str2et_c ( "2005-DEC-28 12:00",&et);
    printf ( "\nUTC:2005-DEC-28 12:00=\nET:%f\n", et );

    //UNLOAD KERNEL
    unload_c ( "/home/kingpc/asteroid/spice kernel data/ephemeris.furnsh");
    return 0;
}
 
    
