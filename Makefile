# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 15:33:20 by kenguyen          #+#    #+#              #
#    Updated: 2018/04/05 16:37:17 by ysingaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM				= asm
DASM			= dasm
VM				= corewar

CC				= gcc
FLAGS			= -Wall -Wextra -Werror #$(DFLAGS)
DFLAGS			= -g3 -fsanitize=address

SRC_ASM			= \
main.c\
op.c\
parsing.c\
cmd.c\
label.c\
param.c\
store_label.c\
error.c\
file_creation.c\
writing.c\
processing.c

SRC_DASM		= \
dasm.c

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


SRC_INC			= \
asm.h\
dasm.h\
vm.h\
op.h

LIB_DIR			= libft/
INC_DIR			= includes/

SRC_DIR_ASM		= srcs_asm/
SRC_DIR_DASM	= srcs_dasm/
SRC_DIR_VM		= srcs_vm/

OBJ_DIR_ASM		= objs_asm/
OBJ_DIR_DASM	= objs_dasm/
OBJ_DIR_VM		= objs_vm/

LIBFT_LIB		= $(LIB_DIR)libft.a

SRCS_INC		= $(addprefix $(INC_DIR), $(SRC_INC))

SRCS_ASM		= $(addprefix $(SRC_DIR_ASM), $(SRC_ASM))
SRCS_DASM		= $(addprefix $(SRC_DIR_DASM), $(SRC_DASM))
SRCS_VM			= $(addprefix $(SRC_DIR_VM), $(SRC_VM))

OBJS_ASM		= $(addprefix $(OBJ_DIR_ASM), $(SRC_ASM:.c=.o))
OBJS_DASM		= $(addprefix $(OBJ_DIR_DASM), $(SRC_DASM:.c=.o))
OBJS_VM			= $(addprefix $(OBJ_DIR_VM), $(SRC_VM:.c=.o))

HEADER			= -I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR)

C_NO			= "\033[00m"
C_GREEN			= "\033[32m"
C_RED			= "\033[31m"
C_YELL			= "\033[33m"

SUCCESS			= $(C_GREEN)SUCCESS$(C_NO)
OK				= $(C_YELL)OK$(C_NO)
RM				= $(C_RED)OK$(C_NO)

all: lib $(ASM) $(DASM) $(VM)

lib:
	@make -j -C $(LIB_DIR)

$(ASM): $(LIBFT_LIB) $(OBJS_ASM)
	@$(CC) $(FLAGS) $(OBJS_ASM) $(LIBFT_LIB) -o $@
	@echo "Compiling" [ $@ ] $(SUCCESS)

$(OBJ_DIR_ASM)%.o: $(SRC_DIR_ASM)%.c $(SRCS_INC)
	@mkdir -p $(OBJ_DIR_ASM)
	@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<
	@echo "Linking" [ $< ] $(OK)

$(DASM): $(LIBFT_LIB) $(OBJS_DASM)
	@$(CC) $(FLAGS) $(OBJS_DASM) $(LIBFT_LIB) -o $@
	@echo "Compiling" [ $@ ] $(SUCCESS)

$(OBJ_DIR_DASM)%.o: $(SRC_DIR_DASM)%.c $(SRCS_INC)
	@mkdir -p $(OBJ_DIR_DASM)
	@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<
	@echo "Linking" [ $< ] $(OK)

$(VM): $(LIBFT_LIB) $(OBJS_VM)
	@$(CC) $(FLAGS) $(OBJS_VM) $(LIBFT_LIB) -lncurses -o $@
	@echo "Compiling" [ $@ ] $(SUCCESS)

$(OBJ_DIR_VM)%.o: $(SRC_DIR_VM)%.c $(SRCS_INC)
	@mkdir -p $(OBJ_DIR_VM)
	@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<
	@echo "Linking" [ $< ] $(OK)

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR_ASM) $(OBJ_DIR_DASM) $(OBJ_DIR_VM)
	@echo "Cleaning" [ objs_asm \& objs_vm ] $(RM)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(ASM) $(DASM) $(VM)
	@echo "Delete" [ asm \& corewar ] $(RM)

re: fclean all

.PHONY: all fclean clean re lib
