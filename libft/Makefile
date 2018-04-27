# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 15:33:20 by kenguyen          #+#    #+#              #
#    Updated: 2018/04/09 10:50:36 by kenguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc
FLAGS	= -Wall -Wextra -Werror -MMD -g -g3 -fsanitize=address

SRC_BASE = \
char/ft_charcspn.c\
char/ft_isalnum.c\
char/ft_isalpha.c\
char/ft_isblank.c\
char/ft_isascii.c\
char/ft_isdigit.c\
char/ft_isprint.c\
char/ft_isspace.c\
char/ft_tolower.c\
char/ft_toupper.c\
convert/ft_atoi.c\
convert/ft_itoa.c \
convert/ft_itoa_base.c \
convert/ft_ltoa.c\
convert/ft_ltoa_base.c\
convert/ft_uitoa.c\
convert/ft_uitoa_base.c\
convert/ft_ultoa.c\
convert/ft_ultoa_base.c\
get_next_line/get_next_line.c\
lst/ft_lstadd.c\
lst/ft_lstdel.c\
lst/ft_lstdelone.c\
lst/ft_lstiter.c\
lst/ft_lstmap.c\
lst/ft_lstnew.c\
mem/ft_bzero.c\
mem/ft_memalloc.c\
mem/ft_memccpy.c\
mem/ft_memchr.c\
mem/ft_memcmp.c\
mem/ft_memcpy.c\
mem/ft_memdel.c\
mem/ft_memmove.c\
mem/ft_memset.c\
output/ft_putchar_fd.c\
output/ft_putchar.c\
output/ft_putendl_fd.c\
output/ft_putendl.c\
output/ft_putnbr_fd.c\
output/ft_putnbr.c\
output/ft_putstr_fd.c\
output/ft_putstr.c\
printf/ft_printf.c\
printf/pf_conv.c\
printf/pf_conv_etc.c\
printf/pf_fill_buff.c\
printf/pf_parse_args.c\
printf/pf_print_base.c\
printf/pf_print_char.c\
printf/pf_print_digit.c\
printf/pf_print_invalid.c\
printf/pf_print_ptraddr.c\
printf/pf_print_str.c\
printf/pf_print_wchar.c\
printf/pf_print_wstr.c\
str/ft_str_is_lowercase.c\
str/ft_str_is_numeric.c\
str/ft_str_is_uppercase.c\
str/ft_strcat.c\
str/ft_strchr.c\
str/ft_strclr.c\
str/ft_strcmp.c\
str/ft_strcpy.c\
str/ft_strcspn.c\
str/ft_strdel.c\
str/ft_strdup.c\
str/ft_strequ.c\
str/ft_striter.c\
str/ft_striteri.c\
str/ft_strjoin.c\
str/ft_strlcat.c\
str/ft_strlen.c\
str/ft_strlower.c\
str/ft_strmap.c\
str/ft_strmapi.c\
str/ft_strncat.c\
str/ft_strncmp.c\
str/ft_strncpy.c\
str/ft_strndup.c\
str/ft_strnequ.c\
str/ft_strnew.c\
str/ft_strnstr.c\
str/ft_strrchr.c\
str/ft_strrev.c\
str/ft_strsplit.c\
str/ft_strsplitdel.c\
str/ft_strspn.c\
str/ft_strstr.c\
str/ft_strsub.c\
str/ft_strtrim_space.c\
str/ft_strtrim.c

CUR_DIR	= libft/
SRC_DIR	= srcs/
OBJ_DIR	= objs/
INC_DIR	= includes/

SRCS	= $(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS	= $(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

INC		= $(OBJS:%.o=%.d)

C_NO	= \033[00m
C_RED	= \033[31m
C_GREEN	= \033[32m
C_CYAN	= \033[36m

OK1		= $(C_GREEN)✔$(C_NO)
OK2		= $(C_RED)✔$(C_NO)

all:
	@make $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rcs $@ $(OBJS)
	@printf "\rCompiling %-15s$(OK1)\033[K\n" "[ $@ ]"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $(FLAGS) -I $(INC_DIR) $< -o $@
	@printf "\rCompiling %-15s$<\033[K" "[ $(NAME) ]"

clean:
	@if [ -e $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi;

fclean: clean
	@if [ -e $(NAME) ]; then rm -f $(NAME); fi;

re: fclean
	@make $(NAME)

.PHONY: all fclean clean re
-include $(INC)
