/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:00:39 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/15 18:28:17 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s + start);
	ret = (char *)ft_calloc(sizeof(char), (len + 1));
	if (ret == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len && s[i])
		{
			ret[j++] = s[i];
		}
		i++;
	}
	ret[j] = '\0';
	return (ret);
}
