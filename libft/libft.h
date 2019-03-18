/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:58:46 by mtordjma          #+#    #+#             */
/*   Updated: 2019/03/12 17:15:49 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dnode
{
	int				data;
	int				*xtab;
	int				*xctab;
	int				*ytab;
	struct s_dnode	*p_next;
	struct s_dnode	*p_prev;
}					t_dnode;

typedef struct		s_dlist
{
	size_t			length;
	t_dnode			*p_head;
	t_dnode			*p_tail;
}					t_dlist;

void				ft_putchar(char c);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_dnode				*ft_dlistaddh(t_dlist **p_list);
t_dnode				*ft_dlistaddt(t_dlist **p_list);
t_dlist				*ft_dlistnew(void);
char				*ft_strmap(char const *s, char (*f)(char));
int					get_next_line(const int fd, char **line);
char				*ft_strcapitalize(char *str);
void				ft_bzero(void *s, size_t n);
void				ft_swap(int *a, int *b);
void				ft_foreach(int *tab, int lenght, void (*f)(int));
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_lstadd(t_list **alst, t_list *lol);
char				*ft_strndup(const char *s1, size_t n);
void				ft_strdel(char **as);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putnbr(int nb);
void				ft_sort_integer_table(int *tab, int size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
void				ft_striter(char *s, void (*f)(char *));
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putnbr_fd(int nb, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strnew(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_strclr(char *s);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
char				*ft_strtrim(char const *s);
void				ft_putendl_fd(char const *s, int fd);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_strequ(char const *s1, char const *s2);
void				ft_putstr(char const *str);
char				*ft_strrchr(const char *s, int c);
void				ft_putendl(char const *s);
char				*ft_itoa(int n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strrev(char *str);
void				ft_putchar_fd(char c, int fd);
char				*ft_strdup(const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putstr_fd(char const *s, int fd);
void				*ft_memset(void *str, int c, size_t len);
int					ft_atoi(const char *str);
int					ft_isspace(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
#endif
