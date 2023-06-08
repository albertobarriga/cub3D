/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:56:48 by jlimones          #+#    #+#             */
/*   Updated: 2023/06/08 12:06:55 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void			ft_bzero(void *s, int n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memcpy(void *dst, const void *src, int n);
void			*ft_memmove(void *dst, const void *src, int len);
void			*ft_memset(void *b, int c, int len);
int				ft_strlcpy(char *dst, char *src, int size);
int				ft_strlen(const char *s);
int				ft_strlcat(char *dst, char *src, int size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, int n);
void			*ft_memchr(const void *s, int c, int n);
int				ft_memcmp(const void *s1, const void *s2, int n);
char			*ft_strnstr(const char *haynode, const char *needle, int n);
int				ft_atoi(const char *str);
void			*ft_calloc(int count, int size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_swap(int *a, int*b);

t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

int				ft_printf(const char *str, ...);

char			*get_next_line(int fd);
char			*ft_mod_join(char *buff, char *tmp_buff);
char			*ft_get_line(char *buff);
char			*ft_read(int fd, char *buff);
char			*ft_get_static(char *buff);
void			*ft_calloc_get(unsigned int nmemb, unsigned int size);
void			ft_bzero_get(void *s, unsigned int n);
char			*ft_strchr_get(const char *str, int c);
char			*ft_strjoin_get(char *s1, char const *s2);
int				ft_strlen_get(const char *s);

#endif