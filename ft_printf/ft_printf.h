/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:57:17 by arcarval          #+#    #+#             */
/*   Updated: 2023/01/15 13:06:36 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format_string, ...);
int		ft_putchar_printf(char caracter);
int		ft_putstr_printf(char *number);
int		ft_putnbr_printf(int number);
int		ft_putnbr_unsigned_fd(unsigned int number);
int		ft_strlen_printf(char const *str);
int		ft_puthex(long int number, char *base_hex);
int		ft_putpointer(unsigned long long number);

#endif