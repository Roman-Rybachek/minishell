/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:50:06 by jeldora           #+#    #+#             */
/*   Updated: 2020/10/06 18:00:25 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_printf(const char *fmt, ...);
int					get_next_line(int fd, char **line);
int					get_next_line_exam(char **line);
int					ft_free(void *obj_to_free);
t_list				*ft_lst_previous(t_list **all_lst, \
					t_list **current_lst);
void				ft_skip_spaces(char **input);
void				ft_3array_clr(char ***array);
int					ft_3array_len(char ***array);
char				***ft_darray_split(char **darray, char *split);
char				**ft_lst_to_darray(t_list *lst);
int					ft_cnt_occur(t_list *lst, void *content, \
									t_list **get_occur);
t_list				*ft_cntsrch(t_list *lst, void *content);
int					ft_fexist(char *path_to_file);
char				**ft_darray_dup(char **array);
int					ft_strmatch(const char *s1, const char *s2);
void				ft_clr_darray(char **array);
char				*ft_addchars(char *line, char c, int count);
int					ft_height_darray(char **darray);
char				**ft_darray(int value_of_str);
size_t				ft_nbr_len(int n);
char				*ft_itoa_l(unsigned int n);
char				*ft_itoa_hex_t(size_t n);
char				*ft_itoa_hex(size_t n);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
char				*ft_strnstr(const char *big, const char *l, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *l, void *(*f)(void *), \
void (*d)(void *));

#endif
