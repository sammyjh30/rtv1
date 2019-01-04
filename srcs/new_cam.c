/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:14:42 by xrhoda            #+#    #+#             */
/*   Updated: 2019/01/04 10:26:33 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam	*new_cam(t_vec3 org, t_vec3 target, double fov)
{
	t_cam *cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (NULL);
	cam->org = org;
	cam->tar = target;
	cam->forward = vec3_sub_new(target, cam->org);
	vec3_nor(&(cam->forward));
	if (!cam->forward.z)
		cam->right = vec3_crs(cam->forward, (t_vec3){0, 0, 1});
	else		
		cam->right = vec3_crs(cam->forward, (t_vec3){0, 1, 0});
	vec3_nor(&(cam->right));
	cam->up = vec3_crs(cam->forward, cam->right);
	cam->h = tan(fov);
	cam->w = cam->h * RATIO;
	return (cam);
}
