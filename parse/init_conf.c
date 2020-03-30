/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:17:03 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/30 16:46:09 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_conf(t_c3d *t)
{
	t->map = NULL;
	t->winw = 0;
	t->winh = 0;
	t->orienter = -1;
	t->pos = (t_double){0.0, 0.0, 0.0};
	t->tex_tab = NULL;
	t->flr_color = 0x64a5e8;
	t->cl_color = 0x7a674b;
	t->tex_flr = 0;
	t->tex_cl = 0;
	t->dir = (t_double){-1.0, 0.0, 0.0};
	t->pln.y = 0.66;
	t->mvs = 0.05;
	t->rts = 0.05;
	t->mvu = 0;
	t->mvd = 0;
	t->mvl = 0;
	t->mvr = 0;
	t->rtl = 0;
	t->rtr = 0;
	t->txpos = (t_int){0, 0};
	t->save = 0;
}
