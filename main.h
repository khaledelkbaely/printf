#ifndef PRINT_H
#define PRINT_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int _print_decimal(long int n);
int _print_binary(unsigned int n);
int _strlen(char *);
void reverse(char *);
int handle_format_specifier(va_list args, char specifier);

#endif /* PRINT_H */
