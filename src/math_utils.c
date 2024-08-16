/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:09:17 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/08/16 00:01:02 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
 * Given an n number in range [prev_min - prev_max]
 * map it's value to the range [new_min - new_max]
 *  (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 */
double	map(double n, double new_min, double new_max, double prev_min, double prev_max)
{
	return ((n - new_min) * (prev_max - prev_min) / (new_max - new_min) + prev_min);
}

t_complex	sum(t_complex z1, t_complex z2)
{
	t_complex sum;

	sum.x = z1.x + z2.x;
	sum.y = z1.y + z2.y;
	return (sum);
}

/*
 * Makes the power of a complex number
 * 	~ the real (x) part is x^2 - y^2
 * 	~ the imaginary (yi) part is 2xy
 *	
 *	that's because: 
 *		(x + yi)*(x + yi)
 *		x^2 + xyi + xyi + y^2 * i^2
 *		
 *		~ The power of i is -1 so
 *		x^2 - y^2 + 2xyi
 *		---------   ----
 *			Real     Imaginary
 */
t_complex	power(t_complex z)
{
	t_complex	power;

	power.x = z.x * z.x;
	power.y = 2 * z.x * z.y;
	return (power);
}
