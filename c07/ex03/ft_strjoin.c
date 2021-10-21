#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	c;
	unsigned int	count;

	count = 0;
	while (dest[count] != 0)
	{
		count++;
	}
	c = 0;
	while (src[c] != '\0')
	{
		dest[c + count] = src[c];
		c++;
	}
	dest[c + count] = 0;
	return (dest);
}

int	size_str(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

int	size_all(int size, char *strs[], char *sep)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	counter += size_str(sep) * (size - 1);
	while (i < size)
	{
		counter += size_str(strs[i]);
		i++;
	}
	return (counter);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * size_all(size, strs, sep));
	i = 0;
	while (i < size)
	{
		str = ft_strcat(str, strs[i]);
		if (i + 1 != size)
			str = ft_strcat(str, sep);
		i++;
	}
	return (str);
}
