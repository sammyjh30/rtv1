/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:59:29 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 10:40:40 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ray.h"

int		inter_check(t_inter *i)
{
	if ((t_shape *)(i->shape) != NULL)
		return (1);
	return (0);
}
