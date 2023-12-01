/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:42:44 by isb3              #+#    #+#             */
/*   Updated: 2023/12/01 16:32:44 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int     ft_printf(const char *, ...);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_itoa(int n);

#endif