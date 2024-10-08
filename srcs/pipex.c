/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:16:23 by yachan            #+#    #+#             */
/*   Updated: 2024/08/26 19:42:51 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char *av[], char **env)
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
	proc_id = fork();
	if (proc_id < 0)
		quit("Fork error");
	else if (proc_id == 0)
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

void	here_doc(int ac, char **av)
{
	int		end[2];
	pid_t	proc_id;

	if (ac < 6)
		invalid_input();
	if (pipe(end) < 0)
		quit("Pipe error");
	proc_id = fork();
	if (proc_id < 0)
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

void	here_doc_prompt(int end[2], char *limiter)
{
	char	*line;
	size_t	check;

	while (1)
	{
		ft_printf("> ");
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			check = ft_strlen(limiter);
			if (line[check] == '\n' || line[check] == '\0')
				break ;
		}
		write(end[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(end[1]);
	exit(EXIT_SUCCESS);
}
