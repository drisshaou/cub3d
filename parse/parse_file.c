/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 04:23:04 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/30 02:30:58 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		extract_data(char *line, char **split, t_c3d *t)
{
	int	split_size;

	split_size = ft_get_tab_size(split);
	if (split_size == 3 && !ft_strcmp(*split, "R"))
		return (set_resolution(t, split));
	else if (split_size == 2 && (!ft_strcmp(*split, "NO")
			|| !ft_strcmp(*split, "SO") || !ft_strcmp(*split, "WE")
			|| !ft_strcmp(*split, "EA") || !ft_strcmp(*split, "S")))
		return (set_texture(t, split));
	else if (split_size == 2
			&& (!ft_strcmp(*split, "F") || !ft_strcmp(*split, "C")))
		return (set_color(t, split));
	else if ((*split)[0] == '1' || (*split)[0] == '0')
		return (fill_map(&t->map, line));
	else
		return (0);
}

int		parse_file(int fd, t_c3d **t, char **av)
{
	char	*line;
	char	**split;
	int		ret;

	if (!(*t = malloc(sizeof(t_c3d))))
		return (exit_error(CANT_MALLOC_STRUCT));
	init_conf(*t);
	ret = 0;
	while (ret != -2 && (ret = get_next_line(fd, &line)) > 0)
	{
		split = (ft_strlen(line) > 0) ? ft_split(line, ' ') : NULL;
		if (split != NULL && !extract_data(line, split, *t))
			ret = -2;
		free_line_n_split(line, split);
	}
	if (!ret)
		free(line);
	if (ret < 0 || !check_conf(t))
	{
		free_conf(*t);
		return (0);
	}
	(*t)->save = av[2] != NULL && !ft_strcmp(av[2], "--save") ? 1 : 0;
	return (1);
}
