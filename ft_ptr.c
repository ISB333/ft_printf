/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:42:45 by adesille          #+#    #+#             */
/*   Updated: 2023/12/06 17:11:45 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(unsigned long long ptr)
{
	uintptr_t	n;
	char		*hexa_base;
	char		result[20];
	int			i_hexa;
	int			i;

	i = 0;
	n = (uintptr_t)ptr;
	if (!n)
		return (ft_putstr("0x0"), 3);
	hexa_base = "0123456789abcdef";
	while (n > 0)
	{
		i_hexa = n % 16;
		result[i] = hexa_base[i_hexa];
		n /= 16;
		i++;
	}
	if (!write(1, "0x", 2))
		return (-1);
	i_hexa = i;
	while (i - 1 >= 0)
		ft_putchar(result[--i]);
	return (i_hexa + 2);
}
