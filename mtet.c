/*
 * PrintFloatmulTest2012 - A small utility to test the behaiviour of printf with a speciql float multiplication
 * Written in 2012 by Karolin Varner <karo@cupdev.net>
 * To the extent possible under law, the author(s) have dedicated all copyright and related and neighboring rights to this software to the public domain worldwide. This software is distributed without any warranty.
 * You should have received a copy of the CC0 Public Domain Dedication along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#include <stdio.h>

#define aL 100000
#define bL 333333

#define decl(type, ex)                                      \
    type a ## ex = aL,                                      \
         b ## ex = bL,                                      \
         res ## ex  = (( type )  a ## ex   *   b ## ex ) ,  \
         rlit ## ex = (( type )  ((long) aL) * bL)

#define out(from, ex, cast, intr)          \
    printf( #from " -> "                   \
            #cast " -> "                   \
           /* FORMAT STRING */             \
           "%" #intr ": "                  \
           "[" #intr ", " #intr "]"        \
           " = " #intr                     \
           " = " #intr                     \
           " = " #intr "\n"                \
           /* EO STRING */                 \
           , (( cast ) a ## ex )           \
           , (( cast ) b ## ex )           \
           , (( cast ) res ## ex )         \
           , (( cast ) rlit ## ex )        \
           , (( cast ) a ## ex * b ## ex) )

#define test(ex, type, cast, intr) \
    decl(type, ex);                \
    out(type, ex, cast, intr)

int main() {
    // NO CAST
    test(_F,    float,  float, %f);
    test(_F_L,  float,  float, %lf);
    test(_D_F,  double, double, %f);
    test(_D,    double, double, %lf);

    // LONG DOUBLE
    test(_LD_F, long double, long double, %f);
    test(_LD_D, long double, long double, %lf);

    // CAST
    test(_CS_F,    float,  double, %f);
    test(_CS_F_L,  float,  double, %lf);
    test(_CS_D_F,  double, float,  %f);
    test(_CS_D,    double, float,  %lf);

    return 0;
}
