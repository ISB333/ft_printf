/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:26:04 by isb3              #+#    #+#             */
/*   Updated: 2023/12/04 19:50:22 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr(int n, int digit_nbr)
{
	char	*str_nbr;
	int		len;
	int		token;

	token = 0;
	len = digit_nbr;
	str_nbr = malloc(digit_nbr + 1);
	if (n < 0)
	{
		n *= -1;
		token = 1;
	}
	while (digit_nbr > 0)
	{
		str_nbr[--digit_nbr] = n % 10 + '0'; 
		n /= 10;
	}
	if (token == 1) 
		str_nbr[0] = '-';
	str_nbr[len] = '\0';
	return (str_nbr);
}

int	digit_counter(int n)
{
	int count;
	int temp_n;

	temp_n = n;
	count = 0;
	if (temp_n < 0)
	{
		temp_n *= -1;
		count ++;
	}
	while(temp_n > 0)
	{
		temp_n /= 10;
		count++;
	}
	return (count);
}

int	ft_itoa(int n)
{
	int digit_nbr;
	char *result;
	int i;

	i = 0;
	if (n == 0)
		return(write(1, "0", 1), 1);
	if (n == -2147483648)
		return(write(1, "-2147483648", 11), 11);
	digit_nbr = digit_counter(n);
	result = ft_putnbr(n, digit_nbr);
	while(result[i])
		write(1, &result[i++], 1);
	free(result);
	return(digit_nbr);
}
