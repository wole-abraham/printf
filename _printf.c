#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // To keep track of the number of characters printed

    while (*format) {
        if (*format == '%') {
            format++; // Move past '%'
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int)); // Print a character
                    count++;
                    break;
                case 's':
                    {
                        const char *str = va_arg(args, const char *);
                        while (*str) {
                            putchar(*str); // Print each character in the string
                            count++;
                            str++;
                        }
                    }
                    break;
                case '%':
                    putchar('%'); // Print a literal '%'
                    count++;
                    break;
                default:
                    putchar('%'); // Print the '%' itself
                    count++;
                    putchar(*format); // Print the character following '%'
                    count++;
                    break;
            }
        } else {
            putchar(*format); // Print regular characters
            count++;
        }
        format++; // Move to the next character in the format string
    }

    va_end(args);
    return count;
}

