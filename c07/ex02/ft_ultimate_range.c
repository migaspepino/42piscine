#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;
	int	j;

	j = 0;
	i = min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = malloc((sizeof(int) * ((long long int)max - (long long int)min)) + 1);
	*range = arr;
	if (arr == NULL)
		return (-1);
	while (i < max)
	{
		(*range)[j] = i;
		i++;
		j++;
	}
	return (j);
}
