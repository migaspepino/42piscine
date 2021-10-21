/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:51:19 by mimarque          #+#    #+#             */
/*   Updated: 2021/07/19 15:51:24 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	left;
	long long	right;
	long long	mid;

	left = 1;
	right = nb;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid * mid < nb)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (0);
}
