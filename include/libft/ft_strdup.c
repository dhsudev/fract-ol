/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:05:36 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/01/25 16:38:48 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;

	size = ft_strlen(s1);
	s2 = malloc(size * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, size + 1);
	return (s2);
}

/*#include <stdio.h>
#include <string.h>
int main(void){
	//const char* s1 = "HO   s	l777aaaa";
	char *s2 = ft_strdup(((void *)0));
	printf("My strdup: %s.\n", s2);
	s2 = strdup(((void *)0));
	printf("Orginal  : %s.", s2);
	free(s2);
}*/