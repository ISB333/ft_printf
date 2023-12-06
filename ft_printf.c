/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:45:43 by adesille          #+#    #+#             */
/*   Updated: 2023/12/06 17:12:33 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_identifier(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 's')
		return (len += ft_putstr(va_arg(args, char *)), len);
	else if (format == 'c')
		return (len += ft_putchar(va_arg(args, int)), len);
	else if (format == 'd' || format == 'i')
		return (len += ft_itoa(va_arg(args, int)), len);
	else if (format == 'u')
		return (len += ft_itoa_unsigned(va_arg(args, unsigned int)), len);
	else if (format == 'x' || format == 'X')
		return (len += ft_put_hexa(va_arg(args, unsigned int), format), len);
	else if (format == 'p')
		return (len += ft_ptr(va_arg(args, unsigned long long)), len);
	else if (format == '%')
		return (write(1, "%", 1), 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int			full_printed_len;
	int			i;
	va_list		args;

	i = 0;
	full_printed_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (-1);
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
	va_end(args);
	return (full_printed_len);
}
