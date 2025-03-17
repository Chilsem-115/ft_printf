/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:35:15 by itamsama          #+#    #+#             */
/*   Updated: 2024/12/23 13:30:05 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	ptr_checker(va_list args, int *count)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		*count += ft_putstr("(nil)");
	else
	{
		*count += ft_putstr("0x");
		*count += ft_puthexa((unsigned long)ptr, 'a');
	}
}

void	cases(char chr, va_list args, int *count)
{
	if (chr == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (chr == 's')
		*count += ft_putstr(va_arg(args, char *));
	else if (chr == 'p')
		ptr_checker(args, count);
	else if (chr == 'd' || chr == 'i')
		*count += ft_putnbr(va_arg(args, int));
	else if (chr == 'u')
		*count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (chr == 'x')
		*count += ft_puthexa(va_arg(args, unsigned int), 'a');
	else if (chr == 'X')
		*count += ft_puthexa(va_arg(args, unsigned int), 'A');
	else if (chr == '%')
		*count += ft_putchar('%');
}

int	ft_printf(const char *str, ...)
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
				cases(*str, args, &count);
			else
				break ;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
