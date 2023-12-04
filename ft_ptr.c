/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:42:45 by adesille          #+#    #+#             */
/*   Updated: 2023/12/04 13:11:50 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_ptr(unsigned long long ptr)
{
	char *hex_digits;
	char hex_result[20];
	int index = 0;
	int i = 0;
	uintptr_t n = (uintptr_t)ptr;

	hex_digits = "0123456789abcdef";
	while (n > 0)
	{
		int remainder = n % 16;
		hex_result[index] = hex_digits[remainder];
		n /= 16;
		index++;
	}
	i = index - 1;
	write(1, "0x", 2);
	while(i >= 0)
		write(1, &hex_result[i--], 1);
	return index;
}

// int main() 
// {
//     int value = 42;
//     ft_put_hexa_ptr(&value, 'x');  // Example with 'x' format
//     return 0;
// }
