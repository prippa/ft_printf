/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 12:12:53 by prippa            #+#    #+#             */
/*   Updated: 2018/01/02 12:12:56 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_p(t_printf **fpf)
{
	int		len;
	char	*base_str;
	char	*str;

	if (!(base_str = ft_itoa_base(va_arg((*fpf)->args, unsigned long int),
															16, 87, 0)))
		return (0);
	if (!(str = ft_strjoin("0x", base_str)))
		return (0);
	len = write(1, str, ft_strlen(str));
	free(base_str);
	free(str);
	return (len);
}
