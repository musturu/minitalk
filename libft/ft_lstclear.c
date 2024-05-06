/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:44:07 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/14 19:20:33 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
