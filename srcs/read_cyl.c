/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:04:06 by shillebr          #+#    #+#             */
/*   Updated: 2019/01/03 07:34:57 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_cyl_info(t_shape *cyl, char *line)
{
	if (ft_strequ("\tradius[", line))
		return (!(get_radius(cyl, line, 8))) ? (0) : (1);
	else if (ft_strequ("\tpos[", line))
		return (!(get_pos(cyl, line, 5))) ? (0) : (1);
	else if (ft_strequ("\taxis[", line))
		return (!(get_axis(cyl, line, 6))) ? (0) : (1);
	else if (ft_strequ("\tcolour[", line))
		return (!(get_tcol(&cyl->col, line, 8))) ? (0) : (1);
	else if (ft_strequ("\ttexture[", line))
		return (!(get_texture(cyl, line, 9))) ? (0) : (1);
	else
		return (0);
	return (1);
}

int		cyl_line(char *line, t_vector *set, t_shape *cyl)
{
	int		r;

	if (ft_strequ(line, "\0"))
		r = 2;
	else if (ft_strequ("}", line))
	{
		vector_add(set, cyl);
		ft_strdel(&line);
		r = 1;
	}
	else if (get_cyl_info(cyl, line))
		r = 2;
	else
		r = 0;
	ft_strdel(&line);
	return (r);
}

int		make_cyl(int fd, t_vector *set)
{
	int		i;
	int		r;
	t_shape *cyl;
	char	*line;

	i = 1;
	cyl = cyl_new((t_vec3){0, 0, 0}, (t_vec3){0, 0, 0}, 0,
			(t_colour){0, 0, 0});
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		r = cyl_line(line, set, cyl);
		if (r == 1)
			return (1);
		else if (r == 2)
			continue ;
		else
			return (0);
	}
	return (0);
}
