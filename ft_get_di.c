/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dDi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:23:44 by prippa            #+#    #+#             */
/*   Updated: 2018/01/02 14:23:46 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_di(t_printf *fpf)
{
	char	*str;

	if (FC == 'd' || FC == 'i')
		str = ft_itoa(ft_conv_sig_int(fpf));
	else if (FC == 'D' && (fpf->size_flag = SF_L))
		str = ft_itoa(ft_conv_sig_int(fpf));
	if (!str)
		return (NULL);
	return (str);
}
