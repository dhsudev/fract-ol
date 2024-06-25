/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:32:42 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/01/29 21:20:08 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * ft_countdigits(n) + 1);
	if (!str)
		return (NULL);
	i = ft_countdigits(n);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[i] = '\0';
	i--;
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}

/*
#include <stdio.h>
int main (void)
{
	int num = 0;
	char *str = ft_itoa(num);
	printf("Num of dig: %d\n", ft_countdigits(num));
	printf("Num: %s\n", str);
	free(str);
}*/