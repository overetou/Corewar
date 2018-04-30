#!/bin/bash

make -C ../../asm_srcs && cp ../../asm_srcs/asm .

echo "\nUnknown instruction-------"
valgrind ./asm ../champs/errors/unknown_instruction.s
echo "\nWrong param number-------"
valgrind ./asm ../champs/errors/bad_param_nb.s
echo "\nWrong param type-------"
valgrind ./asm ../champs/errors/bad_param_type.s
echo "\nBad character in param-------"
valgrind ./asm ../champs/errors/bad_char_in_param.s
echo "\nNonexistent label-------"
valgrind ./asm ../champs/errors/nonexistent_label.s
echo "\nNo code-------"
valgrind ./asm ../champs/errors/no_code.s
echo "\nNo name-------"
valgrind ./asm ../champs/errors/no_name.s
echo "\nNo comment-------"
valgrind ./asm ../champs/errors/no_comment.s
echo "\nName and comment too long-------"
valgrind ./asm ../champs/errors/name_com_too_long.s
N=`echo ../champs/Asombra` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/Kappa` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/Machine-gun` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/MarineKing` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/Misaka_Mikoto` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/Rainbow_dash` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/THUNDER` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/Varimathras` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/Wall` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/_` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/_honeybadger` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/bee_gees` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/big_feet` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/big_life` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/bigzork` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/casimir` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/champ` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/corelol` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/darksasuke` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/doge` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/dubo` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/fat_42` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/fluttershy` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/gedeon` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/helltrain` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/jinx` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/justin_bee` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/littlepuppy` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/live` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/loose` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/mandragore` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/meowluigi` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/salamahenagalabadoun` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/sam_2.0` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/seg` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/skynet` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/slider2` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/Octobre_Rouge_V4.2` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/maxidef` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/jumper` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/Gagnant` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/ex` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/Car` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/barriere` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/42` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/mortel` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/terminator` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/turtle` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/ultimate-surrender` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/while_fork` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/youforkmytralala` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S
N=`echo ../champs/zork` S=`echo $N.s` COR=`echo $N.cor` && valgrind ./asm $S

 sh leaks.sh 2> leaks.txt
# grep -r "indirectly" leaks.txt
# grep -r "definitely" leaks.txt


