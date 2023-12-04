/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:26:04 by isb3              #+#    #+#             */
/*   Updated: 2023/12/04 15:40:50 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_unsigned(unsigned int n, int len)
{
	char			*str_nbr;

	str_nbr = malloc(len + 1);
	if(!str_nbr)
		return(NULL);
	str_nbr[len] = '\0';
	while (n > 0)
	{
		str_nbr[--len] = n % 10 + '0'; 
		n /= 10;
	}
	return (str_nbr);
}

int	unsigned_digit_counter(unsigned int n)
{
	int				count;

	count = 0;
	while(n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_itoa_unsigned(unsigned int n)
{
	char *result;
	int i;

	i = 0;
	if (n == 0)
		return(write(1, "0", 1), 1);
	result = ft_putnbr_unsigned(n, unsigned_digit_counter(n));
	if(!result)
		return(0);
	while(result[i])
		write(1, &result[i++], 1);
	free(result);
	return(i);
}
