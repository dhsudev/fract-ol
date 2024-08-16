/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 23:53:59 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/15 23:54:16 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atod(char *str)
{
	double	number;
	int		signal;
	int		i;
	double	n;

	signal = 1;
	number = 0;
	n = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			signal = -1;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0' )
		number = number * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		number = number + (str[i++] - '0') * 0.1 * n;
		n /= 10;
	}
	return ((number) * signal);
}
