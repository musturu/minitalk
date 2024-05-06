/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:16:37 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/14 21:19:37 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	enddest;
	size_t	endsrc;
	size_t	i;

	i = 0;
	endsrc = ft_strlen(src);
	if (size == 0 || size <= ft_strlen(dest))
		return (size + endsrc);
	enddest = ft_strlen(dest);
	while (i < size - enddest - 1 && src[i])
	{
		dest[i + enddest] = src[i];
		i++;
	}
	dest[i + enddest] = '\0';
	return (enddest + endsrc);
}
