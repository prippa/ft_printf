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

    // printf("%d\n", printf("%ls\n", L"مرحبا!"));
    // printf("%d\n", ft_printf("%S\n", L"مرحبا!"));
	// wchar_t wstr[3];
	// wstr[0] = L'♥';
	// wstr[1] = L'+';
	// wstr[2] = L'\0';
	// printf("%d\n", ft_printf("%c\n", '$'));
	// printf("%d\n", ft_printf("%C\n", L'斯'));
	//printf("%d\n", ft_printf("%S\n", L"مرحبا!"));

	int a = 10;
	int *b = &a;
	char *str = "Hello Wordl!";
	char **arr = &str;
	printf("%p\n", 0);
	ft_printf("%p\n", 0);

	return (0);
}
