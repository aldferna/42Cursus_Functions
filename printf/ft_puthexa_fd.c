/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:21:19 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/28 16:21:49 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_fd(int num, int fd, int *count, char type)
{
	char			c;
	unsigned int	n;

	if (num < 0)
		n = (unsigned int)num;
	else
		n = num;
	if (n >= 16)
		ft_puthexa_fd(n / 16, fd, count, type);
	if ((n % 16) < 10)
		c = (n % 16) + '0';
	else
	{
		if (type == 'x')
			c = (n % 16) - 10 + 'a';
		if (type == 'X')
			c = (n % 16) - 10 + 'A';
	}
	write(fd, &c, 1);
	(*count)++;
}
