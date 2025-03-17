/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:05:20 by itamsama          #+#    #+#             */
/*   Updated: 2024/12/22 16:45:15 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putstr(char *x)
{
	int	count;

	count = 0;
	if (!x)
		x = "(null)";
	while (x[count])
		count++;
	write(1, x, count);
	return (count);
}
