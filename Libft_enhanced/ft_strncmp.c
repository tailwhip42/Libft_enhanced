/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jportier <jportier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:06:38 by jportier          #+#    #+#             */
/*   Updated: 2022/12/17 11:29:35 by jportier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (-999);
	if (n == 0)
		return (0);
	while (index < n - 1 && s1[index] == s2[index] && s1[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
