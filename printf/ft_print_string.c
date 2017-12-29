
#include "ft_printf.h"

size_t	ft_print_string(t_printf **fpf, char c)
{
	char *str;

	if (c == 's')
		str = va_arg((*fpf)->args, char *);
	if (c == 'S')
		return (0);
	return (write(1, str, ft_strlen(str)));
}
