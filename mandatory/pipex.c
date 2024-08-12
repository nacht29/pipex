#include "../includes/pipex.h"

int	main(int ac, char*av[])
{
	int		end[2];
	pid_t	parent;


	if (ac != 5) // ac < 4 for bonus
		quit("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (pipe(end) < 0)
		quit("Pipe error");
	parent = fork();
	if (parent < 0)
		quit("Fork error ");
	if (!parent)
		// child_process();
		;
	else
		// parent_process();
		;
}

void	parent_process(char **av, int *end)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0622);
	if (outfile < 0)
		quit("Failed to open outfile");
	close(end[1]);
	dup2(end[0], STDIN_FILENO);
	close(end[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	// exec_cmd();
}

void	child_process(char **av, int *end)
{
	int	infile;

	infile = open(av[1], O_RDONLY | O_CREAT, 0644);
	if (infile < 0)
		quit("Failed to open infile");
	close(end[0]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	// exec_cmd();
}
