#include "../includes/pipex_bonus.h"

int main(int ac, char *av[], char **env)
{
	int		cmd_id;
	int		outfile;

	if (ac < 5)
		invalid_input();
	manage_files_hd(ac, av, &cmd_id, &outfile);
	while (cmd_id < ac - 2)
	{
		create_child_process(av[cmd_id], env);
		cmd_id++;
	}
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	exec_cmd(av[ac - 2], env);
	return (EXIT_SUCCESS);
}

void	manage_files_hd(int ac, char **av, int *cmd_id, int *outfile)
{
	int	infile;

	if (ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		*cmd_id = 3;
		*outfile = open_file(ac, av, OUTFILE_HD);
		here_doc(ac, av);
	}
	else
	{
		*cmd_id = 2;
		infile = open_file(ac, av, INFILE);
		dup2(infile, STDIN_FILENO);
		close(infile);
		*outfile = open_file(ac, av, OUTFILE);
	}
}

void	create_child_process(char *cmd, char **env)
{
	int		end[2];
	pid_t	proc_id;

	if (pipe(end) < 0)
		quit("Pipe error");
	if ((proc_id = fork()) < 0)
		quit("Fork error");
	else if (proc_id == 0) // represents the child
	{
		close(end[0]);
		dup2(end[1], STDOUT_FILENO);
		close(end[1]);
		exec_cmd(cmd, env);
	}
	else // parent
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		close(end[0]);
		wait(NULL);
	}
}

void	here_doc(int ac, char **av)
{
	int		end[2];
	pid_t	proc_id;

	if (ac < 6)
		invalid_input();
	if (pipe(end) < 0)
		quit("Pipe error");
	if ((proc_id = fork()) < 0)
		quit("Fork erorr");
	else if (proc_id == 0)
		here_doc_prompt(end, av[2]);
	else
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		close(end[0]);
		wait(NULL);
	}
}

void    here_doc_prompt(int end[2], char *limiter)
{
	char	*line;

	ft_printf("heredoc:\n");
	while ((line = get_next_line(0)) != NULL)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break;
		write(end[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(end[1]);
	exit(EXIT_SUCCESS);
}
