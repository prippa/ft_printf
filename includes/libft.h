/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 13:12:21 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 13:12:25 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define ABS(x) (((x) < 0) ? -(x) : (x))
# define MAX(a, b) (a > b ? a : b)

char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa_max(long long int n);
char			*ft_itoa_base(unsigned long long int num, int base, int letter);
int				ft_isdigit(int c);
int				ft_isascii(int c);
void			ft_strdel(char **as);
short			ft_nbrlen(long long int nb);

#endif
