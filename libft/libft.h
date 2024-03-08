/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:47:01 by nmagdano          #+#    #+#             */
/*   Updated: 2024/03/08 18:01:01 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//gnl
typedef struct new_line_bit
{
	char				*line_bit;
	size_t				len;
	struct new_line_bit	*next;
}		t_bits;

char		*get_next_line(int fd);

size_t		ft_lsbsize(t_bits *lst);
char		*ft_strcat(char *s1, const char *s2);
t_bits		*lst_magic(void *content, t_bits *lst);
char		*ft_strldup(const char *s1, ssize_t *fe);
char		*fill_line(t_bits *bits);

//printf
int			ft_numlen(long long num);
size_t		ft_putstrlen(char *s);
int			ft_print_d(int str);
int			ft_print_p(unsigned long long num);
int			ft_printf(const char *format, ...);
void		ft_putnbr_int(int n);
int			ft_putcharlen(char c);
int			ft_printf(const char *format, ...);
int			ft_print_u(unsigned int num);
int			thex(unsigned int num, int key);

//libft
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src,
				size_t dstsize);
static char	**split_ret(char **str, size_t i);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strnstr(const char *strB, const char *strA, size_t len);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		*ft_strrchr(const char *str, int ch);
char		*ft_strchr(const char *s, int c);
int			ft_isprint(int c);
int			ft_tolower(int ch);
int			ft_toupper(int ch);
size_t		ft_strlcat(char *dst, const char *src,
				size_t dstsize);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif