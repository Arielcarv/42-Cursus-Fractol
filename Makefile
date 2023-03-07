# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 22:31:07 by arcarval          #+#    #+#              #
#    Updated: 2023/03/06 23:39:09 by arcarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
BLACK			=	\033[0;30m
BLUE			=	\033[0;34m
CYAN			=	\033[0;36m
GREEN			=	\033[0;32m
MAGENTA			=	\033[1;35m
ORANGE			=	\033[1;38;5;214m
RED				=	\033[0;31m
RESET			=	\033[0m
WHITE			=	\033[0;37m
YELLOW			=	\033[0;33m

# FRACTOL
NAME			=	fractol
LIBFT			=	./Libft/libft.a
MLX				=	./libraries/minilibx-linux
HEADER			=	fractol.h
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			=	

FRACTOL_SRCS	=	fractol.c
FRACTOL_OBJS	=	$(FRACTOL_SRCS:.c=.o)

AR				=	ar -rcs
RM				=	rm -rf

%.o : %.c
				@echo "$(ORANGE) Compiling  ➟  $(BLUE)$< $(WHITE)"
				$(CC) $(CFLAGS) -I/usr/include -I$(MLX) -O3 -c $< -o $@

$(NAME): 		minilibx libft $(FRACTOL_OBJS)
				$(CC) $(FRACTOL_OBJS) -L$(MLX) -lmlx -L /usr/lib -I$(MLX) -lXext -lX11 -lm -lz -o $(NAME)

libft: 
				@make -C Libft

minilibx:
				@make -C $(MLX)

all:			$(NAME)

clean:
				@$(RM) $(FRACTOL_OBJS)
				@echo "$(CYAN) FRACTOL - Bye Laziness, Bye dirt 🚿$(RESET)"

fclean:			clean
				@$(RM) $(NAME)
				@make fclean -C Libft
				@make clean -C $(MLX)
				@echo "$(CYAN) FRACTOL - Bath is so good!  Now it's over. 🧼✨$(RESET)"

nn:
				norminette -CheckForbiddenSourceHeader $(FRACTOL_SRCS) $(HEADER) ./Libft/*.c ./Libft/*.h

re:				fclean all

.PHONY:	all $(NAME) libft printf bonus clean fclean re
