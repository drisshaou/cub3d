/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:37:16 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/30 17:06:36 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_c3d *t)
{
	init_bufz(t);
	init_orientation(t, t->orienter);
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, t->winw, t->winh, "cub3d");
	mlx_hook(t->win, 17, 0L, ft_exit, t);
	mlx_hook(t->win, 2, 0, keypress, t);
	mlx_hook(t->win, 3, 0, keyrelease, t);
	load_xpm(t);
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
}
