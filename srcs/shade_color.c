/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:24:11 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/20 08:17:41 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		shade_color(int color, double shadedist)
{
	shadedist *= 1.;
	if (shadedist <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / shadedist) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / shadedist) << 8)
		+ ((int)((0x0000FF & color) / shadedist)));
}
