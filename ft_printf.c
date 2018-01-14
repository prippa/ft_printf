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

static void		ft_dispatcher(t_printf *fpf)
{
	if (FC == 'c' || FC == 'C')
		ft_output_c_modul(fpf);
	else if (FC == 's' || FC == 'S')
		ft_output_s_modul(fpf);
	else if (FC == 'd' || FC == 'i' || FC == 'D')
		ft_output_d_modul(fpf);
	else if (FC == 'u' || FC == 'U')
		ft_output_u_modul(fpf);
	else if (FC == 'o' || FC == 'O' || FC == 'x' || FC == 'X')
		ft_output_ox_modul(fpf);
	else if (FC == 'p')
		ft_output_p_modul(fpf);
	else
		ft_strjoin(fpf, fpf->str, ft_strlen(fpf->str));
}

static void		ft_initialization(t_printf *fpf)
{
	ft_bzero(fpf->flag, FLAG_SIZE);
	fpf->width = 0;
	fpf->precision = 0;
	fpf->size_flag = 0;
	fpf->type = '\0';
	fpf->str = NULL;
	ft_get_flags(fpf);
	ft_get_type(fpf);
}

static void		ft_base_output(t_printf *fpf)
{
	int		len;
	int		i;
	char	*str;

	i = fpf->i;
	len = 0;
	while (fpf->format[i] && fpf->format[i] != '%')
	{
		len++;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return ;
	str[len] = '\0';
	i = 0;
	while (i < len)
	{
		str[i] = PC;
		i++;
		fpf->i++;
	}
	ft_strjoin(fpf, str, len);
	free(str);
	fpf->i--;
}

static void		ft_lobi(t_printf *fpf)
{
	while (PC)
	{
		if (PC == '%')
		{
			fpf->i++;
			if (!PC)
				continue;
			ft_initialization(fpf);
			if (fpf->type && fpf->str)
			{
				ft_dispatcher(fpf);
				free(fpf->str);
			}
			else
				fpf->i--;
		}
		else
			ft_base_output(fpf);
		fpf->i++;
	}
}

int				ft_printf(const char *format, ...)
{
	t_printf	fpf;

	fpf.format = ft_strdup(format);
	fpf.out_str = NULL;
	fpf.i = 0;
	fpf.size = 0;
	va_start(fpf.args, format);
	ft_lobi(&fpf);
	va_end(fpf.args);
	free(fpf.format);
	if (fpf.out_str)
	{
		write(1, fpf.out_str, fpf.size);
		free(fpf.out_str);
	}
	return (fpf.size);
}
