/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:27:13 by mtshukud          #+#    #+#             */
/*   Updated: 2018/09/06 15:22:41 by mtshukud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	size_t i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (((unsigned char)str1[i] - (unsigned char)str2[i]) > 0)
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		if (((unsigned char)str1[i] - (unsigned char)str2[i]) < 0)
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

void	print_error(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ./ft_ls [-Ralrt] [file ...]\n");
	exit(1);
}
