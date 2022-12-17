/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jportier <jportier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:06:16 by jportier          #+#    #+#             */
/*   Updated: 2022/11/10 13:27:48 by jportier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen2(char const *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		index;
	char	*str;

	len_s1 = ft_strlen2(s1);
	len_s2 = ft_strlen2(s2);
	index = -1;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	while (++index < len_s1)
		str[index] = s1[index];
	index = -1;
	while (++index < len_s2)
		str[index + len_s1] = s2[index];
	str[index + len_s1] = '\0';
	return (str);
}
