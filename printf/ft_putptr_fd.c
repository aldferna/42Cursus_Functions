/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:13:37 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/28 16:21:40 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_fd(unsigned long long lg, int fd, int *count)
{
	char	c;

	if (lg >= 16)
		ft_putptr_fd(lg / 16, fd, count);
	if ((lg % 16) < 10)
		c = (lg % 16) + '0';
	else
		c = (lg % 16) - 10 + 'a';
	write(fd, &c, 1);
	(*count)++;
}
