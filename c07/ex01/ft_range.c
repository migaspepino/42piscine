#include <stdlib.h>

int	size(int min, int max)
{
	if (min >= max)
		return (-1);
	else
		return (max - min);
}

int	*ft_range(int min, int max)
{
	int	i;
	int	j;
	int	*arr;

	j = 0;
	i = min;
	if (size(min, max) == -1)
		return (NULL);
	arr = malloc(sizeof(int) * size(min, max));
	while (i < max)
	{
		arr[j] = i;
		i++;
		j++;
	}
	return (arr);
}
