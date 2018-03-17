# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 15:33:20 by kenguyen          #+#    #+#              #
#    Updated: 2018/03/17 01:10:23 by kenguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= a.out

CC		= gcc
FLAGS	= -Wall -Wextra -Werror #$(DFLAGS)
DFLAGS	= -g3 -fsanitize=address

SRC_BASE = \
main.c

INC_BASE = corewar.h

CUR_DIR	= Corewar/
SRC_DIR	= srcs/
OBJ_DIR	= objs/
INC_DIR	= includes/
LIB_DIR	= libft/

LIBFT_LIB = $(LIB_DIR)libft.a

SRCS	= $(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS	= $(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

C_NO	= "\033[00m"
C_GREEN	= "\033[32m"
C_RED	= "\033[31m"
C_YELL	= "\033[33m"

SUCCESS	= $(C_GREEN)SUCCESS$(C_NO)
OK		= $(C_YELL)OK$(C_NO)
RM		= $(C_RED)OK$(C_NO)

all: lib $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) \
		-I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR) \
		$(LIBFT_LIB) $(FLAGS)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)
	@./a.out | cat -e

lib:
	@make -j -C $(LIB_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)$(INC_BASE)
	@$(CC) $(FLAGS) -I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR) -c $< -o $@
	@echo "Linking" [ $< ] $(OK)

cleanlib:
	@make -C $(LIB_DIR) clean

fcleanlib:
	@make -C $(LIB_DIR) fclean

clean: cleanlib
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning" [ $(CUR_DIR)objs ] $(RM)

fclean: clean fcleanlib
	@rm -rf $(NAME)
	@echo "Delete" [ $(NAME) ] $(RM)

re: fclean all

.PHONY: fclean clean fcleanlib cleanlib re lib
