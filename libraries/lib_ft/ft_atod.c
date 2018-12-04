/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:46:01 by xrhoda            #+#    #+#             */
/*   Updated: 2018/12/04 07:27:37 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"
#include <stdio.h>

int			ft_pow(int a, int b)
{
	int		ret;

	ret = a;
	while (--b > 0)
		ret *= a;
	return (ret);
}

double		calc_end(char *splt)
{
	int		len;
	double	end;

	len = 0;
	while (ft_isdigit(splt[len]))
		len++;
	end = ft_atod(splt) / ft_pow(10, len);
	free(splt);
	return (end);
}

double		ft_atod(char *str)
{
	char	**splt;
	double	start;
	double	end;
	int		neg;

	start = 0;
	neg = 1;
	if (str)
	{
		splt = ft_strsplit(str, '.');
		if (splt[0][0] == '-')
			neg = -1;
		start = (double)ft_atoi(splt[0]);
		free(splt[0]);
		end = 0;
		if (splt[1])
			end = calc_end(splt[1]);
		if (start >= 0)
			start = (start + end) * neg;
		else
			start -= end;
		free(splt);
	}
	return (start);
}
