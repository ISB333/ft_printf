/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:42:44 by adesille          #+#    #+#             */
/*   Updated: 2023/12/05 12:26:52 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_itoa(int n);
int	ft_itoa_unsigned(unsigned int n);
int	ft_put_hexa(unsigned int n, const char format);
int	ft_ptr(unsigned long long ptr);

#endif