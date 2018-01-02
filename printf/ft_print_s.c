/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:48:07 by prippa            #+#    #+#             */
/*   Updated: 2018/01/02 15:48:12 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_s(t_printf **fpf, char c)
{
	int		len;
	void	*data;
	char	*str;

	data = va_arg((*fpf)->args, void *);
	if (!data)
		return (write(1, "(null)", 6));
	if (c == 's')
		str = (char *)data;
	else
	{
		if (!(str = ft_wstr_to_str((wchar_t *)data)))
			return (0);
	}
	len = write(1, str, ft_strlen(str));
	if (c == 'S')
		free(str);
	return (len);
}
