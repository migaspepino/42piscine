/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:39:33 by mimarque          #+#    #+#             */
/*   Updated: 2021/07/12 18:39:41 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_np(char a)
{
	char	t;
	char	u;

	t = "0123456789abcdef"[a / 16];
	u = "0123456789abcdef"[a % 16];
	write(1, "\\", 1);
	write(1, &t, 1);
	write(1, &u, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 0)
			str[i] = str[i] + 256;
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
		{
			print_np(str[i]);
		}
		else
		{
			c = str[i];
			write(1, &c, 1);
		}
		i++;
	}
}
