/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:03:49 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/30 17:15:03 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		fill_map(char ***map, char *line)
{
	static int	x = 0;
	char		**map_tmp;
	int			i;

	i = 0;
	while (line[i])
		if (!ft_checkset(line[i++], VALID_CHAR))
			return (exit_error(MAP_INVALID));
	map_tmp = *map;
	if (!(*map = malloc(sizeof(char*) * (++x + 1))))
		return (exit_error(CANT_MALLOC_MAP));
	i = -1;
	while (++i < x)
		(*map)[i] = (i == x - 1) ? ft_strdup(line) : ft_strdup(map_tmp[i]);
	(*map)[x] = 0;
	if (map_tmp != NULL)
		ft_free_tab(map_tmp);
	return (1);
}
