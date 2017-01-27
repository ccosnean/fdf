# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 13:20:03 by ccosnean          #+#    #+#              #
#    Updated: 2017/01/27 18:25:45 by ccosnean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror 

OBJ = *c

all: $(NAME)

$(NAME):
	@printf "\033[1;34mFDF:\033[0m Compiling..."
	@gcc $(FLAGS) -c $(OBJ)
	@gcc *.o -Llibft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@zsh created.sh

clean: 
	@printf "\033[1;34mFDF:\033[0m Deleting files.o...\t"
	@rm -rf *.o
	@zsh deleted.sh

fclean: clean
	@printf "\033[1;34mFDF:\033[0m Deleting executable\t"
	@rm -rf $(NAME)
	@zsh deleted.sh

re: fclean all

lib: 
	@make re -C libft
