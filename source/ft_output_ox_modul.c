/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_ox_modul.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:09:10 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:09:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_percision_tricks(t_printf *fpf, int *len)
{
	if (fpf->f[F_DOT] && !fpf->precision && fpf->str[0] == '0'
		&& !fpf->f[F_SHARP])
		*len = 0;
	if (fpf->f[F_DOT] && !fpf->precision && fpf->str[0] == '0'
		&& fpf->f[F_SHARP] && (fpf->type == 'x' || fpf->type == 'X'))
		*len = 0;
	if (fpf->f[F_DOT] && fpf->precision
		&& fpf->f[F_SHARP] && (fpf->type == 'o' || fpf->type == 'O'))
		fpf->f[F_SHARP] = '\0';
}

static int		ft_write_sharp(t_printf *fpf)
{
	if (fpf->type == 'x')
	{
		fpf_cat_str(fpf, "0x");
		return (2);
	}
	else if (fpf->type == 'X')
	{
		fpf_cat_str(fpf, "0X");
		return (2);
	}
	else if (fpf->type == 'o' || fpf->type == 'O')
	{
		fpf_cat_char(fpf, '0');
		return (1);
	}
	return (0);
}

static void		ft_base_ox_modul_logic(t_printf *fpf, int len)
{
	if (fpf->width && fpf->f[F_SHARP] && fpf->type != 'o'
		&& fpf->type != 'O')
		fpf->width -= 2;
	else if (fpf->width && fpf->f[F_SHARP] && (fpf->type == 'o'
		|| fpf->type == 'O'))
		fpf->width--;
	if (fpf->width)
	{
		if (fpf->f[F_ZERO] && !fpf->precision)
		{
			if (fpf->f[F_SHARP])
				ft_write_sharp(fpf);
			fpf_charncat(fpf, fpf->width - len, '0');
		}
		else
			fpf_charncat(fpf, fpf->width - MAX(len, fpf->precision), ' ');
	}
	if (fpf->f[F_SHARP] && fpf->str[0] != '0'
		&& (!fpf->f[F_ZERO] || !fpf->width))
		ft_write_sharp(fpf);
	if (fpf->precision)
		fpf_charncat(fpf, fpf->precision - len, '0');
	fpf_cat_str(fpf, fpf->str);
}

void			ft_output_ox_modul(t_printf *fpf)
{
	int	len;
	int	size;

	len = ft_strlen(fpf->str);
	ft_percision_tricks(fpf, &len);
	size = 0;
	if (fpf->f[F_MINUS])
	{
		if (fpf->f[F_SHARP] && len)
			size += ft_write_sharp(fpf);
		if (fpf->precision)
			fpf_charncat(fpf, fpf->precision - len, '0');
		fpf_cat_str(fpf, fpf->str);
		if (fpf->width)
			fpf_charncat(fpf,
			fpf->width - MAX(len, fpf->precision) - size, ' ');
	}
	else
		ft_base_ox_modul_logic(fpf, len);
}
