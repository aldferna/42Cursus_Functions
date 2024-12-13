/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:58:16 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/28 16:22:44 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
void	ft_putnbr_fd(int i, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putchar_fd(int num, int fd, int *count);
void	ft_puthexa_fd(int num, int fd, int *count, char type);
void	ft_putptr_fd(unsigned long long lg, int fd, int *count);
void	ft_putpositive_fd(int num, int fd, int *count);
#endif
