/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:32:25 by oroy              #+#    #+#             */
/*   Updated: 2024/12/08 23:50:25 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	size_t			chunk;
	int				content;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_buf
{
	char	buf[BUFFER_SIZE + 1];
	size_t	i;
}	t_buf;

int		ft_abs(int n);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, size_t start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
// Linked List -------------------------------------------------------------- //
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content, t_list *prev);
size_t	ft_lstsize(t_list *lst);
// Ft_printf ---------------------------------------------------------------- //
int		ft_printf(const char *s, ...);
int		print_hex(unsigned long u, char c, int fd);
int		print_int(int i, int fd);
int		print_p(unsigned long p, int fd);
int		print_s(char *s, int fd);
int		print_uint(unsigned int u, int fd);
// GNL ---------------------------------------------------------------------- //
char	*ft_strjoin_gnl(char *newline, char *line, char *buf, size_t buf_len);
size_t	getbuflength(char *buf, unsigned char *n);
char	*get_next_line(int fd);

#endif