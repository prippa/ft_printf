/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:58:33 by prippa            #+#    #+#             */
/*   Updated: 2018/01/02 15:58:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_c(t_printf *fpf)
{
	char	*str;
	wchar_t	tmp[2];

	if (FC == 'C' || fpf->size_flag == SF_L)
	{
		tmp[0] = (wchar_t)va_arg(fpf->args, int);
		tmp[1] = '\0';
		if (!(str = ft_wstr_to_str(tmp)))
			return (NULL);
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = (char)va_arg(fpf->args, int);
		str[1] = '\0';
	}
	return (str);
}
