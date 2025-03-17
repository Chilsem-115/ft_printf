/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:51:58 by itamsama          #+#    #+#             */
/*   Updated: 2024/12/22 16:45:12 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_dputnbr(int fd, int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_dputchar(fd, '-');
		count += ft_dputchar(fd, '2');
		n = 147483648;
	}
	if (n < 0)
	{
		count += ft_dputchar(fd, '-');
		n = -n;
	}
	if (n < 10)
		count += ft_dputchar(fd, n + '0');
	else
	{
		count += ft_dputnbr(fd ,n / 10);
		count += ft_dputchar(fd ,(n % 10) + '0');
	}
	return (count);
}
