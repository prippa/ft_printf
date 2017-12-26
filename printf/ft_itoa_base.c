/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:14:32 by prippa            #+#    #+#             */
/*   Updated: 2017/12/26 17:14:55 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned long long int n, int base, int flag, int len)
{
	char						tab[65];
	int							i;
	unsigned long long int		tmp;
	unsigned long long int		rest;

	if (base < 2 && base > 16)
		return (NULL);
	tab[64] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	tmp = n;
	i = 64;
	while (tmp != 0)
	{
		rest = tmp % base;
		tmp = tmp / base;
		if (base > 10 && rest > 9)
			tab[--i] = rest + flag;
		else
			tab[--i] = rest + 48;
	}
	return (ft_strdup(tab + i + len));
}
