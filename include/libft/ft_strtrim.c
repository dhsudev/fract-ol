/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:20:54 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/08 17:49:58 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	end;
	size_t	start;

	if (!s1)
		return (NULL);
	if (!set || set[0] == '\0')
		return (ft_strdup(s1));
	if (s1[0] == '\0')
		return (ft_strdup(""));
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	start = i;
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i]))
		i--;
	end = i;
	trim = ft_substr(s1, start, end - start + 1);
	return (trim);
}

/*
int main (void)
{
	char *set = "";
	char *s1 = "";
	s1 = ft_strtrim(s1, set);
	printf("%s", s1);
}*/