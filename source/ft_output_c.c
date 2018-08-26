/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:08:34 by prippa            #+#    #+#             */
/*   Updated: 2018/01/15 13:08:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_join(t_printf *fpf)
{
	if (fpf->str[0])
		fpf_cat_str(fpf, fpf->str);
	else
		fpf_cat_char(fpf, 0);
}

static void	ft_wchar(t_printf *fpf)
{
	int	len;
	int	print;

	len = ft_strlen(fpf->str);
	print = 1;
	if (fpf->f[F_MINUS] && !(print = 0))
		ft_join(fpf);
	if (fpf->width)
	{
		if (fpf->f[F_ZERO] && !fpf->f[F_MINUS])
			fpf_cat_char_len(fpf, fpf->width - len, '0');
		else
			fpf_cat_char_len(fpf, fpf->width - len, ' ');
	}
	if (print)
		ft_join(fpf);
}

static void	ft_char(t_printf *fpf)
{
	int	print;

	print = 1;
	if (fpf->f[F_MINUS] && !(print = 0))
		ft_join(fpf);
	if (fpf->width)
	{
		if (fpf->f[F_ZERO] && !fpf->f[F_MINUS])
			fpf_cat_char_len(fpf, fpf->width - 1, '0');
		else
			fpf_cat_char_len(fpf, fpf->width - 1, ' ');
	}
	if (print)
		ft_join(fpf);
}

void		ft_output_c(t_printf *fpf)
{
	if (fpf->type == 'C' || fpf->size_flag == SF_L)
		ft_wchar(fpf);
	else
		ft_char(fpf);
}
