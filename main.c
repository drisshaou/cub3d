/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:40:09 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/19 09:33:11 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*cub;
	t_c3d	*t;
	int		ret;

	t = NULL;
	if (!(ac >= 2))
		return (exit_error(NO_CUB));
	if ((cub = ft_substr(av[1], ft_strlen(av[1]) - 4, ft_strlen(av[1])))
		&& !ft_strcmp(cub, ".cub"))
	{
		free(cub);
		fd = open(av[1], O_RDONLY);
		ret = (!file_exist(fd, ".cub") || !parse_file(fd, &t, av)) ? 0 : 1;
		close(fd);
		if (!ret)
			return (ret);
		start_game(t);
	}
	else
	{
		free(cub);
		return (exit_error(NOT_CUB));
	}
	return (0);
}
