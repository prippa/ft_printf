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

size_t	ft_print_c(t_printf *fpf, char c, int size_flag)
{
	int		len;
	char	ch;
	char	*str;
	wchar_t	tmp[2];

	if (size_flag == SF_L)
		c = 'C';
	if (c == 'c')
	{
		ch = (char)va_arg(fpf->args, int);
		return (write(1, &ch, 1));
	}
	else
	{
		tmp[0] = (wchar_t)va_arg(fpf->args, int);
		if (!tmp[0])
			return (write(1, "\0", 1));
		tmp[1] = '\0';
		if (!(str = ft_wstr_to_str(tmp)))
			return (0);
	}
	len = write(1, str, ft_strlen(str));
	if (c == 'C')
		free(str);
	return (len);
}
