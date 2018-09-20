/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:17:04 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/10 11:32:34 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		options(char o)
{
	if (o == 'l' || o == 'R' || o == 'a' || o == 'r' || o == 't' || o == '-')
		return (1);
	else
		return (0);
}

void	ft_insert(char *x, char *d)
{
	struct s_list	*temp;
	int				i;

	temp = (struct s_list*)malloc(sizeof(struct s_list));
	i = 0;
	while (x[i])
	{
		temp->name[i] = x[i];
		i++;
	}
	temp->name[i] = '\0';
	i = 0;
	while (d[i])
	{
		temp->date[i] = d[i];
		i++;
	}
	temp->date[i] = '\0';
	temp->next = NULL;
	if (head != NULL)
		temp->next = head;
	head = temp;
}

void	option_r(char *s)
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
		ptr = ctime(&sb.st_mtime);
		p = ft_trim(ptr);
		if (direntp != NULL && direntp->d_name[0] != '.')
			ft_insert(direntp->d_name, p);
		ft_bzero(f, PATH_MAX);
	}
	closedir(dirp);
	al_sort(head);
	ft_pl(head);
}

void	option_a(char *s)
{
	DIR		*dirp;
	char	f[PATH_MAX];

	dirp = opendir(s);
	while ((direntp = readdir(dirp)) != NULL)
	{
		ft_strcpy(f, s);
		ft_strcat(f, "/");
		ft_strcat(f, direntp->d_name);
		lstat(f, &sb);
		stat(direntp->d_name, &sb);
		ft_insert_name(direntp->d_name);
		ft_bzero(f, PATH_MAX);
	}
	closedir(dirp);
	al_sort(head);
	head = reverse(head);
	ft_pl(head);
}
