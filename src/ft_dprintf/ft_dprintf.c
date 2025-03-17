/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:35:15 by itamsama          #+#    #+#             */
/*   Updated: 2024/12/23 13:30:05 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	cases(char chr, va_list args, int *count, int fd)
{
	if (chr == 'c')
		*count += ft_dputchar(fd, va_arg(args, int));
	else if (chr == 's')
		*count += ft_dputstr(fd, va_arg(args, char *));
	else if (chr == 'p')
		ft_dputptr(fd, args, count);
	else if (chr == 'd' || chr == 'i')
		*count += ft_dputnbr(fd, va_arg(args, int));
	else if (chr == 'u')
		*count += ft_dputnbr_unsigned(fd, va_arg(args, unsigned int));
	else if (chr == 'x')
		*count += ft_dputhexa(fd, va_arg(args, unsigned int), 'a');
	else if (chr == 'X')
		*count += ft_dputhexa(fd, va_arg(args, unsigned int), 'A');
	else if (chr == '%')
		*count += ft_dputchar(fd, '%');
}

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!str)
		return (-1);
	va_start (args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str != '\0')
				cases(*str, args, &count, fd);
			else
				break ;
		}
		else
			count += ft_dputchar(fd, *str);
		str++;
	}
	va_end(args);
	return (count);
}
