/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:31:24 by mimarque          #+#    #+#             */
/*   Updated: 2021/07/15 16:31:29 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int	get_sign(char *str)
{
	int	c;
	int	end;
	int	sign_count;

	c = 0;
	sign_count = 0;
	while (str[c] >= '0' && str[c] <= '9')
	{
		c++;
	}
	end = c;
	c = 0;
	while (str[c] != '\0' && c < end)
	{
		if (str[c] == '-')
			sign_count++;
		c++;
	}
	return (sign_count % 2);
}

int	extract_numb(char *str, int start, int end)
{
	int	i;
	int	k;

	k = 0;
	i = start;
	while (i < start + end)
	{
		k = 10 * k + (str[i] - '0');
		i++;
	}
	return (k);
}

int	get_end_arr_ind_of_numb(char *str, int index)
{
	int	c;

	c = index;
	while (str[c] >= '0' && str[c] <= '9')
	{
		c++;
	}
	return (c - index);
}

int	get_numb(char *str)
{
	int	c;
	int	end;
	int	start;
	int	f;
	int	numb;

	c = 0;
	f = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= '0' && str[c] <= '9' && f == 0)
		{
			start = c;
			end = get_end_arr_ind_of_numb(str, start);
			f++;
		}
		c++;
	}
	numb = extract_numb(str, start, end);
	return (numb);
}

int	ft_atoi(char *str)
{
	int	numb;
	int	neg;

	numb = get_numb(str);
	neg = get_sign(str);
	if (neg == 1)
		numb = numb * -1;
	return (numb);
}*/

int	ft_atoi(char *str)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	while (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			s *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (str[c] - '0') + (res * 10);
		c++;
	}
	return (res * s);
}
