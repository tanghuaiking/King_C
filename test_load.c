#include <stdio.h>
#include "SpiceUsr.h"

SpiceDouble   et;
char   *date = "Thu Mar 20 12:53:29 PST 1997";
int main ()
{
    furnsh_c ( "/home/kingpc/asteroid/spice kernel data/ephemeris.furnsh" );
    str2et_c ( date, &et );
    printf ( "%f\n", et );
    unload_c ( "/home/kingpc/asteroid/spice kernel data/ephemeris.furnsh");
    return 0;
}
