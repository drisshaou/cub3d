/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:17:32 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/29 15:51:54 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_conf(t_c3d *t)
{
	if (t->tex_tab != NULL)
		ft_free_tab(t->tex_tab);
	if (t->map != NULL)
		ft_free_tab(t->map);
	if (t->sprites != NULL)
		free_sprite(t, t->sprites);
	free(t);
	t = NULL;
}
