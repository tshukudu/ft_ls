/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:56:45 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/10 15:05:40 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <limits.h>
# include <strings.h>

struct dirent	*direntp;
struct stat		sb;
struct passwd	*pwd;
struct group	*grp;
void			ft_strdup(char *str, char *s);
int				ft_strcmp(const char *str1, const char *str2);
typedef struct	s_opt
{
	int l;
	int r;
	int	a;
	int t;
	int rr;
	int	d;
}				t_opt;
typedef struct	s_list
{
	char			name[50];
	char			date[50];
	struct s_list	*next;
}				t_list;
struct s_list	*head;
void			get_opt(char str, t_opt *f);
int				options(char o);
void			initialize(t_opt *fl);
char			*ft_trim(char *t);
void			*ft_xit(char *t);
int				ft_strlen(char *str);
void			ft_default(char *str);
void			ft_insert(char *x, char *d);
void			ft_pl(t_list *l);
void			d_sort(t_list *s);
void			option_t(char *s);
void			option_r(char *s);
void			option_l(char *s);
int				check_path(int n, char **s);
int				check_flag(int n, char **s);
void			print_error(char c);
void			ex_do(char *s, t_opt op, int n);
int				first_part(char *s, t_opt *op);
void			option_a(char *str);
void			ft_putchar(char c);
void			ft_putnbr(long long int n);
void			ft_putstr(char *s);
void			print_more(char *s);
int				ft_isascii(char c);
void			al_sort(t_list *s);
void			ft_insert_name(char *x);
t_list			*reverse(t_list *head);
void			insert_file(char *d);
void			ft_get_block(char *s, long int *n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);
void			ft_bzero(void *s, size_t n);
int				ft_strnlen(char *s);
int				num_path(int n, char **s);
void			option_rr(char *s);
void			printblocks(int n);
void			ft_perror(char *s);
void			details(struct stat s);
void			print_dir_name(int i, char *s);
#endif
