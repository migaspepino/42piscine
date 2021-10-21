/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:32:08 by mimarque          #+#    #+#             */
/*   Updated: 2021/07/15 16:32:11 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int	is_base_ok(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || (base[1] == '\0'))
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == ' ' || base[i] == '\n' || base[i] == '+'
			|| base[i] == '-' || base[i] == '\t' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	get_numb(char *str, char *base, int end)
{
	int	power;
	int	i;
	int	j;
	int	numb;
	int	baseN;

	i = end;
	baseN = 0;
	numb = 0;
	power = 1;
	while (base[baseN] != '\0')
		baseN++;
	while (i >= 0)
	{
		j = 0;
		while (base[j] != str[i])
			j++;
		numb += j * power;
		power *= baseN;
		i--;
	}
	return (numb);
}

int	is_negative(char *str, int end)
{
	int	i;
	int	minus;

	minus = 0;
	i = 0;
	while (i < end)
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	return (minus % 2);
}

void	get_edges(char *str, char *base, int *start, int *end)
{
	int	i;
	int	j;
	int	f;
	int	f2;

	f = 0;
	f2 = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j] && f++ == 0)
				*start = i;
			if (str[i] == base[j] && f2 == 0)
				*end = i;
			j++;
		}
		if (*end + 1 == i)
			f2++;
		i++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	start;
	int	end;
	int	numb;

	start = 0;
	end = -3;
	if (is_base_ok(base))
	{
		get_edges(str, base, &start, &end);
		numb = get_numb(str, base, end);
		if (is_negative(str, end))
			numb *= -1;
		return (numb);
	}
	return (0);
}*/

int	ft_ver_bas(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1]
			|| base[i] == ' ' || base[i] == '\n' || base[i] == '\t'
			|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_mult_nbr(char d, char *base, int mult, int nbr)
{
	int	c;

	c = 0;
	while (base[c] != '\0')
	{
		if (d == base[c])
			return (nbr + (mult * c));
		c++;
	}
	return (nbr);
}

int	ft_isbase(char n, char *base)
{
	int	c;

	c = 0;
	if (n == '\n' || n == '\t' || n == '\v' || n == '\f' || n == '\r'
		|| n == ' ' || n == '+' || n == '-')
		return (1);
	while (base[c] != '\0')
	{
		if (base[c] == n)
			return (2);
		c++;
	}
	return (0);
}

int	ft_atoi_simpl(char *str, char *base, int size, int start)
{
	int	c;
	int	s;
	int	res;
	int	mult;

	c = start - 1;
	s = 1;
	res = 0;
	mult = 1;
	while (c >= 0)
	{
		if (str[c] == '-')
			s *= (-1);
		if (ft_isbase(str[c], base) == 2)
		{
			res = ft_mult_nbr(str[c], base, mult, res);
			mult *= size;
		}
		c--;
	}
	return (res * s);
}

int	ft_atoi_base(char *str, char *base)
{
	int	size;
	int	c;

	size = 0;
	c = 0;
	if (ft_ver_bas(base) == 0)
		return (0);
	while (base[size] != '\0')
		size++;
	while (str[c] == '\n' || str[c] == '\t' || str[c] == '\v'
		|| str[c] == '\f' || str[c] == '\r' || str[c] == ' ')
		c++;
	while (str[c] == '-' || str[c] == '+')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
		c++;
	return (ft_atoi_simpl(str, base, size, c));
}
