/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:22:26 by itamsama          #+#    #+#             */
/*   Updated: 2024/12/22 16:45:09 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_dputnbr_unsigned(int fd, unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		count += ft_dputchar(fd, n + '0');
	else
	{
		count += ft_dputnbr_unsigned(fd, n / 10);
		count += ft_dputchar(fd ,(n % 10) + '0');
	}
	return (count);
}
