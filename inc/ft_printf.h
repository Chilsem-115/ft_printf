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

#ifndef FT_COMBINED_PRINTF_H
# define FT_COMBINED_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/* ft_printf functions */
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
void	ft_puthex_digit(unsigned char digit, char case_char);
int		ft_puthexa(unsigned long num, char case_char);
int		ft_printf(const char *format, ...);

/* ft_fprintf functions */
void	ft_dputhex_digit(int fd, unsigned char digit, char case_char);
void	ft_dputptr(int fd, va_list args, int *count);
int		ft_dputchar(int fd, int c);
int		ft_dputstr(int fd, char *s);
int		ft_dputnbr(int fd, int n);
int		ft_dputnbr_unsigned(int fd, unsigned int n);
int		ft_dputhexa(int fd, unsigned long num, char case_char);
int		ft_dprintf(int fd, const char *format, ...);

#endif
