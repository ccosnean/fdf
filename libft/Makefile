# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/05 13:02:21 by ccosnean          #+#    #+#              #
#    Updated: 2017/01/26 15:03:14 by ccosnean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FT_MEM = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c
FT_STR = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c
FT_STR += ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_tolower.c ft_toupper.c
FT_IS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
FT_ADD = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c
FT_ADD += ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c
FT_PUT = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
FT_BONUS = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			ft_strrev.c ft_memcpy_b.c ft_nbrlen.c get_next_line.c
SRC = $(FT_MEM) $(FT_STR) $(FT_IS) $(FT_ADD) $(FT_PUT) $(FT_BONUS)
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\033[0;32mLIBFT:\033[0m Creating libft.a..."
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\t[\033[0;32mCreated\033[0m]\n"

$(OBJ) :
	@$(CC) -c $(FLAGS) -o $@ $*.c

clean :
	@printf "\033[0;32mLIBFT:\033[0m Deleting Files.o"
	@rm -rf $(OBJ)
	@printf "\t\t[\033[0;31mDeleted\033[0m]\n"

fclean: clean
	@printf "\033[0;32mLIBFT:\033[0m Deleting libft.a"
	@rm -rf $(NAME)
	@printf "\t\t[\033[0;31mDeleted\033[0m]\n"

re: fclean all

.PHONY: clean
