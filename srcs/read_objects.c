/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:21 by shillebr          #+#    #+#             */
/*   Updated: 2018/12/04 08:55:17 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_objects(int fd, t_vector *set, char *line)
{
	int		i;

	if (ft_strequ(line, "Sphere{"))
		i = make_sphere(fd, set);
	else if (ft_strequ(line, "Plane{"))
		i = make_plane(fd, set);
	else if (ft_strequ(line, "Cylinder{"))
		i = make_cyl(fd, set);
	else if (ft_strequ(line, "Cone{"))
		i = make_cone(fd, set);
	else if (ft_strequ(line, "\0"))
		i = 1;
	else
		i = 0;
	return (i);
}

/*
** Check if the line contains a valid object
*/

int		is_obj(char *line)
{
	if (ft_strequ(line, "Sphere{") || ft_strequ(line, "Plane{"))
		return (1);
	else if (ft_strequ(line, "Cylinder{") || ft_strequ(line, "Cone{"))
		return (1);
	return (0);
}

int		read_obj_loop(int fd, char *line, t_vector *set)
{
	if (is_obj(line))
	{
		if (!(check_objects(fd, set, line)))
			return (0);
	}
	else if (ft_strequ(line, "\0"))
		return (4);
	else if (ft_strequ(line, "#"))
		return (1);
	else
		return (0);
	return (3);
}

/*
** Iterate through the objects class
*/

int		read_objects(int fd, t_vector *set)
{
	int		i;
	int		r;
	char	*line;

	i = 1;
	ft_putendl("Reading Objects");
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			break ;
		r = read_obj_loop(fd, line, set);
		ft_strdel(&line);
		if (r == 4)
			continue;
		if (r != 3)
			return (r);
	}
	ft_strdel(&line);
	return (1);
}
