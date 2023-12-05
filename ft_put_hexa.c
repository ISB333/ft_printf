/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:11:47 by adesille          #+#    #+#             */
/*   Updated: 2023/12/05 12:15:33 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa(unsigned int n, const char format)
{
	char	*hex_digits;
	char	hex_result[20];
	int		i_hexa;
	int		i;

	i = 0;
	if (n == 0)
		return (write(1, "0", 1), 1);
	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	while (n > 0)
	{
		i_hexa = n % 16;
		hex_result[i] = hex_digits[i_hexa];
		n /= 16;
		i++;
	}
	i_hexa = i;
	while (i - 1 >= 0)
		write(1, &hex_result[--i], 1);
	return (i_hexa);
}
