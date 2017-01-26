# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 13:20:03 by ccosnean          #+#    #+#              #
#    Updated: 2017/01/26 15:26:13 by ccosnean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -Llibft -lft

OBJ = *c

all: $(NAME)

$(NAME):
	@printf "\033[1;34mFDF:\033[0m Compiling..."
	@gcc $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
	@sleep .3
	@printf "\t\t[\033[0;32mCompiled\033[0m]\n"

clean: 
	@printf "\033[1;34mFDF:\033[0m Deleting files.o...\t"
	@rm -rf *.o
	@sleep .5
	@printf "[\033[0;31mDeleted\033[0m]\n"

fclean: clean
	@printf "\033[1;34mFDF:\033[0m Deleting executable\t"
	@rm -rf $(NAME)
	@sleep .5
	@printf "[\033[0;31mDeleted\033[0m]\n"

re: fclean all

lib: 
	@make re -C libft
