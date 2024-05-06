/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:28:39 by lmoricon          #+#    #+#             */
/*   Updated: 2024/01/11 11:35:50 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_aux(long int num, int fd)
{
	int	w;

	if (num > 9)
		ft_aux(num / 10, fd);
	w = (num % 10) + '0';
	ft_putchar_fd(w, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	ft_aux(num, fd);
}
