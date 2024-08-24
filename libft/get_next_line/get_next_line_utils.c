#include "get_next_line.h"

int	has_newline(const char *s)
{
	char	*temp;

	temp = (char *)s;
	while (*temp)
	{
		temp++;
		if (*temp == '\n')
			return (TRUE);
		temp++;
	}
	return (FALSE);
}

void	free_list(t_node **lst)
{
	t_node	*temp;
	t_node	*current;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		free(current->str);
		free(current);
		current = temp;
	}
	(*lst) = NULL;
}
