/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:28:51 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/10 15:47:31 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*reverse(t_list *head)
{
	t_list	*p;
	t_list	*q;
	t_list	*r;

	q = head;
	r = q->next;
	while (q != NULL)
	{
		q->next = p;
		p = q;
		q = r;
		if (r != NULL)
			r = r->next;
	}
	return (p);
}

void	get_opt(char str, t_opt *f)
{
	if (str == 'l')
		f->l++;
	else if (str == 'r')
		f->r++;
	else if (str == 'a')
		f->a++;
	else if (str == 't')
		f->t++;
	else if (str == '-')
		f->d++;
	else if (str == 'R')
		f->rr++;
}

void	ft_default(char *s)
{
	DIR		*dirp;
	char	f[PATH_MAX];

	dirp = opendir(s);
	while ((direntp = readdir(dirp)) != NULL)
	{
		ft_strcpy(f, s);
		ft_strcat(f, "/");
		ft_strcat(f, direntp->d_name);
		stat(direntp->d_name, &sb);
		if (direntp->d_name[0] != '.')
			ft_insert_name(direntp->d_name);
		bzero(f, PATH_MAX);
	}
	closedir(dirp);
	al_sort(head);
	head = reverse(head);
	ft_pl(head);
}

void	inner_loop(char *s, t_opt *op)
{
	int j;

	j = 1;
	while (s[j] != '\0')
	{
		if (options(s[j]) == 0)
			print_error(s[j]);
		else
			get_opt(s[j], op);
		j++;
	}
}

int		first_part(char *s, t_opt *op)
{
	if (s[0] == '-' && s[1] != '\0')
	{
		if (!options(s[1]) && s[2] == '\0')
			print_error(s[1]);
		else
			inner_loop(s, op);
		return (1);
	}
	else if (lstat(s, &sb) != 0)
	{
		ft_perror(s);
		return (-1);
	}
	return (0);
}
