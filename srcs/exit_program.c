/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:50:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/12/04 08:02:19 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_program(t_param *p)
{
	int i;

	if (!p)
		exit(0);
	if (p->img)
		destroy_image(p->img, p->mlx);
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	if (p->mlx)
		free(p->mlx);
	i = -1;
	while (++i < p->set->total)
		free(vector_get(p->set, i));
	i = -1;
	while (++i < p->lis->total)
		free(vector_get(p->lis, i));
	if (p->set)
		vector_free(p->set);
	if (p->cam)
		free(p->cam);
	if (p->lis)
		vector_free(p->lis);
	exit(0);
}
