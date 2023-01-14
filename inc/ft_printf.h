/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:03:53 by kilchenk          #+#    #+#             */
/*   Updated: 2023/01/14 21:51:09 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//library
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
//functions

int		ft_printf(const char *format, ...);
int		putstr_fd(char *s, int fd);
int		putchar_fd(char c, int fd);
void	ft_digit(long long int n, int *length, char *hexadecimal, int base);

#endif
