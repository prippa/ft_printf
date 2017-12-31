
#include "ft_printf.h"

size_t	ft_print_char(t_printf **fpf, char c)
{
	char *ch;
	wchar_t tmp[2];

	if (c == 'c')
	{
		if (!(ch = ft_strnew(1)))
			return (0);
		ch[0] = (char)va_arg((*fpf)->args, int);
	}
	else if (c == 'C')
	{
		tmp[0] = (wchar_t)va_arg((*fpf)->args, int);
		tmp[1] = '\0';
		ch = ft_wstr_to_str(tmp);
	}
	return (write(1, ch, ft_strlen(ch)));
}
