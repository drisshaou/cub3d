/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:07:02 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/30 04:00:15 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_player(char ***map, t_double *pos, int *orienter)
{
	char	chr;
	t_int	s;
	int		nb;

	*pos = (t_double){0, 0, 0};
	s.x = -1;
	if (!(nb = 0) && map != NULL)
		while (++s.x < ft_get_tab_size(*map) && (s.y = -1))
			while (++s.y < (int)ft_strlen((*map)[s.x]))
			{
				chr = (*map)[s.x][s.y];
				if (chr == 'N' || chr == 'E' || chr == 'S' || chr == 'W')
				{
					nb++;
					*orienter = chr;
					*pos = (t_double){s.x + 0.5, s.y + 0.5, 0.};
				}
			}
	if (nb == 1)
		(*map)[(int)pos->x][(int)pos->y] = '0';
	else if (nb == 0)
		return (exit_error(CANT_FIND_PLAYER));
	else if (nb > 1)
		return (exit_error(TOO_MUCH_PLAYERS));
	return (nb);
}
