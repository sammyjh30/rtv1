/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:48:49 by shillebr          #+#    #+#             */
/*   Updated: 2018/12/03 13:48:53 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_lights(int fd, t_vector *set, char *line)
{
	int		i;

	if (ft_strequ(line, "Dir Light{"))
		i = make_dir_light(fd, set);
	else if (ft_strequ(line, ""))
		i = 1;
	else
		i = 0;
	return (i);
}

int		is_light(char *line)
{
	if (ft_strequ(line, "Dir Light{"))
		return (1);
	return (0);
}

int		read_extra(char *line)
{
	if (ft_strequ(line, ""))
		return (4);
	else if (ft_strequ(line, "#"))
		return (1);
	else
		return (0);
}

int		read_lights(int fd, t_vector *set)
{
	int		i;
	int		r;
	char	*line;

	i = 1;
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (1);
		if (is_light(line))
			check_lights(fd, set, line);
		else
		{
			r = read_extra(line);
			ft_strdel(&line);
			if (r == 4)
				continue;
			else
				return (r);
		}
		ft_strdel(&line);
	}
	return (1);
}
