/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_line_n_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 04:21:50 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/20 06:49:51 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_line_n_split(char *line, char **split)
{
	if (split != NULL)
		ft_free_tab(split);
	free(line);
}
