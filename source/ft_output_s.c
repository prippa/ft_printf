/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:09:49 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:09:55 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_rules(t_printf *fpf, int len, int print)
{
	if (!ft_strlen(fpf->str))
	{
		len = 0;
		print = 0;
	}
	if (print && fpf->f[F_MINUS] && !(print = 0))
		fpf_cat_str_len(fpf, fpf->str, len);
	if (fpf->width)
	{
		if (fpf->f[F_ZERO] && !fpf->f[F_MINUS])
			fpf_cat_char_len(fpf, fpf->width - len, '0');
		else
			fpf_cat_char_len(fpf, fpf->width - len, ' ');
	}
	if (print)
		fpf_cat_str_len(fpf, fpf->str, len);
}

void		ft_output_s(t_printf *fpf)
{
	int	len;
	int	print;

	len = ft_strlen(fpf->str);
	if (fpf->precision < 0)
		fpf->precision = 0;
	else if (fpf->precision)
	{
		if (fpf->type == 'S' && !ft_isascii(fpf->str[fpf->precision - 1]))
		{
			while (fpf->precision % 3 > 0)
				fpf->precision--;
		}
		if (len > fpf->precision)
			len = fpf->precision;
	}
	else if (fpf->f[F_DOT])
		len = fpf->precision;
	print = 1;
	ft_rules(fpf, len, print);
}
