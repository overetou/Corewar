#!/bin/bash

make -C ../../asm_srcs && cp ../../asm_srcs/asm .

echo "\nUnknown instruction-------"
./asm ../champs/errors/unknown_instruction.s
echo "\nWrong param number-------"
./asm ../champs/errors/bad_param_nb.s
echo "\nWrong param type-------"
./asm ../champs/errors/bad_param_type.s
echo "\nBad character in param-------"
./asm ../champs/errors/bad_char_in_param.s
echo "\nBad character in label-------"
./asm ../champs/errors/bad_char_in_label.s
echo "\nNonexistent label-------"
./asm ../champs/errors/nonexistent_label.s
echo "\nNo code-------"
./asm ../champs/errors/no_code.s
echo "\nNo name-------"
./asm ../champs/errors/no_name.s
echo "\nNo comment-------"
./asm ../champs/errors/no_comment.s
echo "\nName and comment too long-------"
./asm ../champs/errors/name_com_too_long.s


