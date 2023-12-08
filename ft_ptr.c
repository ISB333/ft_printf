/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:42:45 by adesille          #+#    #+#             */
/*   Updated: 2023/12/08 16:27:25 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptrhexa(unsigned long long n, char *hex_result)
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

int	ptr_digit_counter(unsigned long long n)
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

int	ft_ptr(unsigned long long n)
{
	int		size;
	char	*hex_result;

	if (n == 0)
		return (write(1, "0x0", 3));
	size = ptr_digit_counter(n);
	hex_result = malloc(size + 1);
	if (!hex_result)
		return (-1);
	hex_result[size] = '\0';
	if (write(1, "0x", 2) == -1)
		return (free(hex_result), -1);
	return (ft_put_ptrhexa(n, hex_result) + 2);
}
