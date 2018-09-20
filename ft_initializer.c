/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:20:20 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/05 15:31:30 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	initialize(t_opt *fl)
{
	fl->l = 0;
	fl->r = 0;
	fl->a = 0;
	fl->t = 0;
	fl->d = 0;
	fl->rr = 0;
}

int		check_path(int n, char **s)
{
	int i;

	i = 1;
	while (i < n)
	{
		if (s[i][0] == '.' || s[i][0] == '~' || s[i][0] == '/')
			return (1);
		i++;
	}
	return (0);
}

int		check_flag(int n, char **s)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (options(s[i][0]))
			return (1);
		i++;
	}
	return (0);
}
