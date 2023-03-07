# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 23:15:46 by arcarval          #+#    #+#              #
#    Updated: 2023/02/23 21:04:49 by arcarval         ###   ########.fr        #
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

# LIBFT
NAME	=	libft.a
HEADER	=	libft.h
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	\
			ft_isascii.c	ft_isprint.c	ft_strlen.c		\
			ft_memset.c		ft_bzero.c		ft_memcpy.c		\
			ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	\
			ft_toupper.c	ft_tolower.c	ft_strchr.c		\
			ft_strrchr.c	ft_strncmp.c	ft_memchr.c		\
			ft_memcmp.c		ft_strnstr.c	ft_atoi.c		\
			ft_calloc.c		ft_strdup.c		ft_substr.c		\
			ft_strjoin.c	ft_strtrim.c	ft_split.c		\
			ft_itoa.c		ft_striteri.c	ft_strmapi.c	\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	

OBJS		=	$(SRCS:.c=.o)

BONUS		=	ft_lstnew_bonus.c	ft_lstadd_front_bonus.c	ft_lstsize_bonus.c		\
				ft_lstlast_bonus.c	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	\
				ft_lstclear_bonus.c	ft_lstiter_bonus.c		ft_lstmap_bonus.c

BONUS_OBJS	=	$(BONUS:.c=.o)

AR			=	ar -rcs

RM			=	rm -f

.c.o:
			@echo "$(ORANGE) Compiling  ➟  $(BLUE)$< $(RESET)"
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEADER)
			@echo "$(MAGENTA)\n $(NAME)  🗄️  🗃️  Archived ✓$(RESET)"
			@$(AR) $(NAME) $(OBJS)

all:		$(NAME)

bonus:		$(NAME) $(BONUS_OBJS)
			$(AR) $(NAME) $(BONUS_OBJS)

clean:
			@$(RM) $(OBJS) $(BONUS_OBJS)
			@echo "$(CYAN) LIBFT - Bye Laziness, Bye dirt 🚿$(RESET)"

fclean:		clean
			@$(RM) $(NAME) libft.so a.out
			@echo "$(CYAN) LIBFT - Bath is so good!  Now it's over. 🧼✨$(RESET)"

re:			fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY:	all bonus clean fclean re
