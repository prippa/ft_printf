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

size_t	ft_print_di(t_printf *fpf, char c, int size_flag)
{
	int		len;
	char	*str;

	if (c == 'd' || c == 'i')
		str = ft_itoa_lli(ft_conv_sig_int(fpf, size_flag));
	else
		str = ft_itoa_lli(ft_conv_sig_int(fpf, SF_L));
	if (!str)
		return (0);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
