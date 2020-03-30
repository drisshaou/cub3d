/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 04:12:58 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/20 06:49:51 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		file_exist(int fd, char *type)
{
	char		*buffer;
	const char	*cant_read;
	const char	*no_file;
	int			ret;

	cant_read = !ft_strcmp(type, ".cub") ? CANT_RD_CUB : CANT_RD_XPM;
	no_file = !ft_strcmp(type, ".cub") ? NO_CUB : NO_XPM;
	ret = 0;
	if (!(buffer = malloc(sizeof(char) * 2)))
		return (exit_error(cant_read));
	if (!(read(fd, buffer, 0) < 0))
		ret = 1;
	free(buffer);
	if (ret == 0)
		return (exit_error(no_file));
	return (ret);
}
