/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:28:54 by prippa            #+#    #+#             */
/*   Updated: 2018/01/05 12:28:57 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_width(int n, char c)
{
	size_t len;

	len = 0;
	if (n > 0)
		while (n--)
			len += write(1, &c, 1);
	return(len);
}
