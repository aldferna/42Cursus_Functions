/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpositive_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:13:07 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/28 16:21:43 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpositive_fd(int num, int fd, int *count)
{
	unsigned int	n;
	char			c;

	if (num == 0)
	{
		write(fd, "0", 1);
		(*count)++;
		return ;
	}
	else if (num < 0)
		n = (unsigned int)num;
	else
		n = num;
	if (n >= 10)
		ft_putpositive_fd(n / 10, fd, count);
	c = (n % 10) + 48;
	write(fd, &c, 1);
	(*count)++;
}
