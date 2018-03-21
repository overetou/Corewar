/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenguyen <kenguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:14:40 by kenguyen          #+#    #+#             */
/*   Updated: 2018/03/21 14:38:00 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <wchar.h>

# define PF_BUFF_SIZE	64
# define GNL_BUFF_SIZE	32

/*
**				libft
*/

char			*ft_itoa(int n);
char			*ft_itoa_base(int n, int base);
char			*ft_ltoa(long n);
char			*ft_ltoa_base(long n, int base);
char			*ft_uitoa(unsigned int n);
char			*ft_ultoa(unsigned long n);
char			*ft_uitoa_base(unsigned int n, int base);
char			*ft_ultoa_base(unsigned long n, int base);
int				get_next_line(int const fd, char **line);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
char			*ft_strchr(const char *s, int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strcspn(const char *str1, const char *str2);
char			*ft_strdup(const char *str);
char			*ft_strndup(const char *s1, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isblank(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putendl(const char *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putstr(const char *s);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
int				ft_strequ(const char *s1, const char *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			**ft_strsplit(const char *s, char c);
void			ft_strsplitdel(char **split);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strrev(char *str);
void			ft_strlower(char *s);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_uppercase(char *str);

/*
**				lst
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(const void *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstdelone(t_list **lst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **lst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
**				ft_printf
*/

typedef struct	s_pf_flag
{
	int			sp;
	int			plus;
	int			neg;
	int			minus;
	int			hash;
	int			zero;
	int			prec;
	int			width;
}				t_pf_flag;

typedef enum	e_pf_mod
{
	pf_nomod = 0,
	pf_h,
	pf_hh,
	pf_l,
	pf_ll,
	pf_j,
	pf_z,
}				t_pf_mod;

typedef	struct	s_pf_env
{
	va_list		ap;
	char		buff[PF_BUFF_SIZE];
	char		*out;
	t_pf_flag	flag;
	t_pf_mod	mod;
	int			i;
	int			b;
	int			ret;
}				t_pf_env;

int				ft_printf(const char *restrict fmt, ...);

/*
**				fill_buff
*/

void			fill_buff(const char c, t_pf_env *e);
void			fill_sbuff(const char *str, t_pf_env *e);
void			print_buff(t_pf_env *e);

/*
**				parse_arg
*/

void			parse_flag(const char *restrict fmt, t_pf_env *e);
void			parse_prec(const char *restrict fmt, t_pf_env *e);
void			parse_mod(const char *restrict fmt, t_pf_env *e);
void			parse_conv(const char *restrict fmt, t_pf_env *e);

/*
**				get_conv
*/

void			conv_int(t_pf_env *e);
void			conv_unsint(t_pf_env *e, char type);
void			conv_char(t_pf_env *e, char type);
void			conv_wchar(t_pf_env *e, char type);
void			conv_base(t_pf_env *e, char type);
void			conv_ptraddr(t_pf_env *e, char type);
void			conv_percent(t_pf_env *e);

/*
**				print_digit
*/

void			print_digit(t_pf_env *e);
void			print_digit_width(t_pf_env *e);
void			print_digit_sign(t_pf_env *e);
void			check_digit_sign(t_pf_env *e);
void			check_digit_prec(t_pf_env *e);

/*
**				print_base
*/

void			print_base(t_pf_env *e, char type, long val);
void			print_base_width(t_pf_env *e, char type);
void			print_base_pre(t_pf_env *e, char type, long val);
void			check_base_prec(t_pf_env *e, char type);

/*
**				print_char
*/

void			print_char(t_pf_env *e, char c);
void			print_null_char(t_pf_env *e);
void			print_char_width(t_pf_env *e);
void			print_str(t_pf_env *e);
void			print_null_str(t_pf_env *e);
void			print_str_width(t_pf_env *e);

/*
**				print_wchar
*/

void			print_wchar(t_pf_env *e, wchar_t wc);
void			print_wchar_minus(t_pf_env *e, wchar_t wc);
void			put_wchar(t_pf_env *e, wchar_t c);
void			print_wstr(t_pf_env *e, wchar_t *wc);
void			print_wstr_minus(t_pf_env *e, wchar_t *wc, int len);
int				get_wstr_len(wchar_t *wc);
void			put_wstr(t_pf_env *e, wchar_t c);

/*
**				print_ptraddr
*/

void			print_ptraddr(t_pf_env *e, char type);
void			print_ptraddr_width(t_pf_env *e);
void			ptraddr_prec(t_pf_env *e);

/*
**				print_invalid
*/

void			print_invalid_spec(t_pf_env *e, char c);
void			print_invalid_width(t_pf_env *e);

#endif
