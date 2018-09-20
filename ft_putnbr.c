/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 08:06:37 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/10 11:33:29 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putnbr(long long int n)
{
	long long int	integer;

	integer = (long long int)n;
	if (integer < 0)
	{
		ft_putchar('-');
		integer *= -1;
	}
	if (integer >= 10)
		ft_putnbr(integer / 10);
	ft_putchar(integer % 10 + 48);
}

void	al_sort(t_list *s)
{
	t_list	*i;
	t_list	*j;
	char	t[50];

	i = s;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (ft_strcmp(i->name, j->name) < 0)
			{
				ft_strdup(t, i->name);
				ft_strdup(i->name, j->name);
				ft_strdup(j->name, t);
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	ft_insert_name(char *x)
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
	temp->next = NULL;
	if (head != NULL)
		temp->next = head;
	head = temp;
}

void	ft_get_block(char *s, long int *n)
{
	DIR		*dp;
	char	f[PATH_MAX];

	dp = opendir(s);
	while ((direntp = readdir(dp)) != NULL)
	{
		ft_strcpy(f, s);
		ft_strcat(f, "/");
		ft_strcat(f, direntp->d_name);
		lstat(f, &sb);
		stat(direntp->d_name, &sb);
		if (direntp->d_name[0] != '.')
			*n += (long)sb.st_blocks;
		bzero(f, PATH_MAX);
	}
	closedir(dp);
}
