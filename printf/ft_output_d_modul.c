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

static size_t	ft_print_d_modul(t_flag *flg, size_t len, size_t len2)
{
	size_t	size;

	size = 0;
	if (len < len2)
		size += write(1, flg->str + 1, len);
	else
		size += write(1, flg->str, len);
	return (size);
}

static size_t	ft_print_if_psm(t_flag *flg, size_t *len, int *flag)
{
	size_t	size;

	size = 0;
	if (*flag)
	{
		if (flg->flag[F_PLUS] && flg->str[0] != '-' && !(*flag = 0))
			size += write(1, "+", 1);
		else if (flg->str[0] == '-' && !(*flag = 0))
		{
			size += write(1, "-", 1);
			*len -= 1;
		}
		else if (flg->flag[F_SPACE] && !(*flag = 0))
			size += write(1, " ", 1);
	}
	return (size);
}

static void		ft_base_d_modul_logic(t_flag *flg, size_t len,
	size_t *size, int flag)
{
	size_t tmp;

	if (flg->width)
	{
		if (flg->flag[F_ZERO] && !flg->precision)
		{
			tmp = len;
			*size += ft_print_if_psm(flg, &len, &flag);
			*size += ft_print_width(flg->width - tmp, '0');
		}
		else
			*size += ft_print_width(flg->width - MAX(len, flg->precision), ' ');
	}
	if (flg->precision)
	{
		*size += ft_print_if_psm(flg, &len, &flag);
		*size += ft_print_width(flg->precision - len, '0');
		*size += ft_print_d_modul(flg, len, ft_strlen(flg->str));
	}
	else
	{
		*size += ft_print_if_psm(flg, &len, &flag);
		*size += ft_print_d_modul(flg, len, ft_strlen(flg->str));
	}
}

static size_t	ft_logic_with_minus(t_flag *flg, size_t len)
{
	size_t	size;

	size = 0;
	if (flg->flag[F_PLUS] && flg->str[0] != '-')
		size += write(1, "+", 1);
	else if (flg->str[0] == '-')
	{
		size += write(1, "-", 1);
		len--;
	}
	else if (flg->flag[F_SPACE])
		size += write(1, " ", 1);
	if (flg->precision)
		size += ft_print_width(flg->precision - len, '0');
	size += ft_print_d_modul(flg, len, ft_strlen(flg->str));
	if (flg->width)
		size += ft_print_width(flg->width - size, ' ');
	return (size);
}

size_t			ft_output_d_modul(t_flag *flg)
{
	size_t	len;
	size_t	size;

	len = ft_strlen(flg->str);
	size = 0;
	if (flg->str[0] == '0' && flg->flag[F_DOT])
		len = 0;
	if (flg->flag[F_MINUS])
		size += ft_logic_with_minus(flg, len);
	else
	{
		if (flg->width && !flg->flag[F_MINUS]
		&& ((flg->flag[F_PLUS] && flg->str[0] != '-')
		|| flg->flag[F_SPACE] || (flg->precision == len && flg->str[0] == '-')))
		flg->width--;
		ft_base_d_modul_logic(flg, len, &size, 1);
	}
	return (size);
}
