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
	else if (c == 'p')
		(*fpf)->size += ft_print_p(&(*fpf));
	else if (c == 'c' || c == 'C')
		(*fpf)->size += ft_print_c(&(*fpf), c);
	else if (c == 's' || c == 'S')
		(*fpf)->size += ft_print_s(&(*fpf), c);
	else if (c == 'd' || c == 'D' || c == 'i')
		(*fpf)->size += ft_print_di(&(*fpf), c, 0);
	else if (c == 'o' || c == 'u' || c == 'O' || c == 'U')
		(*fpf)->size += ft_print_ou(&(*fpf), c, 0);
	else if (c == 'x' || c == 'X')
		(*fpf)->size += ft_print_x(&(*fpf), c, 0);
	else if (c == ' ')
	{
		(*fpf)->i++;
		ft_dispatcher(&(*fpf));
	}
	else
		(*fpf)->i--;
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
	t_printf	*fpf;
	size_t		len;

	if (!(fpf = (t_printf*)malloc(sizeof(t_printf))))
		return (0);
	fpf->format = ft_strdup(format);
	fpf->size = 0;
	fpf->i = 0;
	va_start(fpf->args, format);
	ft_lobi(&fpf);
	va_end(fpf->args);
	len = fpf->size;
	free(fpf->format);
	free(fpf);
	return (len);
}
