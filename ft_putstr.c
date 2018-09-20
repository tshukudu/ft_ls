/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 08:09:40 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/10 12:14:38 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	print_more(char *s)
{
	ft_putchar('	');
	ft_putstr(s);
}

int		ft_isascii(char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

void	printblocks(int n)
{
	if (n != 0)
	{
		ft_putstr("total ");
		ft_putnbr(n);
		ft_putchar('\n');
	}
}

void	ft_perror(char *s)
{
	ft_putstr("ft_ls: ");
	ft_putstr(s);
	ft_putstr(": No such file or directory\n");
}
