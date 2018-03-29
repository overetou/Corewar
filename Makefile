# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 15:33:20 by kenguyen          #+#    #+#              #
#    Updated: 2018/03/29 17:13:56 by kenguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM			= asm
VM			= corewar

CC			= gcc
FLAGS		= -Wall -Wextra -Werror #$(DFLAGS)
DFLAGS		= -g3 -fsanitize=address

SRC_ASM		= \
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

SRC_VM		= \
vm.c

SRC_INC		= \
asm.h\
vm.h\
op.h

LIB_DIR		= libft/
INC_DIR		= includes/

SRC_DIR_ASM	= srcs_asm/
SRC_DIR_VM	= srcs_vm/

OBJ_DIR_ASM	= objs_asm/
OBJ_DIR_VM	= objs_vm/

LIBFT_LIB	= $(LIB_DIR)libft.a

SRCS_INC	= $(addprefix $(INC_DIR), $(SRC_INC))

SRCS_ASM	= $(addprefix $(SRC_DIR_ASM), $(SRC_ASM))
SRCS_VM		= $(addprefix $(SRC_DIR_VM), $(SRC_VM))

OBJS_ASM	= $(addprefix $(OBJ_DIR_ASM), $(SRC_ASM:.c=.o))
OBJS_VM		= $(addprefix $(OBJ_DIR_VM), $(SRC_VM:.c=.o))

HEADER		= -I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR)

C_NO		= "\033[00m"
C_GREEN		= "\033[32m"
C_RED		= "\033[31m"
C_YELL		= "\033[33m"

SUCCESS		= $(C_GREEN)SUCCESS$(C_NO)
OK			= $(C_YELL)OK$(C_NO)
RM			= $(C_RED)OK$(C_NO)

all: lib $(ASM) $(VM)

lib:
	@make -j -C $(LIB_DIR)

$(ASM): $(LIBFT_LIB) $(OBJS_ASM)
	@$(CC) $(FLAGS) $(OBJS_ASM) $(LIBFT_LIB) -o $@
	@echo "Compiling" [ $@ ] $(SUCCESS)

$(OBJ_DIR_ASM)%.o: $(SRC_DIR_ASM)%.c $(SRCS_INC)
	@mkdir -p $(OBJ_DIR_ASM)
	@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<
	@echo "Linking" [ $< ] $(OK)

$(VM): $(LIBFT_LIB) $(OBJS_VM)
	@$(CC) $(FLAGS) $(OBJS_VM) $(LIBFT_LIB) -o $@
	@echo "Compiling" [ $@ ] $(SUCCESS)

$(OBJ_DIR_VM)%.o: $(SRC_DIR_VM)%.c $(SRCS_INC)
	@mkdir -p $(OBJ_DIR_VM)
	@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<
	@echo "Linking" [ $< ] $(OK)

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR_ASM) $(OBJ_DIR_VM)
	@echo "Cleaning" [ objs_asm \& objs_vm ] $(RM)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(ASM) $(VM)
	@echo "Delete" [ asm \& corewar ] $(RM)

re: fclean all

.PHONY: all fclean clean re lib
