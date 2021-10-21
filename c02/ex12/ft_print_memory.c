/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:47:16 by mimarque          #+#    #+#             */
/*   Updated: 2021/07/12 18:47:25 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	print_add(void *addr)
{
	int				i;
	unsigned char	hi;
	unsigned char	lo;
	unsigned char	buf[sizeof(addr)];

	memcpy(buf, &addr, sizeof(addr));
	i = sizeof(addr) - 1;
	while (i >= 0)
	{
		hi = (buf[i] >> 4) & 0xf;
		lo = buf[i] & 0xf;
		if (hi < 10)
			hi += '0';
		else
			hi += 'a' - 10;
		if (lo < 10)
			lo += '0';
		else
			lo += 'a' - 10;
		write(1, &hi, 1);
		write(1, &lo, 1);
		i--;
	}
	write(1, ": ", 2);
}

void	print_hex(char c)
{
	char	c1;
	char	c2;

	c1 = "0123456789ABCDEF"[c / 16];
	c2 = "0123456789ABCDEF"[c % 16];
	write(1, &c1, 1);
	write(1, &c2, 1);
}

void	print_hex_value(char *addr)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (addr[i] != '\0' || i < 16)
	{
		if (addr[i] != '\0' && f == 0)
		{
			print_hex(addr[i]);
			if ((i - 17) % 2 == 0)
				write(1, " ", 1);
			i++;
		}
		else
		{
			if (f == 0)
				write(1, "00", 2);
			f = 1;
			if ((i - 17) % 2 == 0)
				write(1, " ", 1);
			i++;
		}
	}
}

void	print_lit_value(char *addr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 15)
	{
		if (addr[i] < 32 || addr[i] > 126)
		{
			write(1, ".", 1);
		}
		else
		{
			c = addr[i];
			write(1, &c, 1);
		}
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			buff[17];

	i = 0;
	while (i * 16 < size)
	{
		memcpy(buff, &addr[i * 15], 16);
		buff[16] = '\0';
		print_add(addr + i * 16);
		print_hex_value(buff);
		print_lit_value(buff);
		i++;
	}
	return (addr);
}
