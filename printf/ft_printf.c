/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:49:17 by prippa            #+#    #+#             */
/*   Updated: 2017/12/20 17:49:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_dispatcher(t_printf **fpf)
{
	char c;

	c = (*fpf)->format[(*fpf)->i];
	if (c == '%')
		(*fpf)->size += write(1, "%", 1);
	if (c == 'c' || c == 'C')
		(*fpf)->size += ft_print_char(&(*fpf), c);
	if (c == 's' || c == 'S')
		(*fpf)->size += ft_print_string(&(*fpf), c);
	if (c == 'd' || c == 'D' || c == 'i')
		(*fpf)->size += ft_print_signed_int(&(*fpf), c);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
		(*fpf)->size += ft_print_unsigned_int(&(*fpf), c);
}

static void	ft_lobi(t_printf **fpf)
{
	while ((*fpf)->format[(*fpf)->i])
	{
		if ((*fpf)->format[(*fpf)->i] == '%')
		{
			(*fpf)->i++;
			ft_dispatcher(&(*fpf));
		}
		else
		{
			ft_putchar((*fpf)->format[(*fpf)->i]);
			(*fpf)->size++;
		}
		(*fpf)->i++;
	}
}

int			ft_printf(const char *format, ...)
{
	t_printf *fpf;

	fpf = (t_printf*)malloc(sizeof(t_printf));
	fpf->format = ft_strdup(format);
	fpf->size = 0;
	fpf->i = 0;
	va_start(fpf->args, format);
	ft_lobi(&fpf);
	va_end(fpf->args);
	return (fpf->size);
}
