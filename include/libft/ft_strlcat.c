/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:35:51 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/01/24 14:42:01 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	dest_length = ft_strlen(dst);
	j = dest_length;
	i = 0;
	if (dest_length < size - 1 && size > 0)
	{
		while (src[i] && dest_length + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}

/*int main() {
    char destination_custom[20] = "Hello, ";
    char destination_original[20] = "Hello, ";
    const char *source = "world!";
    size_t max_length = 20;

    size_t result_custom = ft_strlcat(destination_custom, source, max_length);
    size_t result_original = strlcat(destination_original, source, max_length);

    printf("Custom strlcat - Resulting string: %s\n", destination_custom);
    printf("Custom strlcat - Total length: %zu\n", result_custom);

    printf("Original strlcat - Resulting string: %s\n", destination_original);
    printf("Original strlcat - Total length: %zu\n", result_original);


    return 0;
}*/