/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:23:18 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/10 15:51:23 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_xit(char *t)
{
	int		i;
	int		d;
	char	*p;
	int		j;

	p = "";
	d = 2;
	i = 0;
	j = 0;
	while (t[i] != ' ' && t[i])
		i++;
	i++;
	p = &t[i];
	while (t[i])
	{
		if (t[i] == ':')
			d--;
		if (d != 0)
		{
			ft_putchar(t[i]);
			j++;
		}
		i++;
	}
	return (p);
}

void	ex_do(char *s, t_opt op, int n)
{
	if (lstat(s, &sb) == 0)
	{
		if (op.a > 0)
			option_a(s);
		else if (op.l > 0)
			option_l(s);
		else if (op.t > 0)
			option_t(s);
		else if (op.d > 0)
			ft_default(s);
		else if (op.r > 0)
			option_r(s);
		else if (op.rr > 0)
			option_rr(s);
		else if (check_flag(n, &s) == 0)
			ft_default(s);
	}
	else
		ft_perror(s);
}
