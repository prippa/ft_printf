
#include "ft_printf.h"

size_t	ft_print_signed_int(t_printf **fpf, char c)
{
	char *str;

	if (c == 'D')
		str = ft_itoa_lli(va_arg((*fpf)->args, long));
	else if (c == 'd' || c == 'i')
		str = ft_itoa_lli(va_arg((*fpf)->args, int));
	return (write(1, str, ft_strlen(str)));
}
