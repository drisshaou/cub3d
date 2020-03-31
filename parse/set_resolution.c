/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 04:19:16 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/31 02:23:15 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_resolution(t_c3d *t, char **split)
{
	int	i;

	i = -1;
	while (split[1][++i])
		if (!ft_isdigit(split[1][i]))
			return (exit_error(RESOLUTION_PROBLEM));
	t->winw = (ft_atoi(split[1]) > 640) ? ft_atoi(split[1]) : 640;
	i = -1;
	while (split[2][++i])
		if (!ft_isdigit(split[2][i]))
			return (exit_error(RESOLUTION_PROBLEM));
	t->winh = (ft_atoi(split[2]) > 480) ? ft_atoi(split[2]) : 480;
	return (1);
}
