/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:37 by arcarval          #+#    #+#             */
/*   Updated: 2022/12/05 20:21:18 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

int		ft_isalpha(int caracter);
int		ft_isdigit(int caracter);
int		ft_isalnum(int caracter);
int		ft_isascii(int caracter);
int		ft_isprint(int caracter);
size_t	ft_strlen(char const *str);
void	*ft_memset(void *str, int caracter, size_t length);
void	ft_bzero(void *str, size_t number);
void	*ft_memcpy(void *dest, const void *src, size_t char_number);
void	*ft_memmove(void *str1, const void *str2, size_t char_number);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
size_t	ft_strlcat(char *dest, char const *src, size_t size);
int		ft_toupper(int caracter);
int		ft_tolower(int caracter);
char	*ft_strchr(char const *str, int caracter);
char	*ft_strrchr(char const *str, int caracter);
int		ft_strncmp(char const *str1, char const *str2, size_t char_number);
void	*ft_memchr(const void *str, int caracter, size_t char_number);
int		ft_memcmp(const void *str, const void *str2, size_t char_number);
char	*ft_strnstr(char const *haystack, char const *needle, size_t str_len);
int		ft_atoi(char const *str);
void	*ft_calloc(size_t number_spaces, size_t size);
char	*ft_strdup(char const *str);
char	*ft_substr(char const *src, unsigned int beginning, size_t max_length);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *str, char const *set);
char	**ft_split(char const *str, char delimiter);
char	*ft_itoa(int number);
char	*ft_strmapi(char const *str, char (*function)(unsigned int, char));
void	ft_striteri(char *str, void (*function)(unsigned int, char*));
void	ft_putchar_fd(char caracter, int file_descriptor);
void	ft_putstr_fd(char *str, int file_descriptor);
void	ft_putendl_fd(char *str, int file_descriptor);
void	ft_putnbr_fd(int number, int file_desciptor);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*function)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*function)(void *), void (*del)(void *));

#endif
