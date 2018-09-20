/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 15:14:48 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/10 16:04:40 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		inc;
	size_t	endc;

	inc = 0;
	endc = (size_t)ft_strlen(dest);
	while (src[inc] != '\0')
	{
		dest[endc] = src[inc];
		inc++;
		endc++;
	}
	dest[endc] = '\0';
	return (dest);
}

int		num_path(int n, char **s)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (lstat(s[i], &sb) == 0)
			j++;
		i++;
	}
	return (j);
}

void	rec(unsigned char typ, char *newdir)
{
	if (typ == 4)
	{
		ft_putstr("\n");
		ft_putstr(newdir);
		ft_putstr(":\n");
		option_rr(newdir);
	}
}

void	option_rr(char *path)
{
	DIR		*dp;
	char	newdir[PATH_MAX];
	int		i;

	i = 0;
	dp = opendir(path);
	while ((direntp = readdir(dp)))
	{
		if (direntp->d_name[0] != '.')
			ft_putstr(direntp->d_name);
		ft_putchar('\n');
	}
	closedir(dp);
	dp = opendir(path);
	while ((direntp = readdir(dp)))
	{
		ft_strcpy(newdir, path);
		ft_strcat(newdir, "/");
		ft_strcat(newdir, direntp->d_name);
		stat(newdir, &sb);
		if (direntp->d_name[0] != '.')
			rec(direntp->d_type, newdir);
		ft_bzero(newdir, PATH_MAX);
	}
	closedir(dp);
}
