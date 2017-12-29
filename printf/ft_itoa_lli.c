
#include "ft_printf.h"

static int	ft_itoa_len(long long int num)
{
	long long int	flag;
	int				len;

	if (num < 0)
		flag = -0 - num;
	else
		flag = num;
	len = 0;
	while (flag)
	{
		flag /= 10;
		len++;
	}
	if (num == 0)
		len++;
	return (len);
}

char		*ft_itoa_lli(long long int num)
{
	int		len;
	int		flag;
	char	*fresh;

	if (num == -9223372036854775808)
		return (ft_strdup("-9223372036854775808"));
	len = ft_itoa_len(num);
	flag = 0;
	if (num < 0)
		flag++;
	if ((fresh = ft_strnew(len + flag)) == NULL)
		return (NULL);
	if (flag == 1)
	{
		fresh[0] = '-';
		num = -0 - num;
	}
	len += flag;
	fresh[len] = '\0';
	while (flag <= --len)
	{
		fresh[len] = ((num % 10) + '0');
		num /= 10;
	}
	return (fresh);
}