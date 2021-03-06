/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:21:41 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/05 11:22:30 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_trim(char *t)
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
			j++;
		i++;
	}
	t[i] = '\0';
	p[j + 3] = '\0';
	return (p);
}
