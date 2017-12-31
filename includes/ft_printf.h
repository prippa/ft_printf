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
//# include <inttypes.h>
# include <wchar.h>

typedef	struct		s_printf
{
	char			*format;
	int				i;
	size_t			size;
	va_list			args;
}					t_printf;

int		ft_printf(const char *format, ...);
char	*ft_itoa_lli(long long int num);
char	*ft_itoa_base(unsigned long long int num, int base, int letter, int len);
char	*ft_wstr_to_str(wchar_t *ws);

size_t	ft_print_char(t_printf **fpf, char c);
size_t	ft_print_string(t_printf **fpf, char c);
size_t	ft_print_signed_int(t_printf **fpf, char c);
size_t	ft_print_unsigned_int(t_printf **fpf, char c);

#endif
