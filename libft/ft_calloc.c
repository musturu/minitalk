/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:25:16 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/15 18:03:51 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count && size && (4294967295U / size <= count))
		return (0);
	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, (count * size));
	return (ret);
}
