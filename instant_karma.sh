#!/bin/bash

./corewar $1 -dump $i -v 4 > us
./ressources/corewar $1 -d $i -v 4 > zaz
sed -i '' '1,2d' zaz
sed -i '' '/0x1000 :/d' us
if [ -z "`diff --suppress-common-lines us zaz`" ]
then
    echo "No difference !"
else
    diff zaz us -y > dif_file
    echo "FAIL -> first difference spotted at line : `grep -n -m 1 "[|<>]" ./dif_file | sed  's/\([0-9]*\).*/\1/'`"
fi
