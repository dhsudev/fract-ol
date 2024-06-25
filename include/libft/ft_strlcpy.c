/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:29:03 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/01/26 22:29:46 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i ++;
		}
		dest[i] = '\0';
	}
	return (src_size);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	const char* src = "hola";
	size_t num = 0;
	char dest1[20];
	char dest2[20];
	printf("Mine: %s \n Org: %s\n", dest1, dest2);
	ft_strlcpy(dest1,src,num);
	strlcpy(dest2,src,num);
	printf("Mine: %s \n Org: %s", dest1, dest2);
}*/