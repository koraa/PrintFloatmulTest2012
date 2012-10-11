#include <stdio.h>

#define aL 100000
#define bL 333333

#define decl(type, ex)                           \
    type a ## ex = aL,                           \
         b ## ex = bL,                           \
         res ## ex  = (( type )  a ## ex   *   b ## ex ) ,  \
         rlit ## ex = (( type )  ((long) aL) * bL)

#define out(from, ex, intr)                \
    printf( #from " -> "                   \
           /* FORMAT STRING */             \
           "%" #intr ": "                  \
           "[" #intr ", " #intr "]"        \
           " = " #intr                     \
           " = " #intr                     \
           " = " #intr "\n"                \
           /* EO STRING */                 \
           , a ## ex                       \
           , b ## ex                       \
           , res ## ex                     \
           , rlit ## ex                    \
           , a ## ex * b ## ex)

#define test(ex, type, intr) \
    decl(type, ex);          \
    out(type, ex, intr)

int main() {
    test(_F,    float,  %f);
    test(_F_L,  float,  %lf);
    test(_D_F,  double, %f);
    test(_D,    double, %lf);
    test(_LD_F, long double, %f);
    test(_LD_D, long double, %lf);

    return 0;
}
