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

static int	ft_identify_flag(t_printf **fpf)
{
	int		size_flag;
	char	c_1;
	char	c_2;

	size_flag = 0;
	c_1 = (*fpf)->format[(*fpf)->i];
	c_2 = (*fpf)->format[(*fpf)->i + 1];
	if (!c_1 || !c_2)
		return (0);
	if (c_1 == 'l' && c_2 == 'l' && (size_flag = SF_LL))
		(*fpf)->i += 2;
	else if (c_1 == 'l' && (size_flag = SF_L))
		(*fpf)->i += 1;
	else if (c_1 == 'h' && c_2 == 'h' && (size_flag = SF_HH))
		(*fpf)->i += 2;
	else if (c_1 == 'h' && (size_flag = SF_H))
		(*fpf)->i += 1;
	else if (c_1 == 'j' && (size_flag = SF_J))
		(*fpf)->i += 1;
	else if (c_1 == 'z' && (size_flag = SF_Z))
		(*fpf)->i += 1;
	return (size_flag);
}

static void	ft_dispatcher(t_printf **fpf, int size_flag)
{
	char c;

	c = (*fpf)->format[(*fpf)->i];
	if (c == '%')
		(*fpf)->size += write(1, "%", 1);
	else if (c == 'p')
		(*fpf)->size += ft_print_p(&(*fpf));
	else if (c == 'c' || c == 'C')
		(*fpf)->size += ft_print_c(&(*fpf), c, size_flag);
	else if (c == 's' || c == 'S')
		(*fpf)->size += ft_print_s(&(*fpf), c, size_flag);
	else if (c == 'd' || c == 'D' || c == 'i')
		(*fpf)->size += ft_print_di(&(*fpf), c, size_flag);
	else if (c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		c == 'x' || c == 'X')
		(*fpf)->size += ft_print_oux(&(*fpf), c, size_flag);
	else if (c == ' ')
	{
		(*fpf)->i++;
		ft_dispatcher(&(*fpf), size_flag);
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
			ft_dispatcher(&(*fpf), ft_identify_flag(&(*fpf)));
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
