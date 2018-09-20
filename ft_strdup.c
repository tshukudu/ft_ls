/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stridup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:26:01 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/10 14:55:37 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_strdup(char *str, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
}

void	ft_pl(t_list *l)
{
	t_list *s;

	s = l;
	while (s)
	{
		ft_putstr(s->name);
		ft_putchar('\n');
		s = s->next;
	}
}

void	d_sort(t_list *s)
{
	t_list	*i;
	t_list	*j;
	char	temp[50];
	char	t[50];

	i = s;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (ft_strcmp(i->date, j->date) < 0)
			{
				ft_strdup(temp, i->date);
				ft_strdup(t, i->name);
				ft_strdup(i->date, j->date);
				ft_strdup(i->name, j->name);
				ft_strdup(j->date, temp);
				ft_strdup(j->name, t);
			}
			j = j->next;
		}
		i = i->next;
	}
}
