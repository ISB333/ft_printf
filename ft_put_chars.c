/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:43:10 by adesille          #+#    #+#             */
/*   Updated: 2023/12/06 17:09:30 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (!write(1, &c, 1))
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		if (!write(1, "(null)", 6))
			return (0);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		if (!write (1, &str[i++], 1))
			return (-1);
	}
	return (i);
}
