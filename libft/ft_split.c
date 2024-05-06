/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:48:43 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/15 18:29:08 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_strfree(char **str)
{
	while (*str)
	{
		free(*str);
		(*str)++;
	}
	free(str);
	return (NULL);
}

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	if (str == NULL || str[0] == 0)
		return (0);
	i = 0;
	count = 0;
	if (str[i] != c)
		count++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1])
			count++;
		i++;
	}
	return (count);
}

static int	*find_words(const char *str, char c)
{
	int	count;
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * count_words(str, c));
	if (arr == NULL || str == NULL)
		return (0);
	if (str[0] == '\0')
		return (arr);
	i = 0;
	count = 0;
	if (str[i] != c)
	{
		arr[count++] = i;
	}
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1])
		{
			arr[count++] = i + 1;
		}
		i++;
	}
	return (arr);
}

static int	my_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *str, char c)
{
	int		*wpos;
	int		i;
	char	**r;

	if (!str)
		return (NULL);
	i = 0;
	wpos = find_words(str, c);
	r = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (r == NULL || wpos == NULL)
		return (NULL);
	while (i < count_words(str, c) && str[0])
	{
		r[i] = ft_substr(str, wpos[i], my_len(str + wpos[i], c));
		if (r[i++] == NULL)
			return (ft_strfree(r));
	}
	r[i] = NULL;
	free(wpos);
	return (r);
}
