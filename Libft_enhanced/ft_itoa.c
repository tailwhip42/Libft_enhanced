/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jportier <jportier@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:02:11 by jportier          #+#    #+#             */
/*   Updated: 2022/11/09 13:33:36 by jportier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	integer_len(long long int n)
{
	int	sign;
	int	len;

	if (n < 0)
		sign = 1;
	else
		sign = 0;
	len = sign + 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = integer_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_memcpy(str, "-2147483648", 12));
	if (n < 0)
	{
		str[0] = '-';
		n = -1 * n;
	}
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	while (n != 0)
	{
		str[--len] = 48 + n % 10;
		n /= 10;
	}
	return (str);
}
