/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isb3 <isb3@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:45:43 by isb3              #+#    #+#             */
/*   Updated: 2023/11/29 13:02:38 by isb3             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...) 
{
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;  // Move past '%'
            switch (*format) {
                case 's':
                    // String argument
                    char *str = va_arg(args, char *);
                    printf("String: %s\n", str);
                    break;
                case 'c':
                    // Character argument
                    char ch = va_arg(args, int);  // char is promoted to int in va_arg
                    printf("Character: %c\n", ch);
                    break;
                // Add more cases for other format specifiers as needed
                default:
                    // Handle unsupported format specifiers or other cases
                    break;
            }
        } else {
            putchar(*format);
        }
        format++;  // Move to the next character in the format string
    }

    va_end(args);
    return 0;  // Return whatever is appropriate for your function
}

int main() 
{
    ft_printf("This is a string: %s and a character: %c\n", "Hello, World!", 'A');
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