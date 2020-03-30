/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 00:20:51 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/17 06:53:25 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int		ft_checkset(char c, const char *set)
{
	int i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	total_len;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
		if (ft_checkset(*s1, set))
			s1++;
		else
			break ;
	total_len = ft_strlen(s1);
	while (ft_checkset(s1[total_len - 1], set) && total_len != 0)
		total_len--;
	return (ft_substr(s1, 0, total_len));
}
