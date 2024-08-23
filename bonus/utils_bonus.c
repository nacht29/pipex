#include "../includes/pipex_bonus.h"

void	free_str_arr(char ***str_arr)
{
	char	**arr;
	int		i;

	if (!str_arr || !*str_arr)
		return ;
	arr = *str_arr;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	*str_arr = NULL;
}

void	invalid_input()
{
	quit("Usage:\n"
	"1) ./pipex infile cmd1 cmd2 ... outfile\n"
	"2) ./pipex here_doc LIMITER cmd1 cmd2 ... outfile");
}
