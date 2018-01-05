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
	int width = 20;
	int preci = 5;
	// printf("%d\n", ft_printf("%0*.*p\n", width, preci, &printf));
	// printf("%d\n", printf("%0*.*p\n", width, preci, &printf));
	printf("%10.5d", 4242);
	// printf("%d\n", ft_printf("%010.*lC\n", a, L'ツ'));
	// printf("%d\n", printf("%010.*C\n", a, L'ツ'));
	//printf("%d\n", printf("{%05.1C}", L'ツ'));
	//printf("%d\n", ft_printf("{%5c}", 0));
	//printf("%d\n", printf("%05.2s is a string", ""));
	// printf("%d\n", ft_printf("%010.4S\n", L"ツツツ"));
	// printf("%d\n", printf("{%5c}", 0));
	return (0);
}

//system("leaks a.out > leaks");
