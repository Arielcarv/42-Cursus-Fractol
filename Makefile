# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 22:31:07 by arcarval          #+#    #+#              #
#    Updated: 2023/08/22 16:35:37 by arcarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
BLACK				=	\033[0;30m
BLUE				=	\033[0;34m
CYAN				=	\033[0;36m
GREEN				=	\033[0;32m
MAGENTA				=	\033[1;35m
ORANGE				=	\033[1;38;5;214m
RED					=	\033[0;31m
RESET				=	\033[0m
WHITE				=	\033[0;37m
YELLOW				=	\033[0;33m

# FRACTOL
NAME				=	fractol
HEADER				=	fractol.h
LIBFT				=	./Libft/libft.a
FT_PRINTF			=	./ft_printf/libftprintf.a
LIBRARIES			=	./libraries/
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror

FRACTOL_SRCS		=	fractol.c initialize.c hooks.c utilities.c \
						validations.c mandelbrot.c julia.c
FRACTOL_OBJS		=	$(FRACTOL_SRCS:%.c=%.o)

FRACTOL_BONUS_SRCS	=	fractol_bonus.c initialize.c hooks.c utilities.c \
						validations_bonus.c mandelbrot.c julia.c burning_ship.c
FRACTOL_BONUS_OBJS	=	$(FRACTOL_BONUS_SRCS:%.c=%.o)

AR					=	ar -rcs
RM					=	rm -rf

####################
####  SELECT OS ####
####################
ifeq ($(shell uname), Linux)
	MLX = minilibx-linux
	MLX_LINKS = -lbsd -I$(LIBRARIES)$(MLX) -L$(LIBRARIES)$(MLX) $(LIBRARIES)$(MLX)/libmlx_Linux.a -L/usr/lib -lmlx -lXext -lX11 -lm -lz
else ifeq ($(shell uname), Darwin)
	MLX = minilibx-macos
	MLX_LINKS = -I$(LIBRARIES)$(MLX) -L$(LIBRARIES)$(MLX) -lmlx -framework OpenGL -framework AppKit
endif

%.o : %.c
				@echo "$(ORANGE) Compiling  ➟  $(BLUE)$< $(WHITE)"
				@$(CC) $(CFLAGS) -I/usr/include -I$(LIBRARIES)$(MLX) -c $< -o $@

$(NAME):		minilibx libft printf $(FRACTOL_OBJS)
				$(CC) $(FRACTOL_OBJS) $(MLX_LINKS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
				@echo "$(CYAN) FRACTOL - I'm ready to work! 🧠$(RESET)"

bonus:			minilibx libft printf $(FRACTOL_BONUS_OBJS)
				$(CC) $(FRACTOL_BONUS_OBJS) $(MLX_LINKS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
				@echo "$(CYAN) FRACTOL - I'm ready to work! 🧠$(RESET)"

minilibx:
				cd libraries && tar -xvf minilibx-linux.tgz
				@make -C $(LIBRARIES)$(MLX)

libft:
				@make -C Libft

printf:
				@make -C ft_printf

all:			$(NAME)

bonus:			bonus

clean:
				@$(RM) $(FRACTOL_OBJS) $(FRACTOL_BONUS_OBJS)
				@echo "$(CYAN) FRACTOL - Bye Laziness, Bye dirt 🚿$(RESET)"

fclean:			clean
				@$(RM) $(NAME)
				@make fclean -C Libft
				@make fclean -C ft_printf
				@make clean -C $(LIBRARIES)$(MLX)
				@echo "$(CYAN) FRACTOL - Bath is so good!  Now it's over. 🧼✨$(RESET)"

nn:
				norminette -R CheckForbiddenSourceHeader $(FRACTOL_SRCS) $(HEADER) ./Libft/*.c ./Libft/*.h ./ft_printf/*.c ./ft_printf/*.h

re:				fclean all

.PHONY:	all $(NAME) libft printf bonus clean fclean re
