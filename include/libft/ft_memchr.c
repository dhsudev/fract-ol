/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:47:28 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/01/18 17:34:27 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*rt;

	i = 0;
	ch = (char) c;
	rt = (unsigned char *)s;
	while (i != n)
	{
		if (rt[i] == ch)
		{
			return ((char *)&rt[i]);
		}
		i ++;
	}
	return (NULL);
}
