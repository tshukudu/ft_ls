/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:28:06 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/10 15:50:33 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_perm(struct stat s)
{
	ft_putchar((S_ISDIR(s.st_mode)) ? 'd' : '-');
	ft_putchar((s.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((s.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((s.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((s.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((s.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((s.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((s.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((s.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((s.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putchar(' ');
	ft_putnbr(s.st_nlink);
}

void	option_l(char *s)
{
	long int	n;
	DIR			*dp;
	char		f[PATH_MAX];

	n = 0;
	ft_get_block(s, &n);
	printblocks(n);
	dp = opendir(s);
	while ((direntp = readdir(dp)) != NULL)
	{
		ft_strcpy(f, s);
		ft_strcat(f, "/");
		ft_strcat(f, direntp->d_name);
		lstat(f, &sb);
		if (direntp->d_name[0] != '.')
		{
			print_perm(sb);
			details(sb);
			print_more(direntp->d_name);
			ft_putchar('\n');
		}
		ft_bzero(f, PATH_MAX);
	}
	closedir(dp);
}

void	newline(int n, char **s, t_opt op, int i)
{
	if (num_path(n, s) > 1 && op.l > 0)
	{
		if (!(i < 2))
			ft_putstr("\n");
	}
}

void	norm(int n, char **s, t_opt op, int i)
{
	if (num_path(n, s) > 1 && op.l > 0)
		print_dir_name(i, s[i]);
}

int		main(int n, char **s)
{
	t_opt	op;
	int		i;
	int		k;
	int		p;

	i = 1;
	k = check_path(n, s);
	p = num_path(n, s) - 1;
	initialize(&op);
	if (n == 1)
		ft_default(".");
	while (i < n)
	{
		if (first_part(s[i], &op) == -1)
			return (0);
		if (k == 0)
			s[i] = ".";
		norm(n, s, op, i);
		if ((s[i][0] == '.' || s[i][0] == '~' || s[i][0] == '/') && s[i])
			ex_do(s[i], op, n);
		newline(n, s, op, i);
		i++;
		p--;
	}
	return (0);
}
