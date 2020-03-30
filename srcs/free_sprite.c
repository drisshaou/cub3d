/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:14:00 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/19 08:38:44 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_sprite(t_c3d *t, t_sprite **sprite)
{
	int	i;

	i = -1;
	while (++i < t->nbsprites)
		free(sprite[i]);
	free(sprite);
	sprite = NULL;
}
