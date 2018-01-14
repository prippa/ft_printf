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

char	*ft_get_oux(t_printf *fpf)
{
	char	*str;

	if (FC == 'o')
		str = ft_itoa_base(ft_conv_unsig_int(fpf), 8, 0);
	else if (FC == 'O' && (fpf->size_flag = SF_L))
		str = ft_itoa_base(ft_conv_unsig_int(fpf), 8, 0);
	else if (FC == 'u')
		str = ft_itoa_base(ft_conv_unsig_int(fpf), 10, 0);
	else if (FC == 'U' && (fpf->size_flag = SF_L))
		str = ft_itoa_base(ft_conv_unsig_int(fpf), 10, 0);
	else if (FC == 'x')
		str = ft_itoa_base(ft_conv_unsig_int(fpf), 16, 87);
	else if (FC == 'X' && (fpf->size_flag = SF_L))
		str = ft_itoa_base(ft_conv_unsig_int(fpf), 16, 55);
	if (!str)
		return (NULL);
	return (str);
}
