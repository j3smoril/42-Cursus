/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:17:20 by jesmoril          #+#    #+#             */
/*   Updated: 2024/10/22 17:17:26 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(char *str);
size_t	ft_putchar(int c);
size_t	ft_putstr(char *str);
size_t	ft_numlen(int n, int base);
size_t	ft_putnum(int n);
void	ft_putnbr(int n);
int		ft_putnbr_base(unsigned long num, char *base);
int		ft_putptr(void *ptr);
int		ft_puthex_l(unsigned long num);
int		ft_puthex_u(unsigned long num);
#endif
