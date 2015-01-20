# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 10:54:30 by ibakayok          #+#    #+#              #
#    Updated: 2015/01/11 20:40:48 by tbalea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= ft_retro

SRC 		= CElement.cpp				\
			  Entity.Class.cpp			\
			  EntityMoving.class.cpp	\
			  EntityShoot.class.cpp		\
			  main.cpp					\


OBJ			= $(SRC:%.c=.obj/%.o)

FLAGS = -Wall -Wextra -Werror -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	@g++ $(FLAGS) -o $(NAME) $(OBJ)

start:
	@echo  "$(OK_COLOR)COMPILING-----EXE"


.obj/%.o: %.c
		@mkdir -p .obj/
		@g++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf .obj/
	@/bin/rm -f libft/libft.a

fclean: clean
	@/bin/rm -f $(NAME)


re: fclean all


.PHONY: all fclean clean re

