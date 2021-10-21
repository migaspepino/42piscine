#include <unistd.h>

void	print(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		print('-');
		print('2');
		ft_putnbr(147483648);
	}
	else
	{
		if (nb < 0 && nb != -2147483648)
		{
			print('-');
			ft_putnbr(nb * -1);
		}
		else if (nb < 10 && nb >= 0)
		{
			print(nb + '0');
		}
		else
		{
			ft_putnbr(nb / 10);
			print(nb % 10 + '0');
		}
	}
}
