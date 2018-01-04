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

static void	ft_dispatcher(t_flag *flg)
{

}

static t_flag	ft_initialization(t_printf *fpf)
{
	t_flag flg;

	ft_bzero(flg.flag, FLAG_SIZE);
	flg.width = 0;
	flg.precision = 0;
	flg.size_flag = 0;
	flg.type = '\0';
	flg.str = NULL;
	ft_get_flags(fpf, &flg);
	ft_get_type(fpf, &flg);
	return (flg);
}

static void		ft_lobi(t_printf *fpf)
{
	t_flag flg;

	while (PC)
	{
		if (PC == '%')
		{
			fpf->i++;
			flg = ft_initialization(fpf);
			if (flg.type)
			{
				ft_dispatcher(&flg);
				free(flg.str);
			}
			else
				fpf->i--;
		}
		else
		{
			ft_putchar(PC);
			fpf->size++;
		}
		fpf->i++;
	}
}

int				ft_printf(const char *format, ...)
{
	t_printf	fpf;

	fpf.format = ft_strdup(format);
	fpf.size = 0;
	fpf.i = 0;
	va_start(fpf.args, format);
	ft_lobi(&fpf);
	va_end(fpf.args);
	free(fpf.format);
	return (fpf.size);
}
