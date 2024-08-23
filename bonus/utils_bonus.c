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
