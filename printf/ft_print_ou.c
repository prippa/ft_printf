/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oOuU.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:44:35 by prippa            #+#    #+#             */
/*   Updated: 2018/01/02 13:44:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_ou(t_printf **fpf, char c, int size_flag)
{
	int		len;
	char	*str;

	if (c == 'o')
		str = ft_itoa_base(ft_conv_unsig_int(&(*fpf), size_flag), 8, 0, 0);
	else if (c == 'O')
		str = ft_itoa_base(ft_conv_unsig_int(&(*fpf), SF_L), 8, 0, 0);
	else if (c == 'u')
		str = ft_itoa_base(ft_conv_unsig_int(&(*fpf), size_flag), 10, 0, 0);
	else
		str = ft_itoa_base(ft_conv_unsig_int(&(*fpf), SF_L), 10, 0, 0);
	if (!str)
		return (0);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
