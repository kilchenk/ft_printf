/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:22:04 by kilchenk          #+#    #+#             */
/*   Updated: 2023/01/14 21:48:21 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	check_letter(const char *str, int i, va_list ar)
{
	int	num;

	num = 0;
	if (str[i] == 'c')
		num += putchar_fd(va_arg(ar, int), 1);
	if (str[i] == 's')
		num += putstr_fd(va_arg(ar, char *), 1);
	if (str[i] == 'd' || str [i] == 'i')
		num += ft_digit(va_arg(ar, int), &num, "0123456789", 10);
	if (str[i] == '%')
		num += putchar_fd('%', 1);
	if (str[i] == 'u')
		num += ft_digit(va_arg(ar, unsigned int), &num, "0123456789", 10);
	if (str[i] == 'x')
		num += ft_digit(va_arg(ar, unsigned int), &num, "0123456789abcdef", 16);
	if (str[i] == 'X')
		num += ft_digit(va_arg(ar, unsigned int), &num, "0123456789ABCDEF", 16);
	if (str[i] == 'p')
	{
		num += putstr_fd("0x", 1);
		num += ft_digit(va_arg(ar, size_t), &num, "0123456789abcdef", 16);
	}
	return (num);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		letters;

	va_start (arg, format);
	i = 0;
	letters = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			letters += check_letter(format, i + 1, arg);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			letters ++;
		}
	}
	va_end (arg);
	return (letters);
}

// int main()
// {
//     // int x = 5;
//     int i = ft_printf("%d\n", 5);
// 	ft_printf("%i\n", i);
// 	int x = printf("%d\n", 5);
// 	printf("%i\n", x);
//     // ft_printf("%i\n", x);
// 	// printf("%d\n", x);
//     // printf("%i\n", x);
//     return 0;
// }
