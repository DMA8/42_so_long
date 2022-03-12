/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:23:03 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:23:03 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_strlen(const char *s);
char	*ft_itoa(int n);
int		ft_atoi(const char *s);
void	ft_bzero(void *dest, size_t nbytes);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t nbytes);
void	*ft_memmove(void *dest, const void *src, size_t nbytes);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *src_str, int char_to_find);
char	*ft_strdup(const char*str);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t nbytes);
size_t	ft_strlcpy(char *dst, const char *src, size_t nbytes);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *src_str, const char *goal_str, size_t len);
char	*ft_strrchr(const char *src_str, int char_to_find);
char	*ft_strtrim(const char *s1, char const *set);
char	*ft_substr(const char *src, unsigned int start, size_t len);
int		ft_tolower(int s);
int		ft_toupper(int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *input_str, ...);
int		ft_putunsignedint_fd(int n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_hex_fd(unsigned int n, char size, int fd);
int		ft_put_void_ptr_fd(void *a, int fd);

#endif