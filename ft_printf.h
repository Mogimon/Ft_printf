#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_printf(const char *, ...);
int	ft_printchar(int c);
int	ft_printnbr(int n);
int	ft_printstr(char *s);
int	ft_printptr(unsigned long long ptr);
int	ft_hex(unsigned long long num, const char c);
int	ft_unsigned(unsigned int n);

#endif