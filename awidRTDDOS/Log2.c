#include "defs.h"
#include <math.h>
// Calculates log2 of number.
double Log2( double n )
{
    // log(n)/log(2) is log2.
    return (log10( n ) / log10( 2 ));
}
