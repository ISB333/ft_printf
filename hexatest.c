#include <unistd.h>
#include <stdio.h>

void print_hexadecimal(int decimal) {
    char hex_digits[] = "0123456789ABCDEF";
    char hex_result[20];  // Assuming a 32-bit integer; adjust as needed
    int index = 0;

    // Handle the case when the number is 0 separately
    if (decimal == 0) {
        write(1, "0", 1);
        return;
    }

    // Convert decimal to hexadecimal
    while (decimal > 0) {
        int remainder = decimal % 16;
        printf("remainder = %d\nhexa = %c\n\n", remainder, hex_digits[remainder]);
        hex_result[index] = hex_digits[remainder];
        decimal /= 16;
        index++;
    }

    // Write the hexadecimal digits in reverse order
    for (int i = index - 1; i >= 0; i--) {
        write(1, &hex_result[i], 1);
    }
    printf("\n-------------------------------\n");
}

int main() {
    print_hexadecimal(2147483647);
    print_hexadecimal(255);

    return 0;
}