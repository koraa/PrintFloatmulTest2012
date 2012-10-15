#! /bin/bash

#
# PrintFloatmulTest2012 - A small utility to test the behaiviour of
#                         printf with a speciql float multiplication
#
# Written in 2012 by Karolin Varner <karo@cupdev.net>
# To the extent possible under law, the author(s) have dedicated all copyright
# and related and neighboring rights to this software to the public domain worldwide. 
# This software is distributed without any warranty.
#
# You should have received a copy of the CC0 Public Domain Dedication along with this software.
# If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#

# TODO: Dig into the formatter with gcc
# TODO: Compare Headers/STDLIB code for different palltforms


COMPO="`date '+%Y.%m.%d:%H:%m'`-gcc.out"
STD="c90 c89 iso9899:1990 iso9899:199409 c99 c9x iso9899:1999 iso9899:199x c1x gnu90 gnu89 gnu99 gnu++98 c++0x C++0x gnu++0x"

# Optimization seems _not_ to affect floats Optimization seems _not_ to affect floats
# OPTIM="0"
OPTIM="0 1 2 3 s fast z 4"

LANG="c c++"

COMPILER="gcc clang"

for _comp_ in $COMPILER; do
    for _lang_ in $LANG; do
        for _std_ in $STD; do
            for _o_ in $OPTIM; do
                CMD="$_comp_ -x$_lang_ -O$_o_ --std=$_std_ *.c -o mtet"
                
                echo ""                             |  tee -a "$COMPO"
                echo "############################" |  tee -a "$COMPO"
                echo "$CMD"                         |  tee -a "$COMPO"
                echo ""                             |  tee -a "$COMPO"

                eval $CMD 2>&1 | tee -a "$COMPO" > /dev/null && ./mtet
            done
        done
    done
done

CMD="i586-mingw32msvc-gcc -x$_lang_ -O$_o_ *.c -o mtet.exe"

echo ""                             |  tee -a "$COMPO"
echo "############################" |  tee -a "$COMPO"
echo "$CMD"                         |  tee -a "$COMPO"
echo ""                             |  tee -a "$COMPO"

eval $CMD 2>&1 | tee -a "$COMPO" > /dev/null && wine mtet.exe
