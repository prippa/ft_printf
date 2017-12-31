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
	wchar_t wstr[3];
	wstr[0] = L'♥';
	wstr[1] = L'+';
	wstr[2] = L'\0';
	printf("%d\n", ft_printf("%c\n", '$'));
	printf("%d\n", ft_printf("%C\n", L'斯'));
	printf("%d\n", ft_printf("%S\n", wstr));
	return (0);
}
