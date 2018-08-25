/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p_modul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:09:36 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:09:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_base_p_modul_logic(t_printf *fpf, int len)
{
	int	flag;

	fpf->width -= 2;
	flag = 1;
	if (fpf->width)
	{
		if (fpf->f[F_ZERO] && !fpf->precision)
		{
			flag = 0;
			fpf_cat_str(fpf, "0x");
			fpf_charncat(fpf, fpf->width - len, '0');
		}
		else
			fpf_charncat(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	if (flag)
		fpf_cat_str(fpf, "0x");
	if (fpf->precision)
		fpf_charncat(fpf, fpf->precision - len, '0');
	fpf_cat_str(fpf, fpf->str);
}

void			ft_output_p_modul(t_printf *fpf)
{
	int	len;

	len = ft_strlen(fpf->str);
	if (fpf->f[F_DOT] && !fpf->precision && fpf->str[0] == '0')
		len = 0;
	if (fpf->f[F_MINUS])
	{
		fpf_cat_str(fpf, "0x");
		if (fpf->precision)
			fpf_charncat(fpf, fpf->precision - len, '0');
		fpf_cat_str(fpf, fpf->str);
		if (fpf->width)
			fpf_charncat(fpf, fpf->width - MAX(len, fpf->precision) - 2, ' ');
	}
	else
		ft_base_p_modul_logic(fpf, len);
}