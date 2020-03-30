/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:21:21 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/31 01:11:07 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_xpm(t_c3d *t)
{
	int	a;
	int	b;
	int	i;

	a = TX_W;
	b = TX_H;
	i = -1;
	while (++i < ft_get_tab_size(t->tex_tab))
	{
		t->tx[i].img = mlx_xpm_file_to_image(t->mlx, t->tex_tab[i], &a, &b);
		t->tx[i].data = mlx_get_data_addr(t->tx[i].img, &t->tx[i].bpp,
			&t->tx[i].sizeline, &t->tx[i].endian);
	}
}
