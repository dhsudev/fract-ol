/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:59:40 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/08 20:28:09 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_arr(char **arr, int size)
{
	while (size > -1)
	{
		free(arr[size]);
		size --;
	}
	free(arr);
	return (NULL);
}

static int	ft_countwords(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i + 1] == c && (size_t)(i + 1) != ft_strlen(s))
			count ++;
		i++;
	}
	if (s[i - 1] != c && s[i - 1] != '\0')
		count++;
	return (count);
}

static void	ft_set_vars(int	*a, int	*b, int	*c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		start;
	int		act_word;

	if (!s)
		return (NULL);
	arr = ft_calloc(sizeof(char *), (ft_countwords(s, c) + 1));
	if (!arr)
		return (NULL);
	ft_set_vars(&i, &start, &act_word);
	while (s[i] != '\0')
	{
		if (s[start] == c && s[i] != c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			arr[act_word++] = ft_substr(s, start, i - start + 1);
			if (!arr[act_word - 1])
				return (ft_free_arr(arr, act_word));
			start = i + 1;
		}
		i++;
	}
	return (arr);
}

/*#include <stdio.h>

int main (void)
{
	char *s = "dfhfghdrt";
	//char **arr = ft_split(s, ' ');
	printf("count: %d\n", ft_countwords(s, '\0'));
	//int i = 0;
	//while(arr[i] != NULL){
	//	printf("i:%d -> %s.\n",i, arr[i]);
	//	i++;}
	//ft_free_arr(arr, ft_countwords(s, ' '));
}*/
