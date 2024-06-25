/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:44:34 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/01/25 17:35:32 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*rt;

	if (dst == src || len == 0)
		return (dst);
	rt = (unsigned char *)dst;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			rt[i] = ((unsigned char *)src)[i];
			i ++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			rt[i - 1] = ((unsigned char *)src)[i - 1];
			i --;
		}
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>
 int main()
 {
	char src[] = "holaabcdefg";
	char dst[20];
	char dst2[20];

	ft_memmove(dst, src, strlen(src) + 1);
	ft_memmove(dst2, src, strlen(src) + 1);
	printf("Copia sin overlap: \n\t%s \n\t%s\n", dst, dst2);

	ft_memmove(dst + 7, dst, 7);
	memmove(dst2 + 7, dst2, 7);
	printf("Copia con overlap (dst > src): \n\t%s \n\t%s\n", dst, dst2);

	ft_memmove(dst, dst + 7, 7);
	memmove(dst2, dst2 + 7, 7);
	printf("Copia con overlap (dst < src)\n\t%s \n\t%s \n", dst, dst2);

	ft_memmove(dst, src, 0);
	memmove(dst2, src, 0);
	printf("Copia de 0 bytes: \n\t%s \n\t%s\n", dst, dst2);

	ft_memmove(dst + 2, dst, 7);
	memmove(dst2 + 2, dst2, 7);
	printf("Copia áreas iguales: \n\t%s \n\t%s\n", dst, dst2);

     return 0;
 } */