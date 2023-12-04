/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:11:47 by adesille          #+#    #+#             */
/*   Updated: 2023/12/04 19:49:03 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int ft_put_hexa(unsigned int n, const char format) 
{
	char *hex_digits; 
	char hex_result[20];
	int index = 0;
	int i;
	
	if (n == 0)
		return(write(1, "0", 1), 1);
	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	while (n > 0)
	{
		int remainder = n % 16;
		hex_result[index] = hex_digits[remainder];
		n /= 16;
		index++;
	}
	i = index - 1;
	while(i >= 0)
		write(1, &hex_result[i--], 1);
	return(index);
}
