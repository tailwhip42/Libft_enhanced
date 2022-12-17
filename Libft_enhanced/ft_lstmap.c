/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jportier <jportier@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:41:40 by jportier          #+#    #+#             */
/*   Updated: 2022/11/27 12:31:48 by jportier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_elem;
	t_list	*new_list_start;

	if (!lst || !f)
		return (NULL);
	new_list_start = 0;
	while (lst)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_list_start, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list_start, new_elem);
		lst = lst->next;
	}
	return (new_list_start);
}
