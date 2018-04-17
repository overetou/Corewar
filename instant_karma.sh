#!/bin/bash

./corewar $1 -debug > us
./ressources/corewar $1 -v 4 > zaz
sed -i '' '1,2d' zaz
sed -i '' '/0x1000 :/d' us
if [ -z "`diff --suppress-common-lines us zaz`" ]
then
    echo "No difference !"
else
    diff zaz us -y > dif_file
    echo "There is a diff."
fi
