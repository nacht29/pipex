#include "pipex_bonus.h"

int main(int ac, char *av[], char **env)
{
	int		cmd_id;
	int		end[2];
	pid_t	proc_id;

	if (ac < 5)
		quit("Ussge: ./pipex file1 cmd1 cmd2 ... file2");
	manage_files(ac, av, &cmd_id);
	while (cmd_id < ac - 2)
	{
		create_child_process(av[cmd_id], env);
		cmd_id++;
	}
}

int	open_files(int ac, char **av, int file_mode)
{
	int	fd;

	if (file_mode == INFILE)
		fd = open(av[1],  O_RDONLY | O_CREAT, 0644);
	else if (file_mode == OUTFILE)
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0622);
	if (fd < 0)
		quit("Failed to open file");
	return (fd);
}

void	manage_files(int ac, char **av, int *cmd_id)
{
	int	infile;

	if ("here_doc")
		return ;
	else
	{
		*cmd_id = 2;
		infile = 0;
	}
}

void	create_child_process(char *cmd, char **env)
{
	int		end[2];
	pid_t	proc_id;

	if (pipe(end) < 0)
		quit("Pipe error");
	proc_id = fork();
	if (proc_id < 0)
		quit("Fork error");
	if (proc_id == 0) //represents the child
	{
		close(end[0]);
		dup2(end[1], STDOUT_FILENO);
		close(end[1]);
		exec_cmd(cmd, env);
	}
	else
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		close(end[0]);
		wait(NULL);
	}
}
