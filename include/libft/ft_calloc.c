/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:43:26 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/01/25 18:04:12 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rv;

	if (size && (count * size / size) != count)
		return (NULL);
	rv = malloc(count * size);
	if (!rv)
		return (NULL);
	ft_bzero(rv, count * size);
	return (rv);
}
