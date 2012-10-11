/*
 * PrintFloatmulTest2012 - A small utility to test the behaiviour of printf with a speciql float multiplication
 * Written in 2012 by Karolin Varner <karo@cupdev.net>
 * To the extent possible under law, the author(s) have dedicated all copyright and related and neighboring rights to this software to the public domain worldwide. This software is distributed without any warranty.
 * You should have received a copy of the CC0 Public Domain Dedication along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

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
