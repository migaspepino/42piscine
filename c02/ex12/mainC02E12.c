#include <unistd.h>
#include <string.h>

#include "ft_print_memory.c"

int	main(void)
{
	char	*str;

	str = "Salut les aminches c'est cool show mem on fait de truc terrible\1\2";
	ft_print_memory(str, strlen(str));
}
