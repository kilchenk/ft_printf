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

static int	check_letter(char i, va_list arg)
{
	int	num;

	num = 0;
	if (i =='c')
		num += print_char();

	return num;
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
			i++;
			letters += check_letter(format[i], ptr);
		}
		else
		{
			write(1, &format[i], 1);
			letters++;
		}
		i++;
	}
	va_end (arg);
	return (letters);
}
