/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:45:43 by isb3              #+#    #+#             */
/*   Updated: 2023/12/01 18:01:14 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// TODO 1 /// Check if I need to put functions in static
/// TODO 2 /// Read carefully rules (for once lol)
/// TODO 3 /// Return the size
/// TODO 4 /// ??? Protect the write function ???

int	format_identifier(va_list args, const char format)
{	
	int printed_len;

	printed_len = 0;
	if (format == 's')
		ft_putstr(va_arg(args, char *));
	else if (format == 'c')
		ft_putchar(va_arg(args, int));
	// if (format[i] == 'i')
	return (printed_len);
}

int ft_printf(const char *format, ...) 
{
	int 		i = 0;
    va_list		args;
	int full_printed_len;

    va_start(args, format);
    while (format[i])
	{
        if (format[i] == '%')
		{
			full_printed_len += format_identifier(args, format[i + 1]);
			i++;
		}
		else
			write(1, &format[i], 1);
		i++;
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