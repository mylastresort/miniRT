/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:28:53 by stamim            #+#    #+#             */
/*   Updated: 2022/10/27 09:06:29 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gsl/gsl_sf_bessel.h>
#include <stdio.h>

int	main(void)
{
	double	cord1;
	double	cord2;

	cord1 = 0;
	cord2 = gsl_sf_bessel_J0(cord1);
	printf("J0(%g) = %.18e\n", cord1, cord2);
}
