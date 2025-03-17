/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:18:22 by itamsama          #+#    #+#             */
/*   Updated: 2024/12/22 16:52:54 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	hexa(unsigned long num, char case_char)
{
	char	*hex_digits;
	int		len;

	len = 0;
	if (case_char == 'A')
		hex_digits = "0123456789ABCDEF";
	else if (case_char == 'a')
		hex_digits = "0123456789abcdef";
	if (num > 0)
	{
		len += hexa((num / 16), case_char);
		len += ft_putchar(hex_digits[num % 16]);
	}
	return (len);
}

int	ft_puthexa(unsigned long num, char case_char)
{
	if (num == 0)
		return (ft_putchar('0'));
	return (hexa(num, case_char));
}
