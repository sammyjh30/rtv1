/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:23:54 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 19:29:39 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_sphere_info(t_shape *sphere, char *line)
{
	if (ft_strequ("\tradius[", line))
		return (!(get_radius(sphere, line, 8))) ? (0) : (1);
	else if (ft_strequ("\tpos[", line))
		return (!(get_pos(sphere, line, 5))) ? (0) : (1);
	else if (ft_strequ("\tcolour[", line))
		return (!(get_cols(sphere, line, 8))) ? (0) : (1);
	else if (ft_strequ("\ttexture[", line))
		return (!(get_texture(sphere, line, 9))) ? (0) : (1);
	else
		return (0);
	return (1);
}

int		sphere_line(char *line, t_vector *set, t_shape *sphere)
{
	int		r;

	if (ft_strequ(line, "\0"))
		r = 2;
	else if (ft_strequ("}", line))
	{
		vector_add(set, sphere);
		ft_strdel(&line);
		r = 1;
	}
	else if (get_sphere_info(sphere, line))
		r = 2;
	else
		r = 0;
	ft_strdel(&line);
	return (r);
}

int		make_sphere(int fd, t_vector *set)
{
	int		i;
	int		r;
	t_shape *sphere;
	char	*line;

	i = 1;
	sphere = sphere_new((t_vec3){0, 0, 0}, 0, (t_colour){0, 0, 0}, 0);
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		r = sphere_line(line, set, sphere);
		if (r == 1)
		{
			printf("Sphere pos: [%f %f %f]\n", sphere->pos.x, sphere->pos.y, sphere->pos.z);
			printf("Sphere radius: [%f]\n", sphere->radius);
			printf("Sphere height: [%f]\n", sphere->height);
			printf("Sphere norm: [%f %f %f]\n", sphere->norm.x, sphere->norm.y, sphere->norm.z);
			printf("Sphere Matrix: \n[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]\n\n", sphere->mat.mat[0][0], sphere->mat.mat[0][1], sphere->mat.mat[0][2], sphere->mat.mat[0][3], sphere->mat.mat[1][0], sphere->mat.mat[1][1], sphere->mat.mat[1][2], sphere->mat.mat[1][3], sphere->mat.mat[2][0], sphere->mat.mat[2][1], sphere->mat.mat[2][2], sphere->mat.mat[2][3], sphere->mat.mat[3][0], sphere->mat.mat[3][1], sphere->mat.mat[3][2], sphere->mat.mat[3][2]);
			printf("Sphere Inverse Matrix: \n[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]\n\n", sphere->imat.mat[0][0], sphere->imat.mat[0][1], sphere->imat.mat[0][2], sphere->imat.mat[0][3], sphere->imat.mat[1][0], sphere->imat.mat[1][1], sphere->imat.mat[1][2], sphere->imat.mat[1][3], sphere->imat.mat[2][0], sphere->imat.mat[2][1], sphere->imat.mat[2][2], sphere->imat.mat[2][3], sphere->imat.mat[3][0], sphere->imat.mat[3][1], sphere->imat.mat[3][2], sphere->imat.mat[3][2]);
			return (1);
		}
		else if (r == 2)
			continue ;
		else
			return (0);
	}
	ft_strdel(&line);
	return (0);
}
