/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:44:49 by prippa            #+#    #+#             */
/*   Updated: 2018/01/02 13:44:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_x(t_printf **fpf, char c, int size_flag)
{
	int		len;
	char	*str;

	if (c == 'x')
		str = ft_itoa_base(ft_conv_unsig_int(&(*fpf), size_flag), 16, 87, 0);
	else
		str = ft_itoa_base(ft_conv_unsig_int(&(*fpf), size_flag), 16, 55, 0);
	if (!str)
		return (0);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
