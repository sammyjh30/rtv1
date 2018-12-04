/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_radius_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 08:12:08 by shillebr          #+#    #+#             */
/*   Updated: 2018/12/04 08:12:31 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_norm(t_shape *shp, char *line, int i)
{
	t_vec3		norm;

	if (!(get_tvec3(&norm, line, i)))
		return (0);
	shp->norm = norm;
	return (1);
}

int		get_axis(t_shape *shp, char *line, int i)
{
	t_vec3		axis;
	double		angle;

	if (!(get_tvec3(&axis, line, i)))
		return (0);
	shp->norm = vec3_nor_cpy(axis);
	angle = acos(vec3_dot((t_vec3){0, 1, 0}, axis) / vec3_len(axis));
	shp->imat = matrix_axis_rot(vec3_crs(axis, (t_vec3){0, 1, 0}), -angle);
	shp->mat = matrix_inverse(&shp->imat);
	return (1);
}

int		get_dir(t_light *lit, char *line, int i)
{
	t_vec3		dir;

	if (!(get_tvec3(&dir, line, i)))
		return (0);
	lit->dir = dir;
	return (1);
}

int		get_intensity(t_light *lit, char *line, int i)
{
	double		intens;

	if (!(get_double(&intens, line, i)))
		return (0);
	lit->intensity = intens;
	return (1);
}

int		get_l_cols(t_light *shp, char *line, int i)
{
	t_colour	col;

	if (!(get_tcol(&col, line, i)))
		return (0);
	shp->col = col;
	return (1);
}
