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

static int	ft_dispatcher(char c, va_list *args)
{
	if (c != '%' && c != 'c' && c != 's' && c != 'd' && c != 'i')
		return (1);
	if (c == '%')
		ft_putchar('%');
	if (c == 'c')
		ft_putchar(va_arg(*args, int));
	if (c == 's')
		ft_putstr(va_arg(*args, char *));
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args, int));
	return (2);
}

static int	ft_lobi(const char *format, va_list *args)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			i += ft_dispatcher(format[i + 1], &(*args));
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_lobi(format, &args);
	va_end(args);
	return (len);
}
