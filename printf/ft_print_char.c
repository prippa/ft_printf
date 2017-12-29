
#include "ft_printf.h"

size_t	ft_print_char(t_printf **fpf, char c)
{
	int l;

	if (c == 'c')
	{
		l = va_arg((*fpf)->args, int);
		return (write(1, &l, 1));
	}
	return (0);
}
