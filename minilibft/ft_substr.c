/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 03:52:50 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/17 06:53:25 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s || !(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && s[i + start] && !(start > ft_strlen(s)))
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
