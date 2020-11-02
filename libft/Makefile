# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apouchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/21 15:42:31 by apouchet          #+#    #+#              #
#    Updated: 2020/11/02 16:53:56 by apouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME), all, clean, fclean, re

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

INC = src/include

SRC_ELSE = ./src/else/ft_atof.c ./src/else/ft_atoi.c ./src/else/ft_atol.c \
./src/else/ft_atost.c ./src/else/ft_bzero.c ./src/else/ft_count_word.c \
./src/else/ft_count_word_char.c ./src/else/ft_find_space.c ./src/else/ft_itoa.c \
./src/else/ft_nbalpha.c ./src/else/ft_nbrlen.c ./src/else/ft_nbrlen_base.c \
./src/else/ft_nbrlen_base_unsigned.c ./src/else/ft_nbrlen_unsigned.c \
./src/else/ft_pow.c ./src/else/ft_tolower.c ./src/else/ft_toupper.c \
./src/else/ft_unicode.c ./src/else/ft_unicode_len.c ./src/else/ft_while_char.c \
./src/else/ft_while_not_char.c ./src/else/ft_while_space.c \
./src/else/ft_ulltoa.c ./src/else/ft_itoa_unsigned_base.c \
./src/else/ft_itoa_base.c

SRC_IS = ./src/is/ft_isalnum.c ./src/is/ft_isalpha.c ./src/is/ft_isascii.c \
./src/is/ft_ischar.c ./src/is/ft_isdigit.c ./src/is/ft_islower.c \
./src/is/ft_isprint.c ./src/is/ft_isspace.c ./src/is/ft_isupper.c

SRC_MEM = ./src/mem/ft_memalloc.c ./src/mem/ft_memccpy.c ./src/mem/ft_memchr.c \
./src/mem/ft_memcmp.c ./src/mem/ft_memcpy.c ./src/mem/ft_memdel.c \
./src/mem/ft_memdup.c ./src/mem/ft_memmove.c ./src/mem/ft_memset.c

SRC_PUT = ./src/put/ft_putchar.c ./src/put/ft_putchar_fd.c \
./src/put/ft_putendl.c ./src/put/ft_putendl_fd.c ./src/put/ft_putnbr.c \
./src/put/ft_putnbr_fd.c ./src/put/ft_putstr.c ./src/put/ft_putstr_fd.c

SRC_STR = ./src/str/ft_str_replace.c ./src/str/ft_strcat.c \
./src/str/ft_strchr.c ./src/str/ft_strclr.c ./src/str/ft_strcmp.c \
./src/str/ft_strcpy.c ./src/str/ft_strdel.c ./src/str/ft_strdup.c \
./src/str/ft_strdup_free.c ./src/str/ft_strequ.c ./src/str/ft_striter.c \
./src/str/ft_striteri.c ./src/str/ft_strjoin.c ./src/str/ft_strjoin_free.c \
./src/str/ft_strlcat.c ./src/str/ft_strlen.c ./src/str/ft_strlen_find.c \
./src/str/ft_strmap.c ./src/str/ft_strmapi.c ./src/str/ft_strnbstr.c \
./src/str/ft_strncat.c ./src/str/ft_strncmp.c ./src/str/ft_strncpy.c \
./src/str/ft_strndup.c ./src/str/ft_strndup_free.c ./src/str/ft_strnequ.c \
./src/str/ft_strnew.c ./src/str/ft_strnstr.c ./src/str/ft_strrchr.c \
./src/str/ft_strsplit.c ./src/str/ft_strstr.c ./src/str/ft_strsub.c \
./src/str/ft_strsub_free.c ./src/str/ft_strtrim.c ./src/str/ft_strwellspace.c

SRC_LST = ./src/lst/ft_list_push_front.c ./src/lst/ft_lstadd.c \
./src/lst/ft_lstdel.c ./src/lst/ft_lstdelone.c ./src/lst/ft_lstiter.c \
./src/lst/ft_lstmap.c ./src/lst/ft_lstnew.c

SRC_PTF = ./src/ft_printf/decalage.c ./src/ft_printf/else.c \
./src/ft_printf/ft_nombre.c ./src/ft_printf/ft_printf.c \
./src/ft_printf/ft_printf_char.c ./src/ft_printf/ft_printf_nb.c \


SRC_GNL = ./src/gnl/get_next_line.c

OBJ_ELSE = $(SRC_ELSE:.c=.o)
OBJ_IS = $(SRC_IS:.c=.o)
OBJ_MEM = $(SRC_MEM:.c=.o)
OBJ_PUT = $(SRC_PUT:.c=.o)
OBJ_STR = $(SRC_STR:.c=.o)
OBJ_LST = $(SRC_LST:.c=.o)
OBJ_PTF = $(SRC_PTF:.c=.o)
OBJ_GNL = $(SRC_GNL:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ_ELSE) $(OBJ_IS) $(OBJ_MEM) $(OBJ_PUT) $(OBJ_STR) $(OBJ_LST) $(OBJ_PTF) $(OBJ_GNL)
	@echo ""
	@ar rc $(NAME) $(OBJ_ELSE) $(OBJ_IS) $(OBJ_MEM) $(OBJ_PUT) $(OBJ_STR) $(OBJ_LST) $(OBJ_PTF) $(OBJ_GNL)
	@ranlib $(NAME)
	@echo "Creation libft.a"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC)
	@printf "\033[1;32m+\033[0m"

clean :
	@rm -rf $(OBJ_ELSE)
	@rm -rf $(OBJ_IS)
	@rm -rf $(OBJ_MEM)
	@rm -rf $(OBJ_PUT)
	@rm -rf $(OBJ_STR)
	@rm -rf $(OBJ_LST)
	@rm -rf $(OBJ_PTF)
	@rm -rf $(OBJ_GNL)

fclean : clean
	@rm -rf $(NAME)

re : fclean $(NAME)

