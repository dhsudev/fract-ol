/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:55:45 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/06 15:46:20 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i ++;
	}
}
/*
void	ft_prueba(unsigned int index, char *c)
{
	index++;
	(*c)++;
}
#include <stdio.h>
int main (void)
{
	char str[] = "abcdefg";

    printf("Input: %s\n", str);
	ft_strmapi(str, (void *)ft_prueba);
    printf("Output: %s\n", str);
}*/