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

int	main(void)
{
	setlocale(LC_ALL, "");
	//printf("%.5s = %0******.*f\n", "value trash", 10, 5, 3.141590000000000);
	printf("%***c\n", 2, 3, 4, '$');
	// char str[5];
	// int i = 0;

	// ft_bzero(str, 5);
	// while (str[i] == '\0')
	// 	printf("%d\n", i++);
	return (0);
}
