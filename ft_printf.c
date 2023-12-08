/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:45:43 by adesille          #+#    #+#             */
/*   Updated: 2023/12/08 16:25:10 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_identifier(va_list args, const char format)
{
	int	len;

	len = 0;
	if (!format)
		return (-1);
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

int	ft_print_n_check(const char *str, va_list args, int security_check)
{
	int	full_printed_len;
	int	i;

	i = 0;
	full_printed_len = 0;
	while (str[i])
	{
		security_check = 0;
		if (str[i] == '%')
		{
			security_check += format_identifier(args, str[++i]);
			if (security_check == -1)
				return (-1);
			full_printed_len += security_check;
		}
		else
		{
			security_check += ft_putchar(str[i]);
			if (security_check == -1)
				return (-1);
			full_printed_len += security_check;
		}
		i++;
	}
	return (full_printed_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		full_printed_len;
	int		security_check;

	security_check = 0;
	full_printed_len = 0;
	va_start(args, str);
	full_printed_len = ft_print_n_check(str, args, security_check);
	if (full_printed_len == -1)
		return (-1);
	va_end(args);
	return (full_printed_len);
}
