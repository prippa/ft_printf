/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:41:47 by prippa            #+#    #+#             */
/*   Updated: 2018/01/04 11:41:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags(t_printf *fpf, t_flag *flg)
{
	while (PC)
	{
		if (PC == '-')
			flg->flag[F_MINUS] = '-';
		else if (PC == '+')
			flg->flag[F_PLUS] = '+';
		else if (PC == ' ')
			flg->flag[F_SPACE] = ' ';
		else if (PC == '#')
			flg->flag[F_SHARP] = '#';
		else if (PC == '0')
			flg->flag[F_ZERO] = '0';
		else if (PC == '*')
		{
			flg->flag[F_STAR] = '*';
			if ((flg->width = va_arg(fpf->args, int)) < 0)
			{
				flg->flag[F_MINUS] = '-';
				flg->width = flg->width * -1;
			}
		}
		else
			return ;
		fpf->i++;
	}
}

static int	ft_get_number(t_printf *fpf)
{
	char	width[NUMBER_SIZE];
	int		i;

	ft_bzero(width, NUMBER_SIZE);
	i = 0;
	while (ft_isdigit(PC) && i < NUMBER_SIZE)
	{
		width[i] = PC;
		fpf->i++;
		i++;
	}
	if (i)
		return(ft_atoi(width));
	return (0);
}

static void	ft_precision(t_printf *fpf, t_flag *flg)
{
	if (flg->flag[F_DOT])
	{
		if (PC == '*')
		{
			flg->flag[F_STAR] = '*';
			while (PC == '*')
			{
				flg->precision = va_arg(fpf->args, int);
				// if ((flg->precision = va_arg(fpf->args, int)) < 0)
				// 	flg->precision = 0;
				fpf->i++;
			}
		}
		else
			flg->precision = ft_get_number(fpf);
	}
}

static void	ft_size_flag(t_printf *fpf, t_flag *flg)
{
	char	c_1;
	char	c_2;

	c_1 = fpf->format[fpf->i];
	c_2 = fpf->format[fpf->i + 1];
	if (!c_1 || !c_2)
		return ;
	if (c_1 == 'l' && c_2 == 'l' && (flg->size_flag = SF_LL))
		fpf->i += 2;
	else if (c_1 == 'l' && (flg->size_flag = SF_L))
		fpf->i += 1;
	else if (c_1 == 'h' && c_2 == 'h' && (flg->size_flag = SF_HH))
		fpf->i += 2;
	else if (c_1 == 'h' && (flg->size_flag = SF_H))
		fpf->i += 1;
	else if (c_1 == 'j' && (flg->size_flag = SF_J))
		fpf->i += 1;
	else if (c_1 == 'z' && (flg->size_flag = SF_Z))
		fpf->i += 1;
}

void		ft_get_flags(t_printf *fpf, t_flag *flg)
{
	ft_flags(fpf, flg);
	if (!flg->width)
		flg->width = ft_get_number(fpf);
	while (PC)
	{
		if (PC == '.')
			flg->flag[F_DOT] = '.';
		else
			break ;
		fpf->i++;
	}
	ft_precision(fpf, flg);
	ft_size_flag(fpf, flg);
}
