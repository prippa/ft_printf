/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:07:32 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:07:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char		*ft_itoa(long long int num)
{
	int		len;
	int		flag;
	char	*fresh;

	if (num == (-9223372036854775807) - 1)
		return (ft_strdup("-9223372036854775808"));
	len = ft_itoa_len(num);
	if (!(flag = 0) && num < 0)
		flag++;
	if (!(fresh = (char *)malloc(sizeof(char) * len + flag + 1)))
		return (NULL);
	fresh[len + flag] = '\0';
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
