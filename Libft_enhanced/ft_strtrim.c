/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jportier <jportier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:06:48 by jportier          #+#    #+#             */
/*   Updated: 2022/12/17 11:33:07 by jportier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_first_char(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	s1_pos;
	size_t	set_pos;

	set_len = ft_strlen(set);
	s1_pos = 0;
	set_pos = 0;
	while (set_pos < set_len && s1[s1_pos])
	{
		if (s1[s1_pos] == set[set_pos])
		{
			set_pos = -1;
			s1_pos++;
		}
		set_pos++;
	}
	return (s1_pos);
}

static size_t	get_last_char(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	s1_pos;
	size_t	set_pos;
	size_t	s1_len;

	set_len = ft_strlen(set);
	s1_len = ft_strlen(s1);
	if (s1_len == 0)
		return (0);
	s1_pos = s1_len - 1;
	set_pos = 0;
	while (set_pos < set_len && s1_pos >= 1)
	{
		if (s1[s1_pos] == set[set_pos])
		{
			set_pos = -1;
			s1_pos--;
		}
		set_pos++;
	}
	return (s1_pos);
}
// The ft_calloc is protected because we immediately return the value, meaning that if calloc fails we are returning NULL, which is the expected behavior.
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start_pos;
	size_t	end_pos;
	size_t	index;

	start_pos = get_first_char(s1, set);
	end_pos = get_last_char(s1, set);
	if (end_pos == 0)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	str = malloc(sizeof(char) * (end_pos - start_pos) + 2);
	if (!str)
		return (NULL);
	index = 0;
	while (start_pos <= end_pos)
		str[index++] = s1[start_pos++];
	str[index] = '\0';
	return (str);
}
