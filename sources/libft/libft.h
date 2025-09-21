/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcardair <tcardair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:24:00 by tcardair          #+#    #+#             */
/*   Updated: 2025/05/28 17:17:01 by tcardair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
//# include <stddef.h>
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
// Checks if the character is printable
int					ft_isprint(int c);

// Returns the length of the string
int					ft_strlen(const char *s);

// Fills memory with a constant byte
void				*ft_memset(void *s, int c, size_t n);

// Sets memory to zero
void				ft_bzero(void *s, size_t n);

// Copies memory area
void				*ft_memcpy(void *dest, const void *src, size_t n);

// Moves memory area
void				*ft_memmove(void *dest, const void *src, size_t n);

// Scans memory for a character
void				*ft_memchr(const void *s, int c, size_t n);

// Compares memory areas
int					ft_memcmp(const void *s1, const void *s2, size_t n);

// Copies a string with size limit
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

// Concatenates a string with size limit
size_t				ft_strlcat(char *dst, const char *src, size_t size);

// Converts a string to an integer,
int					ft_atoi(const char *str);

// Converts a string to a long
long				ft_atol(const char *str);

// Locates the first occurrence of a character in a string
char				*ft_strchr(const char *s, int c);

// Locates the last occurrence of a character in a string
char				*ft_strrchr(const char *s, int c);

// Compares two strings up to a specified number of characters
int					ft_strncmp(const char *s1, const char *s2, size_t n);

// Locates a substring within a string, searching up to a specified length
char				*ft_strnstr(const char *source, const char *target,
						size_t len);

// Duplicates a string by allocating memory and copying the content
char				*ft_strdup(const char *s1);

// Allocates memory for an array and initializes it to zero
void				*ft_calloc(size_t count, size_t size);

// Converts a lowercase character to uppercase
int					ft_toupper(int c);

// Converts an uppercase character to lowercase
int					ft_tolower(int c);

// Extracts a substring from a string
char				*ft_substr(char const *s, unsigned int start, size_t len);

// Joins two strings into a new string
char				*ft_strjoin(char const *s1, char const *s2);

// Trims the characters in 'set' from the beginning and end of 's1'
char				*ft_strtrim(char const *s1, char const *set);

// Splits a string into an array of strings using the character as a delimiter
char				**ft_split(char const *s, char c);

// Converts an integer to a string
char				*ft_itoa(int n);

// Applies function 'f' to each character of 's' to create a new string
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Applies function 'f' to each character of 's' (in-place)
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

// Outputs character 'c' to given file descriptor
void				ft_putchar_fd(char c, int fd);

// Outputs string 's' to given file descriptor
void				ft_putstr_fd(char *s, int fd);

// Outputs string 's' to given file descriptor, then a newline
void				ft_putendl_fd(char *s, int fd);

// Outputs integer 'n' to given file descriptor
void				ft_putnbr_fd(int n, int fd);

// Allocates memory for new list node with 'content'
t_list				*ft_lstnew(void *content);

// Adds node 'new' at beginning of list
void				ft_lstadd_front(t_list **lst, t_list *new);

// Counts number of nodes in list
int					ft_lstsize(t_list *lst);

// Returns last node of list
t_list				*ft_lstlast(t_list *lst);

// Adds node 'new' at end of list
void				ft_lstadd_back(t_list **lst, t_list *new);

// Frees memory of node 'lst' using 'del'
void				ft_lstdelone(t_list *lst, void (*del)(void *));

// Deletes and frees all nodes of list, sets '*lst' to NULL
void				ft_lstclear(t_list **lst, void (*del)(void *));

// Applies function 'f' to content of each node
void				ft_lstiter(t_list *lst, void (*f)(void *));

// Creates new list by applying function 'f' to each node of original list
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					arraylen(char **str);
int					ft_printf(const char *str, ...);
unsigned long long	to_hexa(unsigned long long addr);
char				*get_next_line(int fd);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strstr(const char *source, const char *target);
void				*my_malloc(t_list **list, size_t size);
void				my_free(t_list **list);
void				my_addtolist(t_list **list, void *data);
char				*get_extension(const char *source, const char *target);

#endif