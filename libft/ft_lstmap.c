/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:49:14 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/14 19:17:47 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*current;

	if (!lst)
		return (0);
	ret = ft_lstnew(f(lst->content));
	current = ret;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(lst->content))
			del(lst->content);
		current->next = ft_lstnew(f(lst->content));
		current = current->next;
	}
	return (ret);
}
