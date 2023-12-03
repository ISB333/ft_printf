/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:11:47 by adesille          #+#    #+#             */
/*   Updated: 2023/12/03 13:01:03 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_put_hexa(int n, const char format) 
{
	char *hex_digits; 
	char hex_result[20];
	int index = 0;
	int i;

	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	if (n == 0)
		return(write(1, "0", 1), 1);
	while (n > 0)
	{
		int remainder = n % 16;
		hex_result[index] = hex_digits[remainder];
		n /= 16;
		index++;
	}
	i = index - 1;
	while(i >= 0)
		write(1, &hex_result[i--], 1);
	return(index);
}

// int main() {
//     print_hexadecimal(2147483600);
//     print_hexadecimal(165);
//     print_hexadecimal(15081);

//     return 0;
// }

// void print_hexadecimal(int decimal) {
//     char hex_digits[] = "0123456789ABCDEF";
//     char hex_result[20];  // Assuming a 32-bit integer; adjust as needed
//     int index = 0;

//     // Handle the case when the number is 0 separately
//     if (decimal == 0) {
//         write(1, "0", 1);
//         return;
//     }

//     // Convert decimal to hexadecimal
//     while (decimal > 0) {
//         int remainder = decimal % 16;
//         printf("remainder = %d\nhexa = %c\n\n", remainder, hex_digits[remainder]);
//         hex_result[index] = hex_digits[remainder];
//         decimal /= 16;
//         index++;
//     }

//     // Write the hexadecimal digits in reverse order
//     for (int i = index - 1; i >= 0; i--) {
//         write(1, &hex_result[i], 1);
//     }
//     printf("\n-------------------------------\n");
// }