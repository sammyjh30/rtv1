/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:43:18 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/29 12:43:55 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

int		ft_intlen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
