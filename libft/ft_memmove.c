/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:57:35 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/14 20:00:21 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (src < dst)
	{
		while (i < len)
		{
			i++;
			((unsigned char *)dst)[len - i] = ((unsigned char *)src)[len - i];
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
