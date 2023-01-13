/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:22:04 by kilchenk          #+#    #+#             */
/*   Updated: 2023/01/10 15:09:45 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	check_letter(const char *str, int i, va_list arg)
{
	int	num;

	num = 0;
	if (str[i] == 'c')
		num += ft_putchar_fd(va_arg(arg, int), 1);
	if (str[i] == 's')
		num += putstr_fd(va_arg(arg, char *), 1);
	if (str[i] == 'd' || str [i] == 'i')
		num += ft_putnbr_fd(va_arg(arg, int), 1);
	if (str[i] == '%')
		num += ft_putchar_fd('%', 1);
	if (str[i] == 'u')
		num +=

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
			letters++;
		}
	}
	va_end (arg);
	return (letters);
}
