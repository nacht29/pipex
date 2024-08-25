/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:32:35 by yachan            #+#    #+#             */
/*   Updated: 2024/08/25 18:32:51 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char*av[], char **env)
{
	int		end[2];
	pid_t	proc_id;

	if (ac != 5)
		quit("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (pipe(end) < 0)
		quit("Pipe error");
	proc_id = fork();
	if (proc_id < 0)
		quit("Fork error");
	if (proc_id == 0)
		child_process(av, env, end);
	else
		parent_process(av, env, end);
}

/*
*receives input from the write end[1],
then closes the write end
*process the input with cmd2
*redirects the processed input to outfile as output
*/
void	parent_process(char **av, char **env, int *end)
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
	exec_cmd(av[3], env);
}

/*
*on the write end[1]
*closes read end[0]
*reads from infile an dmake infile STDIN (0)
*executes cmd1 for the input
*writes the processed input to the write end[0]
*input is piped to cmd2 for processing when the child process for cmd1 ends
*/
void	child_process(char **av, char **env, int *end)
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
	exec_cmd(av[2], env);
}
