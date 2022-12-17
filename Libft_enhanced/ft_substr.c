/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jportier <jportier@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:06:51 by jportier          #+#    #+#             */
/*   Updated: 2022/11/09 20:40:49 by jportier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// the ft_calloc call returns NULL is if fails, so we're protecting there 

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	{
		sub_s = ft_calloc(1, 1);
		return (sub_s);
	}
	else if (ft_strlen(s) - (size_t)start < len)
		sub_s = ft_calloc(sizeof(char), ft_strlen(s) - (size_t)start + 1);
	else
		sub_s = ft_calloc(sizeof(char), len + 1);
	if (!sub_s)
		return (NULL);
	while (s[start + index] && index < len)
	{
		sub_s[index] = s[index + start];
		index++;
	}
	sub_s[index] = '\0';
	return (sub_s);
}
