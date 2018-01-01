
#include "ft_printf.h"

size_t	ft_print_char(t_printf **fpf, char c)
{
	char ch;
	char *str;
	wchar_t tmp[2];

	if (c == 'c')
	{
		ch = (char)va_arg((*fpf)->args, int);
		return(write(1, &ch, 1));
	}
	else if (c == 'C')
	{
		tmp[0] = (wchar_t)va_arg((*fpf)->args, int);
		if (!tmp[0])
			return (write(1, "\0", 1));
		tmp[1] = '\0';
		str = ft_wstr_to_str(tmp);
	}
	return (write(1, str, ft_strlen(str)));
}
