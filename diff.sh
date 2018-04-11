#!/bin/bash

let "i = 0"
rm zaz us
touch zaz
touch us
let "i = $2"
./corewar $1 -dump $i > us
./ressource/corewar $1 -d $i > zaz
sed -i '' '1,2d' zaz
sed -i '' '/0x1000 :/d' us
echo $i
while [ -z "`diff --suppress-common-lines us zaz`" ]
do
	let "i++"
	./corewar $1 -dump $i > us
	./ressource/corewar $1 -d $i > zaz
	sed -i '' '1,2d' zaz
	sed -i '' '/0x1000 :/d' us
	echo $i
done
echo ">>>>>>>>>>>>>>>>>> stop = $i"
diff us zaz
