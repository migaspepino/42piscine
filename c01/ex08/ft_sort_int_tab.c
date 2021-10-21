/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:12:29 by mimarque          #+#    #+#             */
/*   Updated: 2021/07/05 19:52:11 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *arr, int size)
{
	int	tmp;
	int	i;
	int	i2;

	i = 0;
	while (i < size)
	{
		i2 = 0;
		while (i2 < size)
		{
			if (arr[i2] > arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[i2];
				arr[i2] = tmp;
			}
			i2++;
		}
		i++;
	}
}
