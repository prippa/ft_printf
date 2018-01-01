
#include "ft_printf.h"

size_t	ft_print_string(t_printf **fpf, char c)
{
	void *data;
	char *str;

	data = va_arg((*fpf)->args, void *);
	if (c == 'p')
		str = ft_strjoin("0x", ft_itoa_base((unsigned long int)data, 16, 87, 0));
	else
	{
		if (!data)
			return(write(1, "(null)", 6));
		if (c == 's')
			str = (char *)data;
		else if (c == 'S')
			str = ft_wstr_to_str((wchar_t *)data);
	}
	return (write(1, str, ft_strlen(str)));
}
