#include <stdio.h>
#include "./mersenne-twister/src/mt19937.h"
#include <limits>

int main(void){
   MT19937 mt19937_self = mt19937_seed(12345);
   uint32_t val;
   val = mt19937_rand(&mt19937_self);
   double vald = val * (1.0 / std::numeric_limits<uint32_t>::max());
   printf("%10u %10u\n", val, std::numeric_limits<uint32_t>::max());
   printf("%lf\n", vald);
}
