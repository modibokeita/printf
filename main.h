#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
int _printf(const char *format, ...);
int print_int(int num);
int print_octal(unsigned int num);
int print_hexadecimal(unsigned int num, int uppercase);
int print_uint(unsigned int num);
int handler(const char *format, ...);
#endif
