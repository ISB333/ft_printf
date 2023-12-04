/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:26:04 by isb3              #+#    #+#             */
/*   Updated: 2023/12/04 12:56:56 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_unsigned(unsigned int n, unsigned int digit_nbr)
{
	unsigned int	len;
	char			*str_nbr;

	len = digit_nbr;
	str_nbr = malloc(digit_nbr + 1);
	while (digit_nbr > 0)
	{
		str_nbr[--digit_nbr] = n % 10 + '0'; 
		n /= 10;
	}
	str_nbr[len] = '\0';
	return (str_nbr);
}

int	unsigned_digit_counter(unsigned int n)
{
	unsigned int	temp_n;
	int				count;

	temp_n = n;
	count = 0;
	while(temp_n > 0)
	{
		temp_n /= 10;
		count++;
	}
	return (count);
}

int	ft_itoa_unsigned(unsigned int n)
{
	int digit_nbr;
	char *result;
	int i;

	i = 0;
	digit_nbr = unsigned_digit_counter(n);
	result = ft_putnbr_unsigned(n, digit_nbr);
	while(result[i])
		write(1, &result[i++], 1);
	free(result);
	return(digit_nbr);
}