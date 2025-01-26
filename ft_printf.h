/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:47:40 by itamsama          #+#    #+#             */
/*   Updated: 2024/12/22 16:44:56 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
void	ft_puthex_digit(unsigned char digit, char case_char);
int		ft_puthexa(unsigned long num, char case_char);
int		ft_printf(const char *format, ...);

#endif
