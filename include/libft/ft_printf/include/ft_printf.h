/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:24:58 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/23 18:16:38 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		print_digit(long n, long base, int upper, int *count);
int		print_string(char *s, int *count);
int		print_char(int c, int *count);
void	print_format(char spec, va_list ap, int *count);
int		print_pt(unsigned long long n, int *count);
char	*set_charset(int upper);

#endif