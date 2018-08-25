/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:56:11 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 12:56:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

# define FPF_BUF_SIZE 512

typedef enum	s_size_flags
{
	SF_H = 1,
	SF_HH,
	SF_L,
	SF_LL,
	SF_J,
	SF_Z
}				t_size_flags;

typedef enum	s_flags
{
	F_MINUS,
	F_PLUS,
	F_SPACE,
	F_SHARP,
	F_ZERO,
	F_DOT,
	F_COLOR,
	FLAG_SIZE
}				t_flags;

typedef struct	s_printf
{
	va_list		args;
	const char	*format;
	char		*str;
	int			fd;
	char		buf[FPF_BUF_SIZE + 1];
	size_t		buflen;
	char		f[FLAG_SIZE];
	int			color;
	int			width;
	int			precision;
	int			size_flag;
	char		type;
	int			len;
}				t_printf;

int						ft_printf(const char *format, ...);
void					fpf_cat_char(t_printf *fpf, char c);
void					fpf_cat_str(t_printf *fpf, const char *src);
void					fpf_parser(t_printf *fpf);
signed long long int	ft_conv_sig_int(t_printf *fpf);
unsigned long long int	ft_conv_unsig_int(t_printf *fpf);
void					fpf_malloc_error_exit(void);
void					fpf_get_type(t_printf *fpf);
char					*ft_wstr_to_str(wchar_t *ws);
void					fpf_charncat(t_printf *fpf, int n, char c);

void					ft_output_c_modul(t_printf *fpf);
void					ft_output_d_modul(t_printf *fpf);
void					ft_output_ox_modul(t_printf *fpf);
void					ft_output_p_modul(t_printf *fpf);
void					ft_output_s_modul(t_printf *fpf);
void					ft_output_u_modul(t_printf *fpf);

#endif
