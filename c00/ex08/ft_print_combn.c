/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:51:24 by mimarque          #+#    #+#             */
/*   Updated: 2021/07/05 19:53:04 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printarray(int *a, int n)
{
	char	d;
	int		i;

	i = 0;
	while (i < n)
	{
		d = a[i] + '0';
		write(1, &d, 1);
		i++;
	}
	if (a[0] != 10 - n)
	{
		write(1, ", ", 2);
	}
}

void	generate_values(int *array, int d, int n)
{
	int	i;
	int	new_array[10];

	i = 0;
	//preenche new array com arg array
	while (i < 10)
	{
		new_array[i] = array[i];
		i++;
	}
	//digito = tamanho do sub array
	//comeca sempre do a[0] = 0 ou a[1] 1 etc...
	i = d;
	//caso base
	//caso digito seja igual a n-1 e o loop tente correr 10 vezes
	while (d == n - 1 && i < 10)
	{
		new_array[d] = i; //gera valores para esta posicao
		if (new_array[d - 1] < i || n == 1) //
			printarray(new_array, n);
		i++;
	}
	while (d != n - 1 && i < 9)
	{
		new_array[d] = i;
		if (i > new_array[d - 1] || d == 0)
			generate_values(new_array, d + 1, n);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	array[10];
	int	i;

	i = 0;
	//popula array
	while (i < 10)
	{
		array[i] = 0;
		i++;
	}
	//gera valores e imprime
	generate_values(array, 0, n);
}
