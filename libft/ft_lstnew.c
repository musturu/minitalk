/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:56:15 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/14 19:21:26 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *ncontent)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	res -> content = ncontent;
	res -> next = NULL;
	return (res);
}
