/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d_modul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:11:02 by prippa            #+#    #+#             */
/*   Updated: 2018/01/05 16:11:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_logic_with_zero(t_flag *flg, size_t len)
{
	size_t	size;

	size = 0;
	if (flg->flag[F_PLUS] && flg->str[0] != '-')
		size += write(1, "+", 1);
	else if (flg->flag[F_SPACE])
		size += write(1, " ", 1);
	if ((flg->flag[F_PLUS] || flg->flag[F_SPACE]) && flg->width)
		flg->width--;
	if (flg->width)
		size += ft_print_width(flg->width - len, '0');
	size += write(1, flg->str, len);
	return (size);
}

static size_t	ft_logic_with_minus(t_flag *flg, size_t len)
{
	size_t	size;

	size = 0;
	if (flg->flag[F_PLUS] && flg->str[0] != '-')
		size += write(1, "+", 1);
	else if (flg->flag[F_SPACE])
		size += write(1, " ", 1);
	if ((flg->flag[F_PLUS] || flg->flag[F_SPACE]) && flg->width)
		flg->width--;
	if (flg->precision)
		flg->precision -= len;
	if (flg->precision > 0)
		size += ft_print_width(flg->precision, '0');
	size += write(1, flg->str, len);
	if (flg->width)
		size += ft_print_width(flg->width - len, ' ');
	return (size);
}

size_t			ft_output_d_modul(t_flag *flg)
{
	size_t	len;
	size_t	size;

	len = ft_strlen(flg->str);
	size = 0;
	if (flg->flag[F_MINUS])
		size += ft_logic_with_minus(flg, len);
	else
	{
		if (flg->flag[F_ZERO])
			size += ft_logic_with_zero(flg, len);
		else
		{
			if (flg->flag[F_PLUS] && flg->str[0] != '-')
				size += write(1, "+", 1);
			else if (flg->flag[F_SPACE] && flg->width)
				flg->width++;
			if (flg->width)
				size += ft_print_width(flg->width - len, ' ');
			if (flg->precision)
			size += write(1, flg->str, len);
		}
	}
	return (size);
}
