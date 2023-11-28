/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:45:43 by isb3              #+#    #+#             */
/*   Updated: 2023/11/28 19:12:47 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int ft_printf(const char *, ...)
{
	int	len;
	va_list args;

	va_start(args, format);
	if (%s)
		va_arg(args, char *);
	if (%c)
		va_arg(args, char);
	if (%d)
		va_arg(args, int);
	if (%i)
		va_arg(args, int);
	if (%u)
		va_arg(args, unsigned int);
	if (%x)
		va_arg(args, unsigned int);
	if (%X)
		va_arg(args, unsigned int);
	if (%p)
		va_arg(args, void *);
	if (%%)
		va_arg(args, '%');
}