/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 03:52:03 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/17 06:53:25 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	s1_len;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	s1_len = ft_strlen(s1);
	if (!(str = malloc(sizeof(char) * (total_len + 1))))
		return (NULL);
	i = 0;
	while (i < total_len)
	{
		str[i] = (i < s1_len) ? s1[i] : s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	return (str);
}
