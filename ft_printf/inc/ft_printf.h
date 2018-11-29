/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:43:10 by hehuang           #+#    #+#             */
/*   Updated: 2017/07/03 15:52:45 by raymondhuang     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <wchar.h>
# include <inttypes.h>
# include "../../libft/libft.h"

typedef struct			s_tag
{
	char				pad;
	int					l_just;
	int					init_width;
	int					min_width;
	char				length;
	int					precision;
	char				type;
	int					header;
	int					hash;
	int					cap;
	int					sign;
	int					space;
	int					neg;
	short				arg_short;
	long				arg_long;
	long long			arg_ll;
	unsigned short		arg_ushort;
	unsigned long		arg_ulong;
	unsigned long long	arg_ull;
	unsigned char		arg_uchar;
	signed char			arg_char;
	wchar_t				arg_wchar;
	wint_t				arg_wint;
	size_t				arg_sizet;
	intmax_t			arg_intmaxt;
	uintmax_t			arg_uintmaxt;
	void				*arg;
	char				*base;
	char				*width;
	char				*prec;
	int					dot;
}						t_tag;

int						ft_printf(const char *format, ...);
int						process_tag(const char *fmt);
int						handle_tag(t_tag *tag);
int						handle_hex(t_tag *tag);
int						is_percent(const char *fmt, int i);
int						is_type(char type);
int						is_flag(const char flag);
int						is_length(const char length);
int						handle_oct(t_tag *tag);
int						handle_decimal(t_tag *tag);
int						handle_char(t_tag *tag);
int						handle_string(t_tag *tag);
int						handle_percent(t_tag *tag);
t_tag					*handle_invalid(t_tag *tag, const char *fmt);
t_tag					*init_tag(const char *fmt);
char					get_type(const char *fmt);
char					get_length(const char *fmt);
int						get_width(const char *fmt);
char					*create_width(t_tag *tag, int init_len);
char					*join_width(char *base, char *width, int l_just);
int						get_precision(const char *fmt);
t_tag					*precision_itoa(t_tag *tag, int base, int cap);
t_tag					*precision_utoa(t_tag *tag, int base, int cap);
int						handle_unsigned(t_tag *tag);
t_tag					*cast_int_with_length(t_tag *tag);
void					*to_int(void *arg);
size_t					ft_wcslen(wchar_t *s);
size_t					ft_wstrlen(wchar_t *ws);
int						ft_putws(wchar_t *s);
int						ft_putwi(wchar_t wc);
int						handle_wchar(t_tag *tag);
int						handle_ws(t_tag *tag);
wchar_t					*ft_wstrnew(size_t size);
wchar_t					*ft_wstrcpy(wchar_t *dst, const wchar_t *src);
wchar_t					*ft_wstrncpy(wchar_t *dst, const wchar_t *src,
	size_t len);
size_t					ft_wcharlen(wchar_t wc);
void					cleanup(t_tag *tag, char *ret, char *base);
char					*oct_and_hex_helper(char *base, char *width,
	int l_just, char *head);
va_list					g_lst;

#endif
