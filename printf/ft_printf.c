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
	char *tmp;
	char c = (*fpf)->format[(*fpf)->i];

	if (c != '%' && c != 'c' && c != 's' && c != 'd' && c != 'i')
		return ;
	if (c == '%')
	{
		(*fpf)->size++;
		ft_putchar('%');
	}
	if (c == 'c')
	{
		(*fpf)->size++;
		ft_putchar(va_arg((*fpf)->args, int));
	}
	if (c == 's')
	{
		tmp = va_arg((*fpf)->args, char *);
		(*fpf)->size += ft_strlen(tmp);
		ft_putstr(tmp);
	}
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg((*fpf)->args, int));
	(*fpf)->i++;
}

static void	ft_lobi(t_printf **fpf)
{
	while ((*fpf)->format[(*fpf)->i])
	{
		if ((*fpf)->format[(*fpf)->i] == '%')
		{
			(*fpf)->size++;
			(*fpf)->i++;
			ft_dispatcher(&(*fpf));
		}
		else
		{
			ft_putchar((*fpf)->format[(*fpf)->i]);
			(*fpf)->size++;
			(*fpf)->i++;
		}
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
