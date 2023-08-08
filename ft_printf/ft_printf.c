/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:40:53 by arcarval          #+#    #+#             */
/*   Updated: 2023/01/15 13:13:19 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_percentage(char caracter, va_list args_list)
{
	int	printed_quant;

	printed_quant = -2;
	if (caracter == 'c')
		printed_quant += ft_putchar_printf(va_arg(args_list, int));
	if (caracter == 's')
		printed_quant += ft_putstr_printf(va_arg(args_list, char *));
	if (caracter == 'p')
		printed_quant += ft_putpointer(va_arg(args_list, unsigned long long));
	if (caracter == 'd' || caracter == 'i')
		printed_quant += ft_putnbr_printf(va_arg(args_list, int));
	if (caracter == 'u')
		printed_quant += ft_putnbr_unsigned_fd(va_arg(args_list, unsigned int));
	if (caracter == 'x')
		printed_quant += ft_puthex(va_arg(args_list, int), "0123456789abcdef");
	if (caracter == 'X')
		printed_quant += ft_puthex(va_arg(args_list, int), "0123456789ABCDEF");
	if (caracter == '%')
		printed_quant += ft_putchar_printf('%');
	return (printed_quant);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	args_list;
	int		length;
	int		index;

	va_start(args_list, format_str);
	length = ft_strlen_printf(format_str);
	index = 0;
	while (format_str[index])
	{
		if (format_str[index] == '%')
		{
			index++;
			length += process_percentage(format_str[index], args_list);
		}
		else
			ft_putchar_printf(format_str[index]);
		index++;
	}
	va_end(args_list);
	return (length);
}

/* #include <stdio.h>

int	main( void )
{
	char				*ponteiro = {"ponteirao"};
	int					nullpointer = 0;
	int					integer_lower = -2147483648;
	int					integer_upper = 2147483647;
	unsigned int		unsigned_integer_upper = 4294967295;
	int					returned1;
	int					returned2;

	// Test print Caracters
	returned1 = ft_printf("Format %c phrase.\n", 'a');
	returned2 = printf("Format %c phrase.\n", 'a');
	printf("\nReturned1 = %d\n", returned1);
	printf("\nReturned2 = %d\n", returned2);

	ft_printf("%c", '0');
	printf("%c", '0');
	ft_printf(" %c ", '0');
	printf(" %c ", '0');
	ft_printf(" %c", '0' - 256);
	printf(" %c", '0' - 256);
	ft_printf("%c ", '0' + 256);
	printf("%c ", '0' + 256);
	ft_printf(" %c %c %c ", '0', 0, '1');
	printf(" %c %c %c ", '0', 0, '1');
	ft_printf(" %c %c %c ", ' ', ' ', ' ');
	printf(" %c %c %c ", ' ', ' ', ' ');
	ft_printf(" %c %c %c ", '1', '2', '3');
	printf(" %c %c %c ", '1', '2', '3');
	ft_printf(" %c %c %c ", '2', '1', 0);
	printf(" %c %c %c ", '2', '1', 0);
	ft_printf(" %c %c %c ", 0, '1', '2');
	printf(" %c %c %c ", 0, '1', '2');
	// Test print String
	ft_printf("Format %s phrase.\n", "abacate");
	printf("Format %s phrase.\n", "abacate");
	// Test print Pointers
	ft_printf("Format %p phrase.\n", ponteiro);
	printf("Format %p phrase.\n", ponteiro);
	ft_printf("Format %p phrase.\n", &nullpointer);
	printf("Format %p phrase.\n", &nullpointer);
	// Test print Decimal (-2147483648 to 2147483647)
	ft_printf("Format %d phrase.\n", integer_upper);
	printf("Format %d phrase.\n", integer_upper);
	// Test print Decimal (-2147483648 to 2147483647)
	ft_printf("Format %i phrase.\n", integer_lower);
	printf("Format %i phrase.\n", integer_lower);
	// Test print Unsigned Decimal (0 to 4294967295)
	ft_printf("Format %u phrase.\n", unsigned_integer_upper);
	printf("Format %u phrase.\n", unsigned_integer_upper);
	// Test print hexadecimal Lowercase (0 to 4294967295)
	ft_printf("Format %x phrase.\n", 23456);
	printf("Format %x phrase.\n", 23456);
	// Test print hexadecimal Uppercase (0 to 4294967295)
	ft_printf("Format %X phrase.\n", 9672);
	printf("Format %X phrase.\n", 9672);
	// Test print Percent Sign
	ft_printf("Format %% phrase.\n");
	printf("Format %% phrase.\n");
	return (0);
} */
