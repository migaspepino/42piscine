#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		c;
	char	*arr;

	c = 0;
	arr = malloc(sizeof(src) + 1);
	if (arr == NULL)
		return (arr);
	while (src[c] != '\0')
	{
		arr[c] = src[c];
		c++;
	}
	arr[c] = '\0';
	return (arr);
}
