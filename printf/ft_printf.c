/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:09:33 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/11 19:45:56 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	no_valid(char type, int fd, int *count)
{
	if (type == 'p')
	{
		write(fd, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	if (type == 's')
	{
		write(fd, "(null)", 6);
		(*count) += 6;
		return ;
	}
}

void	set_ft_basic(char s, va_list *args, int *count)
{
	int		num;
	int		fd;
	char	*str;

	fd = 1;
	if (s == 'd' || s == 'i')
	{
		num = va_arg(*args, int);
		ft_putnbr_fd(num, fd, count);
	}
	else if (s == 'c')
	{
		num = va_arg(*args, int);
		ft_putchar_fd(num, fd, count);
	}
	else if (s == 's')
	{
		str = va_arg(*args, char *);
		if (!str)
			return (no_valid(s, fd, count));
		ft_putstr_fd(str, fd, count);
	}
}

void	set_ft_special(char s, va_list *args, int *count)
{
	int		num;
	int		fd;
	void	*lg;

	fd = 1;
	if (s == 'u')
	{
		num = va_arg(*args, int);
		ft_putpositive_fd(num, fd, count);
	}
	else if (s == 'x' || s == 'X')
	{
		num = va_arg(*args, int);
		ft_puthexa_fd(num, fd, count, s);
	}
	else if (s == 'p')
	{
		lg = va_arg(*args, void *);
		if (!lg)
			return (no_valid(s, fd, count));
		write(fd, "0x", 2);
		(*count) += 2;
		ft_putptr_fd((unsigned long long)lg, fd, count);
	}
}

void	ft_organizer(char s, va_list *args, int *count)
{
	if (s == 'd' || s == 'i' || s == 'c' || s == 's')
		set_ft_basic(s, args, count);
	else if (s == 'u' || s == 'x' || s == 'X' || s == 'p')
		set_ft_special(s, args, count);
	else if (s == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			ft_organizer(format[i], &args, &count);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	//char	*null = NULL;

	//ft_printf(" NULL %s NULL \n", null);
	//ft_printf(" %p %p \n", null, null);
	//ft_printf("hola %");
	//printf("%p", 7);
	ft_printf("%p", 7);
	return (0);
}
