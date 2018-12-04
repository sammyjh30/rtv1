/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_radius_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 08:12:00 by shillebr          #+#    #+#             */
/*   Updated: 2018/12/04 08:12:32 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_radius(t_shape *shp, char *line, int i)
{
	double		rad;

	if (!(get_double(&rad, line, i)))
		return (0);
	shp->radius = rad;
	return (1);
}

int		get_pos(t_shape *shp, char *line, int i)
{
	t_vec3		pos;

	if (!(get_tvec3(&pos, line, i)))
		return (0);
	shp->pos = pos;
	return (1);
}

int		get_cols(t_shape *shp, char *line, int i)
{
	t_colour	col;

	if (!(get_tcol(&col, line, i)))
		return (0);
	shp->col = col;
	return (1);
}

int		get_texture(t_shape *shp, char *line, int i)
{
	double		text;

	if (!(get_double(&text, line, i)))
		return (0);
	shp->tex = text;
	return (1);
}
