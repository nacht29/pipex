#include "pipex_bonus.h"

int main(int ac, char *av[], char **env)
{
	int		i;
	int		**pipes;
	pid_t	parent;

	if (ac < 5)
		quit("Usage: ./pipex infile cmd1 cmd2 ... outfile");
	pipes = malloc(sizeof(int *) * (ac - 4));
	i = -1;
	while (++i < (ac - 4))
	{
		pipes[i] = malloc(sizeof(int) * 2);
        if (pipe(pipes[i]) < 0)
            quit("Pipe error");
	}
}
