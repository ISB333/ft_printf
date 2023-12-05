/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:11:27 by adesille          #+#    #+#             */
/*   Updated: 2023/12/05 12:45:51 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	ft_printf("/////////////////////////////////////\n");
	printf("/////////////////////////////////////\n");
	ft_printf("///// SUPERTEST GIGAMEGAPRO3000 /////\n");
	printf("///// SUPERTEST GIGAMEGAPRO3000 /////\n");
	ft_printf("/////////////////////////////////////\n\n");
	ft_printf("          %s%s\n", "Hello", " World!");
	ft_printf("             %c%c %c%c\n", 'E', 'Z', 'P', 'Z');
	ft_printf("             %d\n        %s\n", 123, "Viva l'algerie");
	ft_printf("          %u\n", 4294967295);
	ft_printf("          %x\n", 2147483647);
	ft_printf("          %x\n", 255);
	ft_printf("          %X\n", 2147483647);
	ft_printf("          %X\n", 255);
	ft_printf("          %%\n");
	ft_printf("0 =  %x \n", 0);
	printf("0 =  %x \n", 0);
	ft_printf(" %p \n", (void *)-1);
	printf(" %p \n", (void *)-1);
	ft_printf(" %p \n", (void *)1);
	printf(" %p \n", (void *)1);
	ft_printf(" %p \n", (void *)15);
	printf(" %p \n", (void *)15);
	ft_printf(" %p \n", (void *)16);
	printf(" %p \n", (void *)16);
	ft_printf(" %p \n", (void *)17);
	printf(" %p \n", (void *)17);
	ft_printf(" %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf(" %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	ft_printf(" %p %p \n", (void *)INT_MIN, (void *)INT_MAX);
	printf(" %p %p \n", (void *)INT_MIN, (void *)INT_MAX);
	ft_printf(" %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf(" %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	ft_printf(" %p %p \n", (void *)0, (void *)0);
	printf(" %p %p \n", (void *)0, (void *)0);
}
