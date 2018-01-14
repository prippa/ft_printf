
#include "ft_printf.h"

void	ft_charjoin(t_printf *fpf, int n, char c)
{
	char	*str;
	int		size;

	size = n;
	if (n < 1)
		return ;
	if (!(str = (char *)malloc(sizeof(char) * n + 1)))
		return ;
	str[n] = '\0';
	while (--n >= 0)
		str[n] = c;
	ft_strjoin(fpf, str, size);
	free(str);
}