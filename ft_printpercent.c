#include "ft_printf.h"

int ft_printpercent(int c)
{
    write(1, "%", 1);
    return (1);
}