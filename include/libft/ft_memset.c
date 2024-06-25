/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:55:47 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/01/18 17:11:06 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*rt;

	i = 0;
	rt = b;
	while (i < len)
	{
		rt[i] = (unsigned char)c;
		i ++;
	}
	return (rt);
}
