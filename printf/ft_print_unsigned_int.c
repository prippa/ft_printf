
#include "ft_printf.h"

size_t	ft_print_unsigned_int(t_printf **fpf, char c)
{
	char *str;

	if (c == 'o')
		str = ft_itoa_base(va_arg((*fpf)->args, unsigned int), 8, 0, 0);
	else if (c == 'O')
		str = ft_itoa_base(va_arg((*fpf)->args, unsigned long), 8, 0, 0);
	else if (c == 'u')
		str = ft_itoa_base(va_arg((*fpf)->args, unsigned int), 10, 0, 0);
	else if (c == 'U')
		str = ft_itoa_base(va_arg((*fpf)->args, unsigned long), 10, 0, 0);
	else if (c == 'x')
		str = ft_itoa_base(va_arg((*fpf)->args, unsigned int), 16, 87, 0);
	else if (c == 'X')
		str = ft_itoa_base(va_arg((*fpf)->args, unsigned long), 16, 55, 0);
	return (write(1, str, ft_strlen(str)));
}
