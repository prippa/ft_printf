/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 13:43:08 by prippa            #+#    #+#             */
/*   Updated: 2018/01/04 13:43:10 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_type_1(t_printf *fpf, t_flag *flg)
{
	if (PC == 'o' && (flg->type = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
	else if (PC == 'O' && (flg->type = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
	else if (PC == 'u' && (flg->type = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
	else if (PC == 'U' && (flg->type = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
	else if (PC == 'x' && (flg->type = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
	else if (PC == 'X' && (flg->type = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
}

void		ft_get_type(t_printf *fpf, t_flag *flg)
{
	if (PC == '%' && (flg->type = PC))
		flg->str = ft_strdup("%");
	else if (PC == 'p' && (flg->type = PC))
		flg->str = ft_get_p(fpf);
	else if (PC == 'c' && (flg->type = PC))
		flg->str = ft_get_c(fpf, PC, flg->size_flag);
	else if (PC == 'C' && (flg->type = PC))
		flg->str = ft_get_c(fpf, PC, flg->size_flag);
	else if (PC == 's' && (flg->type = PC))
		flg->str = ft_get_s(fpf, PC, flg->size_flag);
	else if (PC == 'S' && (flg->type = PC))
		flg->str = ft_get_s(fpf, PC, flg->size_flag);
	else if (PC == 'd' && (flg->type = PC))
		flg->str = ft_get_di(fpf, PC, flg->size_flag);
	else if (PC == 'D' && (flg->type = PC))
		flg->str = ft_get_di(fpf, PC, flg->size_flag);
	else if (PC == 'i' && (flg->type = PC))
		flg->str = ft_get_di(fpf, PC, flg->size_flag);
	else 
		ft_get_type_1(fpf, flg);
}
