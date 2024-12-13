/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:14:48 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/28 16:21:46 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int i, int fd, int *count)
{
	char	c;

	if (i == -2147483648)
	{
		write(fd, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	if (i == 0)
	{
		write(fd, "0", 1);
		(*count)++;
		return ;
	}
	if (i < 0)
	{
		write(fd, "-", 1);
		(*count)++;
		i = -i;
	}
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd, count);
	c = (i % 10) + 48;
	write(fd, &c, 1);
	(*count)++;
}
