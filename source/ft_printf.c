/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:56:51 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 12:56:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fpf_dispatcher(t_printf *fpf)
{
	if (fpf->type == 'c' || fpf->type == 'C')
		ft_output_c_modul(fpf);
	else if (fpf->type == 's' || fpf->type == 'S')
		ft_output_s_modul(fpf);
	else if (fpf->type == 'd' || fpf->type == 'i' || fpf->type == 'D')
		ft_output_d_modul(fpf);
	else if (fpf->type == 'u' || fpf->type == 'U')
		ft_output_u_modul(fpf);
	else if (fpf->type == 'o' || fpf->type == 'O'
		|| fpf->type == 'x' || fpf->type == 'X')
		ft_output_ox_modul(fpf);
	if (fpf->type == 'p')
		ft_output_p_modul(fpf);
}

static void	fpf_handle_type(t_printf *fpf)
{
	fpf->size_flag = 0;
	fpf->width = 0;
	fpf->precision = 0;
	fpf->color = 0;
	fpf->str = NULL;
	ft_bzero(fpf->f, FLAG_SIZE);
	fpf_parser(fpf);
	fpf_dispatcher(fpf);
	// fpf_cat_str(fpf, fpf->str);
	free(fpf->str);
}

static void	fpf_lobi(t_printf *fpf)
{
	while (*fpf->format)
	{
		if (*fpf->format == '%')
			fpf_handle_type(fpf);
		else
			fpf_cat_char(fpf, *fpf->format++);
	}
	if (fpf->buflen)
		fpf->len += write(fpf->fd, fpf->buf, fpf->buflen);
}

int			ft_printf(const char *format, ...)
{
	t_printf fpf;

	fpf.format = format;
	fpf.fd = 1;
	fpf.buflen = 0;
	fpf.len = 0;
	va_start(fpf.args, format);
	fpf_lobi(&fpf);
	va_end(fpf.args);
	return (fpf.len);
}