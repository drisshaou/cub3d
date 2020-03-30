/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 01:17:49 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/20 06:49:51 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_conf(t_c3d **t)
{
	if (!find_player(&(*t)->map, &(*t)->pos, &(*t)->orienter)
		|| !check_map(&(*t)->map, (*t)->pos)
		|| !find_sprites(*t))
		return (0);
	else if (!(*t)->winw || !(*t)->winh)
		return (exit_error(RESOLUTION_PROBLEM));
	else if (ft_get_tab_size((*t)->tex_tab) < 5)
		return (exit_error(TEXTURE_PROBLEM));
	else if ((*t)->cl_color == 0x7a674b && !(*t)->tex_cl)
		return (exit_error(COLOR_PROBLEM));
	else if ((*t)->flr_color == 0x64a5e8 && !(*t)->tex_flr)
		return (exit_error(COLOR_PROBLEM));
	return (1);
}
