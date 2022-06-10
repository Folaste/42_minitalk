/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:33:36 by fleblanc          #+#    #+#             */
/*   Updated: 2022/06/08 18:55:08 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 42
# define HEX_BASE_MIN "0123456789abcdef"
# define HEX_BASE_MAJ "0123456789ABCDEF"
# define CASTS "cspdiuxX%"

typedef struct s_list	t_list;
struct	s_list
{
	void			*content;
	struct s_list	*next;
};

/*--- Libc functions ---*/
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *nptr);
long long		ft_atoll(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);

/*--- Other functions ---*/
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*--- Bonus functions ---*/
t_list			*ft_lstnew(void	*content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *list);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*--- Personnal functions ---*/
size_t			ft_intlen(long n);
void			ft_putnbr_base_fd(int nbr, char *base, int fd);
void			ft_sort_int_tab(int *tab, int size);
char			*ft_itob(unsigned int nb);
unsigned int	ft_btoi(char *tab);
int				ft_btoc(char *tab);
char			*ft_ctob(int c);

/*--- Get_Next_Line functions ---*/
char			*get_next_line(int fd);
char			*ft_read(int fd, char *buffer);
char			*ft_recover_line(char *buffer);
int				ft_find_eol(char *str);
char			*ft_new_buffer(char *old_buffer);
char			*ft_strjoin_gnl(const char *s1, const char *s2);
size_t			ft_strlen_gnl(const char *s);
char			*ft_strchr_gnl(const char *s, int c);
char			*ft_substr_gnl(const char *s, unsigned int start, size_t len);
size_t			ft_strlcpy_gnl(char *dst, const char *src, size_t size);

/*--- ft_printf functions ---*/
typedef struct s_printf	t_printf;
struct	s_printf
{
	va_list	args;
	int		dot;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		hash;
	int		tot_len;
	int		width;
	int		count_flags;
};

/*--- Fonctions principales  ---*/
int				ft_printf(const char *format, ...);
int				ft_read_format(t_printf *tab, const char *format, int i);

/*--- Fonctions de gestion de la structure ---*/
void			ft_init_tab(t_printf *tab);
void			ft_reset_tab(t_printf *tab);
void			ft_count_flags(t_printf *tab);

/*--- Fonctions de lecture des flags et des casts ---*/
int				ft_check_flags(t_printf *tab, const char *format, int i);
int				ft_check_cast(t_printf *tab, const char *format, int i);

/*--- Fonctions d'écriture ---*/
int				ft_printf_char(t_printf *tab, int i);

int				ft_printf_string(t_printf *tab, int i);
void			ft_printf_string_dot(t_printf *tab, char *str, int index);
void			ft_printf_string_width(t_printf *tab, char *str, int index);
void			ft_printf_string_minus(t_printf *tab, char *str, int index);

int				ft_printf_pointer(t_printf *tab, int i);
void			ft_putptr_fd(unsigned long p, t_printf *tab,
					int fd, char *base);
int				ft_hexalen(unsigned long p);
void			ft_printf_pointer_minus(t_printf *tab,
					unsigned long p, int index);
void			ft_printf_pointer_width(t_printf *tab,
					unsigned long p, int index);

int				ft_printf_hexa(t_printf *tab, int i, char x_case);
void			ft_printf_hexa_minus(t_printf *tab, unsigned int x,
					char *base, int index);
void			ft_printf_hexa_zero(t_printf *tab, unsigned int x,
					char *base, int index);
void			ft_printf_hexa_hash(t_printf *tab, unsigned int x, char *base);
void			ft_printf_hexa_width(t_printf *tab, unsigned int x,
					char *base, int index);

int				ft_printf_unsigned(t_printf *tab, int i);
void			ft_putnbr_u_fd(unsigned int u, t_printf *tab, int fd);
void			ft_printf_unsigned_minus(t_printf *tab,
					unsigned int u, int index);
void			ft_printf_unsigned_zero(t_printf *tab,
					unsigned int u, int index);
void			ft_printf_unsigned_width(t_printf *tab,
					unsigned int u, int index);

int				ft_printf_number(t_printf *tab, int i);
void			ft_choice_write(t_printf *tab, int nbr, int size, int index);
void			ft_printf_number_minus(t_printf *tab, int nbr,
					int index, int size);
void			ft_printf_number_zero(t_printf *tab, int nbr,
					int index, int size);
void			ft_printf_number_width(t_printf *tab, int nbr,
					int index, int size);
void			ft_printf_number_dot(t_printf *tab, int nbr,
					int index, int size);

/*--- Fonctions de retour de valeur ---*/
void			ft_return_value_s(t_printf *tab);
void			ft_return_value_p(t_printf *tab);
void			ft_return_value_x(t_printf *tab);
void			ft_return_value_u(t_printf *tab);
void			ft_return_value_nbr(t_printf *tab);

#endif
