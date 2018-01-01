
#include "ft_printf.h"

size_t	ft_print_string(t_printf **fpf, char c)
{
	char *str;

	if (c == 's')
		str = va_arg((*fpf)->args, char *);
	else if (c == 'S')
		str = ft_wstr_to_str(va_arg((*fpf)->args, wchar_t *));
	return (write(1, str, ft_strlen(str)));
}
