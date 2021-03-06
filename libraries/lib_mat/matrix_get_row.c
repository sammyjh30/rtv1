/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_get_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:36:29 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:16:33 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

int		matrix_get_row(t_mat *m, int i)
{
	int j;

	j = i - 1;
	while (++j < 4)
		if (m->mat[j][i] != 0)
			return (j);
	return (-1);
}
