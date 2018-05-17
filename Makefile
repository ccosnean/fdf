# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 13:20:03 by ccosnean          #+#    #+#              #
#    Updated: 2017/03/11 13:38:35 by ccosnean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror 

OBJ = *c

all: $(NAME)

$(NAME):
	@make -C libft
	@printf "\033[1;34mFDF:\033[0m Compiling..."
	@gcc $(FLAGS) -c $(OBJ)
	@gcc *.o mlx/libmlx.a -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)
	@zsh created.sh

clean: 
	@printf "\033[1;34mFDF:\033[0m Deleting files.o...\t"
	@rm -rf *.o
	@zsh deleted.sh
	@make clean -C libft

fclean: clean
	@printf "\033[1;34mFDF:\033[0m Deleting executable\t"
	@rm -rf $(NAME)
	@zsh deleted.sh
	@make fclean -C libft

fast: 
	@printf "\033[1;34mFDF:\033[0m Compiling..."
	@gcc $(FLAGS) -c $(OBJ)
	@gcc *.o mlx/libmlx.a -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)
	@zsh created.sh

libft: 
	@make -C libft

re: fclean all

