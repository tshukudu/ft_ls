/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 15:14:33 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/10 13:21:39 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	details(struct stat sb)
{
	char *ptr;

	if ((pwd = getpwuid(sb.st_uid)) != NULL)
		print_more(pwd->pw_name);
	if ((grp = getgrgid(sb.st_gid)) != NULL)
		print_more(grp->gr_name);
	ft_putchar('	');
	ft_putnbr((long long)sb.st_size);
	ft_putchar('	');
	ptr = ctime(&sb.st_mtime);
	ft_xit(ptr);
}

void	print_dir_name(int i, char *s)
{
	if (!(i < 2))
	{
		ft_putstr(s);
		ft_putstr(":\n");
	}
}

void	option_t(char *s)
{
	char	*p;
	char	*ptr;
	DIR		*dirp;
	char	f[PATH_MAX];

	p = "";
	dirp = opendir(s);
	while ((direntp = readdir(dirp)) != NULL)
	{
		ft_strcpy(f, s);
		ft_strcat(f, "/");
		ft_strcat(f, direntp->d_name);
		stat(direntp->d_name, &sb);
		ptr = ctime(&sb.st_ctime);
		p = ft_trim(ptr);
		if (direntp != NULL && direntp->d_name[0] != '.')
			ft_insert(direntp->d_name, p);
		ft_bzero(f, PATH_MAX);
	}
	closedir(dirp);
	d_sort(head);
	ft_pl(head);
}
