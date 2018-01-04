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
#include <locale.h>
#include <stdio.h>

// printf("flags (%s)\nwidth (%d)\nprecision (%d)\nsize_flag (%d)\ntype (%c)\nstr (%s)\n",
// 					flg.flag,
// 					flg.width,
// 					flg.precision,
// 					flg.size_flag,
// 					flg.type,
// 					flg.str);

int	main(void)
{
	setlocale(LC_ALL, "");
	unsigned long long int a = -1;
	//printf("%.5s = %0******.*f\n", "value trash", 10, 5, 3.141590000000000);
	//ft_printf("%#-+   10.15llx!$#", a);
	//printf("%030.17llx\n", a);
	ft_printf("%lc\n", L'ة');
	// char str[5];
	// int i = 0;

	// ft_bzero(str, 5);
	// while (str[i] == '\0')
	// 	printf("%d\n", i++);
	return (0);
}
