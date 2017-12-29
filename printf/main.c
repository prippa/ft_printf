/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:32:13 by prippa            #+#    #+#             */
/*   Updated: 2017/12/21 16:32:21 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	unsigned long long int ulli = -42;
	// long long int num = -9223372036854775806;
	// printf("%d\n", num);
	// printf("%s\n", ft_itoa_lli((int)num));
	// printf("%d\n", ft_printf("%%%s: (%d%c)", "Piglads", 123, '$'));
	// printf("%d\n", printf("%%%s: (%d%c)", "Piglads", 123, '$'));
	printf("%d\n", ft_printf("%o\n", ulli));
	printf("%d\n", printf("%o\n", ulli));
	return (0);
}
