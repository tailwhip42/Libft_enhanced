/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jportier <jportier@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:06:40 by jportier          #+#    #+#             */
/*   Updated: 2022/11/27 12:43:41 by jportier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
		return ((char *)&big[i]);
	if (len)
	{
		while (big[i] && (i < len -1 || i < 1))
		{
			if (big[i] == little[0])
			{
				j = 0;
				while ((big[i + j] && little[j]) && (big[i + j] == little[j])
					&& (i + j) < len)
					j++;
				if (!(little[j]))
					return ((char *)&big[i]);
			}
			i++;
		}
	}
	return (NULL);
}
