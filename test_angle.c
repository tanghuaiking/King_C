#include <stdio.h>
#include "SpiceUsr.h"    
SpiceDouble   a[3];
SpiceDouble   b[3];
int  main()
{
    vpack_c( 1.0, 0.0, 0.0, a );
    vpack_c( 1.0, 1.0, 0.0, b );
    printf( "angular separation, deg = %12.3f\n", 
             vsep_c(a,b) * dpr_c() );
    return 0;
}
