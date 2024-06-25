/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:01:05 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/08 18:06:40 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (haystack[0] == '\0')
		return (NULL);
	i = 0;
	needle_len = ft_strlen(needle) - 1;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			j++;
			if (j > needle_len)
				return ((char *) haystack + i);
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int main (void)
{
	const char *larga = "lorem ipsum dolor sit amet";
	char *corta = "ame";

	printf("%s\n", strnstr(larga, corta, 10));
	printf("%s", ft_strnstr(larga, corta, 10));
}*/