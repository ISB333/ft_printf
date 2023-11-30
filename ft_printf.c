/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:45:43 by isb3              #+#    #+#             */
/*   Updated: 2023/11/30 18:09:08 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...) 
{
	char		*str;
	char		c;
    va_list		args;
    va_start(args, format);

    while (*format)
	{
        if (*format == '%')
		{
            format++;
			if (*format == 's')
			{
				str = va_arg(args, char *);
				ft_putstr(str);
			}
			if (*format == 'c')
			{
				c = va_arg(args, int);
				ft_putchar(c);
			}
			if (*format == 'i')
			{

			}
        }
		else
			write(1, format, 1);
        format++;
    }
    va_end(args);
    return 0;
}

int main() 
{
    ft_printf("/////////////////////////////////////\n");
    ft_printf("///// SUPERTEST GIGAMEGAPRO3000 /////\n");
    ft_printf("/////////////////////////////////////\n\n");
    ft_printf("          %s%s\n", "Hello"," World!");
    ft_printf("             %c%c %c%c\n", 'E', 'Z', 'P', 'Z');
    return 0;
}

	// if (%s)
	// 	va_arg(args, char *);
	// if (%c)
	// 	va_arg(args, char);
	// if (%d)
	// 	va_arg(args, int);
	// if (%i)
	// 	va_arg(args, int);
	// if (%u)
	// 	va_arg(args, unsigned int);
	// if (%x)
	// 	va_arg(args, unsigned int);
	// if (%X)
	// 	va_arg(args, unsigned int);
	// if (%p)
	// 	va_arg(args, void *);
	// if (%%)
	// 	va_arg(args, '%');

// int main(void)
// {
// 	ft_printf("Gang Gang\n");
// 	ft_printf("");
// 	// ft_printf("ft_printf: %s\n", "Yo Man");
// 	// ft_printf("ft_printf: %c\n", 'W');
// 	// ft_printf("ft_printf: %s\n%s\n", "Yo Man", "Yo Bastard");
// 	// ft_printf("ft_printf: %c%c%c%c\n", 'W', 'o', 'l', 'a');
// 	// ft_printf("ft_printf: C'est pas ma %s mon colonel%c", "guerre", '\n');
// 	// ft_printf("ft_printf: %d - %d\n", 150, -150);
// 	// ft_printf("ft_printf: %i - %i\n", -2147483648, 2147483647;
// 	// ft_printf("ft_printf: %u\n", 4294967295);
// 	// ft_printf("ft_printf: \n");
// 	// ft_printf("ft_printf: \n");
// 	// ft_printf("ft_printf: \n");
	

// }