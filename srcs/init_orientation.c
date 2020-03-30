/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:26:15 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/20 07:11:40 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_orientation(t_c3d *t, char orient)
{
	t->rtr = 1;
	if (orient == 'S')
		t->rts = M_PI;
	else if (orient == 'E')
		t->rts = M_PI * 0.5;
	else if (orient == 'W')
		t->rts = M_PI * 1.5;
	else
		t->rts = 0;
	rotate(t);
	t->rtr = 0;
	t->rts = 0.025;
}
