/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_nor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:47:45 by xeno              #+#    #+#             */
/*   Updated: 2019/01/03 08:10:14 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"
#include "lib_ft.h"

double	vec3_nor(t_vec3 *v)
{
	// double l;

	// l = vec3_len(*v);
	// vec3_div(v, l);
	// return (l);

	double x;
	double y;
	double z;
	double len;

	x = v->x;
	y = v->y;
	z = v->z;
	len = sqrt(x * x + y * y + z * z);
	if (!len)
	{
		// v = VEC3(0, 0, 0);
		v->x = 0;
		v->y = 0;
		v->z = 0;
	}
	else if (len == 1)
	{
		// v = VEC3(x, y, z);
		v->x = x;
		v->y = y;
		v->z = z;
	}
	else
	{
		len = 1 / len;
		v->x = x * len;
		v->y = y * len;
		v->z = z * len;
	}
	return (len);
}

t_vec3	vec3_nor_cpy(t_vec3 v)
{
	// t_vec3 cpy;
	// double len;

	// cpy = vec3_cpy(v);
	// if (!(len = vec3_nor(&cpy)))
	// 	return (vec3());
	// if (len == 1)
	// 	return (v);
	// return (cpy);

	double x;
	double y;
	double z;
	double len;

	x = v.x;
	y = v.y;
	z = v.z;
	len = sqrt(x * x + y * y + z * z);
	if (!len)
		v = (t_vec3){0, 0, 0};
	else if (len == 1)
		v = (t_vec3){x, y, z};
	else
	{
		len = 1 / len;
		v.x = x * len;
		v.y = y * len;
		v.z = z * len;
	}
	return (v);
}
