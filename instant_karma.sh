#!/bin/bash

./corewar $1 $2 $3 $4 -debug > us
./ressources/corewar $1 $2 $3 $4 -v 4 > zaz
sed -i '' '1d' zaz
sed -i '' '/\*/d' zaz
if [ -z "`diff --suppress-common-lines us zaz`" ]
then
    echo "No difference !"
else
    diff zaz us -y > dif_file
    egrep 'lld' -m 1 -n dif_file
    egrep ' [><]' -m 1 -n dif_file
    egrep '[|].*[|].*[|]' -m 1 -n dif_file
    echo "There is a diff."
fi
