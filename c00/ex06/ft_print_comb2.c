/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:28:12 by mimarque          #+#    #+#             */
/*   Updated: 2021/07/02 15:12:10 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_send(char ch)
{
	write(1, &ch, 1);
}

// '0' + an int in c is the same as (char) 0 + int
void	ft_print(int a, int b)
{
	ft_send('0' + a / 10);
	ft_send('0' + a % 10);
	ft_send(' ');
	ft_send('0' + b / 10);
	ft_send('0' + b % 10);
	if (a != 98 || b != 99)
	{
		ft_send(',');
		ft_send(' ');
	}
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			ft_print(num1, num2);
			num2++;
		}
		num1++;
	}
}
