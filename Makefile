# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 15:33:20 by kenguyen          #+#    #+#              #
#    Updated: 2018/04/18 17:01:50 by kenguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM				= asm
DASM			= dasm
VM				= corewar

CC				= gcc
FLAGS			= -Wall -Wextra -Werror -MMD $(DFLAGS)
DFLAGS			= -g3 -fsanitize=address

SRC_ASM			= \
main.c\
op.c\
parse_args.c\
store_cmd.c\
store_header.c\
store_label.c\
store_param.c\
file_creation.c\
file_writing.c\
ft_exit.c

SRC_DASM		= \
dasm.c\
ft_parse.c

SRC_VM			= \
execute_cycle.c\
fill_players.c\
ft_add.c\
ft_aff.c\
ft_and.c\
ft_fork.c\
ft_ld.c\
ft_ldi.c\
ft_lfork.c\
ft_live.c\
ft_lld.c\
ft_lldi.c\
ft_or.c\
ft_st.c\
ft_sti.c\
ft_sub.c\
ft_void.c\
ft_xor.c\
ft_zjmp.c\
get_param_value.c\
initialize.c\
load_params.c\
ncurses.c\
process.c\
vm.c\
write_tab.c

LIB_DIR			= libft/
INC_DIR			= includes/

SRC_DIR_ASM		= srcs_asm/
SRC_DIR_DASM	= srcs_dasm/
SRC_DIR_VM		= srcs_vm/

OBJ_DIR_ASM		= objs_asm/
OBJ_DIR_DASM	= objs_dasm/
OBJ_DIR_VM		= objs_vm/

LIBFT_LIB		= $(LIB_DIR)libft.a

SRCS_ASM		= $(addprefix $(SRC_DIR_ASM), $(SRC_ASM))
SRCS_DASM		= $(addprefix $(SRC_DIR_DASM), $(SRC_DASM))
SRCS_VM			= $(addprefix $(SRC_DIR_VM), $(SRC_VM))

OBJS_ASM		= $(addprefix $(OBJ_DIR_ASM), $(SRC_ASM:.c=.o))
OBJS_DASM		= $(addprefix $(OBJ_DIR_DASM), $(SRC_DASM:.c=.o))
OBJS_VM			= $(addprefix $(OBJ_DIR_VM), $(SRC_VM:.c=.o))

INC				= $(OBJS_ASM:%.o=%.d) $(OBJS_DASM:%.o=%.d) $(OBJS_VM:%.o=%.d)

HEADER			= -I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR)

LLFT			= -L $(LIB_DIR) -lft

C_NO			= \033[00m
C_GREEN			= \033[32m
C_RED			= \033[31m
C_YELL			= \033[33m

OK1				= $(C_GREEN)✔$(C_NO)
OK2				= $(C_RED)✔$(C_NO)

all:
	@make -j -C $(LIB_DIR)
	@make $(ASM)
#	@make $(DASM)
#	@make $(VM)

$(ASM): $(LIBFT_LIB) $(OBJS_ASM)
	@$(CC) $(FLAGS) $(OBJS_ASM) $(LLFT) -o $@
	@printf "\rCompiling %-15s$(OK1)\033[K\n" "[ $@ ]"

$(OBJ_DIR_ASM):
	@mkdir -p $(OBJ_DIR_ASM)

$(OBJ_DIR_ASM)%.o: $(SRC_DIR_ASM)%.c | $(OBJ_DIR_ASM)
	@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<
	@printf "\rCompiling %-15s$<\033[K" "[ $(ASM) ]"

$(DASM): $(LIBFT_LIB) $(OBJS_DASM)
	@$(CC) $(FLAGS) $(OBJS_DASM) $(LLFT) -o $@
	@printf "\rCompiling %-15s$(OK1)\033[K\n" "[ $@ ]"

$(OBJ_DIR_DASM):
	@mkdir -p $(OBJ_DIR_DASM)

$(OBJ_DIR_DASM)%.o: $(SRC_DIR_DASM)%.c | $(OBJ_DIR_DASM)
	@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<
	@printf "\rCompiling %-15s$<\033[K" "[ $(DASM) ]"

$(VM): $(LIBFT_LIB) $(OBJS_VM)
	@$(CC) $(FLAGS) $(OBJS_VM) $(LLFT) -lncurses -o $@
	@printf "\rCompiling %-15s$(OK1)\033[K\n" "[ $@ ]"

$(OBJ_DIR_VM):
	@mkdir -p $(OBJ_DIR_VM)

$(OBJ_DIR_VM)%.o: $(SRC_DIR_VM)%.c | $(OBJ_DIR_VM)
	@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<
	@printf "\rCompiling %-15s$<\033[K" "[ $(VM) ]"

clean: cor
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR_ASM) $(OBJ_DIR_DASM) $(OBJ_DIR_VM)
	@printf "%-25s$(OK2)\n" "Cleaning  [ corewar ]"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(ASM) $(DASM) $(VM)
	@printf "%-25s$(OK2)\n" "Delete    [ corewar ]"

re: fclean
	@make

.s: cor
	@./asm *.s

cor:
	@find . -name '*.cor' -delete
	@printf "%-25s$(OK2)\n" "Cleaning  [ .cor ]"

.PHONY: all fclean clean re cor .s
-include $(INC)
