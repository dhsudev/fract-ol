/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:44:47 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/01/22 16:59:58 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*rt;

	if (!src && !dest)
		return (NULL);
	i = 0;
	rt = (unsigned char *)dest;
	while (i < size)
	{
		rt[i] = ((unsigned char *)src)[i];
		i ++;
	}
	return (dest);
}

/*#include <string.h>
#include <stdio.h>
int main(void)
{
	const char* src = "hol\0ar";
	size_t num = 2;
	char dest1[num];
	char dest2[num];
	
	printf("%s", ft_memcpy(((void *)0), ((void *)0), 3));
	
	printf("%s", memcpy(((void *)0), ((void *)0), 3));

}*/