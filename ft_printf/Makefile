# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 23:15:46 by arcarval          #+#    #+#              #
#    Updated: 2023/02/27 19:35:27 by arcarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
BLACK	=	\033[0;30m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
GREEN	=	\033[0;32m
MAGENTA	=	\033[1;35m
ORANGE	=	\033[1;38;5;214m
RED		=	\033[0;31m
RESET	=	\033[0m
WHITE	=	\033[0;37m
YELLOW	=	\033[0;33m

# FT_PRINTF
NAME	=	libftprintf.a
HEADER	=	ft_printf.h
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

LIBFT_SRCS	=	ft_putchar_printf.c		ft_putnbr_printf.c	\
				ft_putnbr_unsigned_fd.c	ft_strlen_printf.c	\
				ft_putstr_printf.c

LIBFT_OBJS	=	$(addprefix Libft/, $(LIBFT_SRCS:.c=.o))

PRINTF_SRCS	=	ft_printf.c	ft_puthex_printf.c	ft_putpointer_printf.c	ft_puthex_printf.c
PRINTF_OBJS	=	$(PRINTF_SRCS:.c=.o)
PRINTF_OBJS	+=	$(LIBFT_OBJS)

AR		=	ar -rcs
RM		=	rm -rf

.c.o:
			@echo "$(ORANGE) Compiling  ➟  $(BLUE)$< $(RESET)"
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(PRINTF_OBJS) $(HEADER)
			@echo "$(MAGENTA)\n $(NAME)  🗄️  🗃️  Archived ✓$(RESET)"
			@$(AR) $(NAME) $(PRINTF_OBJS)

all:		$(NAME)

clean:
			@$(RM) $(PRINTF_OBJS)
			@echo "$(CYAN) FT_PRINTF - Bye Laziness, Bye dirt 🚿$(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(CYAN) FT_PRINTF - Bath is so good!  Now it's over. 🧼✨$(RESET)"

re:			fclean all

.PHONY:	all bonus clean fclean re