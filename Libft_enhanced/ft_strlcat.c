/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jportier <jportier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:06:19 by jportier          #+#    #+#             */
/*   Updated: 2022/12/17 11:25:42 by jportier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dest_l;

	index = 0;
	if (!dst || !size)
		return (size);
	else
		dest_l = ft_strlen(dst);
	while (src[index] && dest_l + index < size - 1 && size != 0)
	{
		dst[index + dest_l] = src[index];
		index++;
	}
	dst[index + dest_l] = '\0';
	while (src[index])
		index++;
	if (dest_l < size)
		return (dest_l + index);
	else
		return (size + index);
}
