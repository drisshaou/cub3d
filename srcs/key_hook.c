/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:22:45 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/29 15:43:15 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keypress(int keycode, t_c3d *t)
{
	if (keycode == 13 || keycode == 126)
		t->mvu = 1;
	else if (keycode == 1 || keycode == 125)
		t->mvd = 1;
	else if (keycode == 2)
		t->mvr = 1;
	else if (keycode == 0)
		t->mvl = 1;
	else if (keycode == 124)
		t->rtr = 1;
	else if (keycode == 123)
		t->rtl = 1;
	else if (keycode == 257)
		t->mvs = 0.1;
	else if (keycode == 53)
		ft_exit(t);
	return (0);
}

int		keyrelease(int keycode, t_c3d *t)
{
	if (keycode == 13 || keycode == 126)
		t->mvu = 0;
	else if (keycode == 1 || keycode == 125)
		t->mvd = 0;
	else if (keycode == 2)
		t->mvr = 0;
	else if (keycode == 0)
		t->mvl = 0;
	else if (keycode == 124)
		t->rtr = 0;
	else if (keycode == 123)
		t->rtl = 0;
	else if (keycode == 257)
		t->mvs = 0.05;
	return (0);
}
