/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:43:10 by adesille          #+#    #+#             */
/*   Updated: 2023/12/03 13:20:42 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);	
}

int	ft_putstr(char *str)
{
	int	i;

	if(!str)
		return(write(1, "NULL", 4), 4);
	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
	return(i);
}