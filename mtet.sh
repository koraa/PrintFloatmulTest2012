#! /bin/bash

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

                eval $CMD 2>&1 | tee -a "$COMPO" > /dev/null
                mtet
            done
        done
    done
done
