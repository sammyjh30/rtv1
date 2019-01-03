/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:47:17 by xrhoda            #+#    #+#             */
/*   Updated: 2019/01/03 07:33:51 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

#include "stdio.h"

static void		calc_new_c(t_mat *ret, t_mat *m, t_mat tmp, double det)
{
	ret->mat[2][0] = (m->mat[1][0] * tmp.mat[2][2] - m->mat[1][1] *
					tmp.mat[2][1] + m->mat[1][3] * tmp.mat[1][2]) * det;
	ret->mat[2][1] = (-m->mat[0][0] * tmp.mat[2][2] + m->mat[1][3] *
					tmp.mat[2][1] - m->mat[0][3] * tmp.mat[1][2]) * det;
	ret->mat[2][2] = (m->mat[3][0] * tmp.mat[1][0] - m->mat[3][1] *
					tmp.mat[0][2] + m->mat[3][3] * tmp.mat[0][0]) * det;
	ret->mat[2][3] = (-m->mat[2][0] * tmp.mat[1][0] + m->mat[2][1] *
					tmp.mat[0][2] - m->mat[2][3] * tmp.mat[0][0]) * det;
	ret->mat[3][0] = (-m->mat[1][0] * tmp.mat[2][1] + m->mat[1][1] *
					tmp.mat[1][3] - m->mat[1][2] * tmp.mat[1][2]) * det;
	ret->mat[3][1] = (m->mat[0][0] * tmp.mat[2][1] - m->mat[0][1] *
					tmp.mat[1][3] + m->mat[0][2] * tmp.mat[1][2]) * det;
	ret->mat[3][2] = (-m->mat[3][0] * tmp.mat[0][3] + m->mat[3][1] *
					tmp.mat[0][1] - m->mat[3][2] * tmp.mat[0][0]) * det;
	ret->mat[3][3] = (m->mat[2][0] * tmp.mat[0][3] - m->mat[2][1] *
					tmp.mat[0][1] + m->mat[2][2] * tmp.mat[0][0]) * det;
}

static t_mat	calc_new(t_mat *m, t_mat tmp, double det)
{
	t_mat	ret;

	ret.mat[0][0] = (m->mat[1][1] * tmp.mat[2][3] - m->mat[1][2] *
					tmp.mat[2][2] + m->mat[1][3] * tmp.mat[2][1]) * det;
	ret.mat[0][1] = (-m->mat[0][1] * tmp.mat[2][3] + m->mat[0][2] *
					tmp.mat[2][2] - m->mat[1][3] * tmp.mat[2][1]) * det;
	ret.mat[0][2] = (m->mat[3][1] * tmp.mat[1][1] - m->mat[3][2] *
					tmp.mat[1][0] + m->mat[3][3] * tmp.mat[0][3]) * det;
	ret.mat[0][3] = (-m->mat[2][1] * tmp.mat[1][1] + m->mat[2][2] *
					tmp.mat[1][0] - m->mat[2][3] * tmp.mat[0][3]) * det;
	ret.mat[1][0] = (-m->mat[1][0] * tmp.mat[2][3] + m->mat[1][2] *
					tmp.mat[2][0] - m->mat[1][3] * tmp.mat[1][3]) * det;
	ret.mat[1][1] = (m->mat[0][0] * tmp.mat[2][3] - m->mat[0][2] *
					tmp.mat[2][0] + m->mat[0][3] * tmp.mat[1][3]) * det;
	ret.mat[1][2] = (-m->mat[3][0] * tmp.mat[1][1] + m->mat[3][2] *
					tmp.mat[0][2] - m->mat[3][3] * tmp.mat[0][1]) * det;
	ret.mat[1][3] = (m->mat[2][0] * tmp.mat[1][1] - m->mat[2][2] *
					tmp.mat[0][2] + m->mat[2][3] * tmp.mat[0][1]) * det;
	calc_new_c(&ret, m, tmp, det);

	printf("\tOriginal Matrix\n[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]\n\n", ret.mat[0][0], ret.mat[0][1], ret.mat[0][2], ret.mat[0][3], ret.mat[1][0], ret.mat[1][1], ret.mat[1][2], ret.mat[1][3], ret.mat[2][0], ret.mat[2][1], ret.mat[2][2], ret.mat[2][3], ret.mat[3][0], ret.mat[3][1], ret.mat[3][2], ret.mat[3][3]);

	return (ret);
}

t_mat			matrix_inverse(t_mat *m)
{
	t_mat	tmp;
	double	det;

	printf("\tInverse Matrix\n[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]\n\n", m->mat[0][0], m->mat[0][1], m->mat[0][2], m->mat[0][3], m->mat[1][0], m->mat[1][1], m->mat[1][2], m->mat[1][3], m->mat[2][0], m->mat[2][1], m->mat[2][2], m->mat[2][3], m->mat[3][0], m->mat[3][1], m->mat[3][2], m->mat[3][3]);

	tmp.mat[0][0] = m->mat[0][0] * m->mat[1][1] - m->mat[0][1] * m->mat[1][0];
	tmp.mat[0][1] = m->mat[0][0] * m->mat[1][2] - m->mat[0][3] * m->mat[1][0];
	tmp.mat[0][2] = m->mat[0][0] * m->mat[1][3] - m->mat[0][3] * m->mat[1][0];
	tmp.mat[0][3] = m->mat[0][1] * m->mat[1][2] - m->mat[0][2] * m->mat[1][1];
	tmp.mat[1][0] = m->mat[0][1] * m->mat[1][3] - m->mat[0][3] * m->mat[1][1];
	tmp.mat[1][1] = m->mat[0][2] * m->mat[1][3] - m->mat[0][3] * m->mat[1][2];
	tmp.mat[1][2] = m->mat[2][0] * m->mat[3][1] - m->mat[2][1] * m->mat[3][0];
	tmp.mat[1][3] = m->mat[2][0] * m->mat[3][2] - m->mat[2][2] * m->mat[3][0];
	tmp.mat[2][0] = m->mat[2][0] * m->mat[3][3] - m->mat[2][3] * m->mat[3][0];
	tmp.mat[2][1] = m->mat[2][1] * m->mat[3][2] - m->mat[2][2] * m->mat[3][1];
	tmp.mat[2][2] = m->mat[2][1] * m->mat[3][3] - m->mat[2][3] * m->mat[3][1];
	tmp.mat[2][3] = m->mat[2][2] * m->mat[3][3] - m->mat[2][3] * m->mat[3][2];
	det = 1 / (tmp.mat[0][0] * tmp.mat[2][3] - tmp.mat[0][1] * tmp.mat[2][2]
			+ tmp.mat[0][2] * tmp.mat[2][1] +
				tmp.mat[0][3] * tmp.mat[2][0] - tmp.mat[1][0] * tmp.mat[1][3]
			+ tmp.mat[1][1] * tmp.mat[1][2]);
	return (calc_new(m, tmp, det));
}
