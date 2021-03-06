/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:15:14 by shillebr          #+#    #+#             */
/*   Updated: 2019/01/07 07:27:13 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Checks which class is being read
*/

int		read_class(int fd, t_param *p, char *line)
{
	if (ft_strequ(line, "##Objects"))
	{
		if (!(read_objects(fd, p->set)))
			return (0);
	}
	else if (ft_strequ(line, "##Camera"))
	{
		if (!(read_camera(fd, p->cam)))
			return (0);
	}
	else if (ft_strequ(line, "##Lights"))
	{
		if (!(read_lights(fd, p->lis)))
			return (0);
	}
	return (1);
}

int		file_line(int l, int fd, t_param *p, char *line)
{
	int		r;

	if (ft_strequ("##Scene", line))
	{
		if (l != 0)
			r = 0;
		else
			r = 2;
	}
	else if (l > 0 && line[0] == '\0')
		r = 2;
	else if (!(read_class(fd, p, line)))
		r = 0;
	else if (ft_strequ("#\0", line))
		r = 1;
	else
		r = 0;
	return (r);
}

int		read_file(char *av, t_param *p)
{
	char	*line;
	int		i;
	int		r;
	int		l;
	int		fd;

	r = 0;
	if (((fd = open(av, O_RDONLY)) == -1) || !p)
		return (0);
	i = 1;
	l = 0;
	while (i != 0)
	{
		if (((i = get_next_line(fd, &line)) == 0) ||
			(!(r = file_line(l, fd, p, line))))
			break ;
		ft_strdel(&line);
		l++;
	}
	if (line)
		ft_strdel(&line);
	return (r);
}

/*
** Checks if arguement is valid filetype
*/

int		ft_rt(char *str)
{
	char *f_ext;

	f_ext = ft_strstr(str, ".rt");
	if (!f_ext)
		return (0);
	else if (ft_strlen(f_ext) == 3)
		return (1);
	return (0);
}
