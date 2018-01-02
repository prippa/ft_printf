/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:52:26 by prippa            #+#    #+#             */
/*   Updated: 2017/12/20 17:52:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>

# define SF_H			1
# define SF_HH			2
# define SF_L			3
# define SF_LL			4
# define SF_J			5
# define SF_Z			6

typedef	struct			s_flg
{
	char				flag;
	int					widths;
	int					size_flag;
	char				type;
}						t_flg;

typedef	struct			s_printf
{
	char				*format;
	int					i;
	size_t				size;
	va_list				args;
}						t_printf;

int						ft_printf(const char *format, ...);
char					*ft_itoa_lli(long long int num);
char					*ft_itoa_base(unsigned long long int num,
						int base, int letter, int len);
char					*ft_wstr_to_str(wchar_t *ws);
long long int			ft_conv_sig_int(t_printf **fpf, int size_flag);
unsigned long long int	ft_conv_unsig_int(t_printf **fpf, int size_flag);

size_t					ft_print_c(t_printf **fpf, char c);
size_t					ft_print_s(t_printf **fpf, char c);
size_t					ft_print_p(t_printf **fpf);
size_t					ft_print_ou(t_printf **fpf, char c, int size_flag);
size_t					ft_print_x(t_printf **fpf, char c, int size_flag);
size_t					ft_print_di(t_printf **fpf, char c, int size_flag);

#endif
