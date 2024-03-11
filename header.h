#ifndef HEADER_H
#define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
#include <ctype.h>

typedef struct s_list
{
	char    *key;
	char    *file_str;
	int		fd_input;
	int		fd_out;
}       t_list;

char			*get_next_line(int fd);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_isdigit(int c);
void			ft_exit();
void			remove_newline(char *str);
int				check_file(char *file);
int				check_key(char *key);
char			*incrypt_line(t_list *x, char *line, int code);
void			getting_input(t_list *x, int flag);
void			throw_valid_arg();
int				f2_dec(t_list *x, char *code);
int				f1_dec(t_list *x, char *file);

#endif