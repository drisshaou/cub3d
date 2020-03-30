/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 03:53:30 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/17 06:53:25 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
