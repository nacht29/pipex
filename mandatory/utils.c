#include "../includes/pipex.h"

void	quit(const char *err_msg)
{
	ft_printf("%s\n", err_msg);
	exit(EXIT_FAILURE);
}