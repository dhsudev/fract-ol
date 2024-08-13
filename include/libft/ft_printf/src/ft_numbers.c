/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:50:08 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/23 18:13:37 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_pt(unsigned long long n, int *count)
{
	char	*symb;

	symb = "0123456789abcdef";
	if (n < 16)
	{
		print_char(symb[n], count);
		if (*count < 0)
			return (-1);
	}
	else
	{
		print_pt(n / 16, count);
		if (*count < 0)
			return (-1);
		print_pt(n % 16, count);
		if (*count < 0)
			return (-1);
	}
	return (0);
}

char	*set_charset(int upper)
{
	if (upper)
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

int	print_digit(long n, long base, int upper, int *count)
{
	char	*symb;

	if (*count < 0)
		return (-1);
	symb = set_charset(upper);
	if (n < 0)
	{
		print_char('-', count);
		if (*count < 0)
			return (-1);
		print_digit(-n, base, upper, count);
	}
	else if (n < base)
	{
		print_char(symb[n], count);
		if (*count < 0)
			return (-1);
	}
	else
	{
		print_digit(n / base, base, upper, count);
		return (print_digit(n % base, base, upper, count));
	}
	return (0);
}
