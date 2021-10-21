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
	while (src[c] != 0)
	{
		dest[c + count] = src[c];
		c++;
	}
	dest[c + count] = 0;
	return (dest);
}
