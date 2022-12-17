/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jportier <jportier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:05:46 by jportier          #+#    #+#             */
/*   Updated: 2022/12/17 11:21:07 by jportier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(const char *str, char c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (*str)
	{
		if (*str != c && !found)
		{
			found = 1;
			i++;
		}
		else if (*str == c)
			found = 0;
		str++;
	}
	return (i);
}

static char	*write_word(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}
static char **empty_tabs(char **output, int j)
{
	while (j >= 0)
	{
		free(output[j]);
		j--;
	}
	free(output);
	return (NULL);
}
static char **splitter(char **output, char const *s, char c, int index, int i)
{
	int j;

	j = 0;
	while ((size_t)++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || (size_t)i == ft_strlen(s)) && index >= 0)
		{
			output[j++] = write_word(s, index, i);
			if (!output[j - 1])
				return (empty_tabs(output, j - 2));
			index = -1;
		}
	}
	output[j] = 0;
	return (output);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		index;
	char	**split;

	split = malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = -1;
	index = -1;
	return (splitter(split, s, c, index, i));
}
