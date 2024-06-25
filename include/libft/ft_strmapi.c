/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:34:24 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/05 18:27:35 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*rts;

	rts = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!rts)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rts[i] = f(i, s[i]);
		i ++;
	}
	return (rts);
}

/*
char ft_prueba(unsigned int index, char c)
{
    index++;
	return c + 1;
}

#include <stdio.h>
int main (void)
{
	const char *str = "abcdefg";
    char *result;

    result = ft_strmapi(str, &ft_prueba);
    if (result) {
        printf("Input: %s\n", str);
        printf("Output: %s\n", result);
        free(result);
    } else {
        printf("Error al asignar memoria.\n");
    }
}*/