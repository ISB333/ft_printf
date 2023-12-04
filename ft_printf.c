/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:45:43 by isb3              #+#    #+#             */
/*   Updated: 2023/12/04 20:24:33 by isb3             ###   ########.fr       */
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
		return(printed_len += ft_putstr(va_arg(args, char *)), printed_len);
	else if (format == 'c')
		return(printed_len += ft_putchar(va_arg(args, int)), printed_len);
	else if (format == 'd' || format == 'i')
		return(printed_len += ft_itoa(va_arg(args, int)), printed_len);
	else if (format == 'u')
		return(printed_len += ft_itoa_unsigned(va_arg(args, unsigned int)), printed_len);
	else if (format == 'x' || format == 'X')
		return(printed_len += ft_put_hexa(va_arg(args, unsigned int), format), printed_len);
	else if (format == 'p')
		return(printed_len += ft_ptr(va_arg(args, unsigned long long)), printed_len);
	else if (format == '%')
		return(write(1, "%", 1), 1);
	return (0);
}

int ft_printf(const char *format, ...) 
{
	int 		i = 0;
	va_list		args;
	int full_printed_len = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return(0);
			full_printed_len += format_identifier(args, format[i + 1]);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			full_printed_len++;
		}
		i++;
	}
	// printf("%d\n\n", full_printed_len);
	va_end(args);
	return (full_printed_len);
}

// int main() 
// {
// 	int size = ft_printf("/////////////////////////////////////\n");
//  	int size2 = printf("/////////////////////////////////////\n");
//     printf("size = %d\n", size); 
//     printf("size = %d\n", size2); 
//     int size3 = ft_printf("///// SUPERTEST GIGAMEGAPRO3000 /////\n");
//     int size4 = printf("///// SUPERTEST GIGAMEGAPRO3000 /////\n");
//     printf("size = %d\nsize = %d\n", size3, size4); 
//     ft_printf("/////////////////////////////////////\n\n");
//     ft_printf("          %s%s\n", "Hello"," World!");
// 	ft_printf(" NULL %s NULL\n", NULL);
// 	printf(" NULL %s NULL\n", NULL);
//     ft_printf("             %c%c %c%c\n", 'E', 'Z', 'P', 'Z');
//     ft_printf("             %d\n        %s\n", 123, "Viva l'algerie");
//     ft_printf("          %u\n", 4294967295);
//     ft_printf("          %x\n", 2147483647);
//     ft_printf("          %x\n", 255);
//     ft_printf("          %X\n", 2147483647);
//     ft_printf("          %X\n", 255);
//     ft_printf("          %%\n");
// 	ft_printf("0 =  %x \n", 0);
// 	printf("0 =  %x \n", 0);
// 	ft_printf(" %p \n", (void *)-1);
// 	printf(" %p \n", (void *)-1);
// 	ft_printf(" %p \n", (void *)1);
// 	printf(" %p \n", (void *)1);
// 	ft_printf(" %p \n", (void *)15);
// 	printf(" %p \n", (void *)15);
// 	ft_printf(" %p \n", (void *)16);
// 	printf(" %p \n", (void *)16);
// 	ft_printf(" %p \n", (void *)17);
// 	printf(" %p \n", (void *)17);
// 	ft_printf(" %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
// 	printf(" %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
// 	ft_printf(" %p %p \n", (void *)INT_MIN, (void *)INT_MAX);
// 	printf(" %p %p \n", (void *)INT_MIN, (void *)INT_MAX);
// 	ft_printf(" %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
// 	printf(" %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
// 	ft_printf(" %p %p \n", (void *)0, (void *)0);
// 	printf(" %p %p \n", (void *)0, (void *)0);
//     return 0;
// }

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


/* 
TEST(10, print(" NULL %s NULL ", NULL));
*/