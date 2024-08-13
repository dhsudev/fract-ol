/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:10:53 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/23 18:16:27 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_char(int c, int *count)
{
	if (write(1, &c, 1) != -1)
		*count += 1;
	else
		*count = -1;
	return (0);
}

int	print_string(char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
		return (print_string("(null)", count));
	while (s[i])
	{
		print_char(s[i], count);
		if (*count < 0)
			return (-1);
		i++;
	}
	return (0);
}

void	print_format(char spec, va_list ap, int *count)
{
	if (spec == 'c')
		print_char(va_arg(ap, int), count);
	else if (spec == 's')
		print_string(va_arg(ap, char *), count);
	else if (spec == 'i' || spec == 'd')
		print_digit(va_arg(ap, int), 10, 0, count);
	else if (spec == 'u')
		print_digit(va_arg(ap, unsigned int), 10, 0, count);
	else if (spec == 'x')
		print_digit(va_arg(ap, unsigned int), 16, 0, count);
	else if (spec == 'X')
		print_digit(va_arg(ap, unsigned int), 16, 1, count);
	else if (spec == '%')
		print_char('%', count);
	else if (spec == 'p')
	{
		print_string("0x", count);
		if (*count < 0)
			return ;
		print_pt(va_arg(ap, unsigned long long), count);
	}
	else
		*count = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, format);
	count = 0;
	i = -1;
	while (format[++i] && count != -1)
	{
		if (format[i] == '%')
		{
			print_format(format[++i], ap, &count);
			if (count < 0)
				return (-1);
		}
		else
		{
			print_char(format[i], &count);
			if (count < 0)
				return (-1);
		}
	}
	return (count);
}
