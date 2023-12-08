/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:11:47 by adesille          #+#    #+#             */
/*   Updated: 2023/12/08 16:29:42 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa_lowerx(unsigned int n, char *hex_result)
{
	char	*hex_digits;
	int		i_hexa;
	int		i;

	i = 0;
	hex_digits = "0123456789abcdef";
	while (n > 0)
	{
		i_hexa = n % 16;
		hex_result[i] = hex_digits[i_hexa];
		n /= 16;
		i++;
	}
	i_hexa = i;
	while (i - 1 >= 0)
	{
		if (write(1, &hex_result[--i], 1) == -1)
			return (free(hex_result), -1);
	}
	free(hex_result);
	return (i_hexa);
}

int	ft_put_hexa_upperx(unsigned int n, char *hex_result)
{
	char	*hex_digits;
	int		i_hexa;
	int		i;

	i = 0;
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
	{
		if (write(1, &hex_result[--i], 1) == -1)
			return (free(hex_result), -1);
	}
	free(hex_result);
	return (i_hexa);
}

int	hexa_digit_counter(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_put_hexa(unsigned int n, const char format)
{
	int		size;
	char	*hex_result;

	if (n == 0)
		return (write(1, "0", 1));
	size = hexa_digit_counter(n);
	hex_result = malloc(size + 1);
	if (!hex_result)
		return (-1);
	hex_result[size] = '\0';
	if (format == 'x')
		return (ft_put_hexa_lowerx(n, hex_result));
	if (format == 'X')
		return (ft_put_hexa_upperx(n, hex_result));
	return (0);
}
