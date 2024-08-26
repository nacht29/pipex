/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacht <nacht@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:16:26 by yachan            #+#    #+#             */
/*   Updated: 2024/08/26 16:34:22 by nacht            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	quit(const char *err_msg)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

int	open_file(int ac, char **av, int file_mode)
{
	int	fd;

	fd = 0;
	if (file_mode == INFILE)
		fd = open(av[1], O_RDONLY, 0644);
	else if (file_mode == OUTFILE)
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0622);
	else if (file_mode == OUTFILE_HD)
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0622);
	if (fd < 0)
		quit("Failed to open file");
	return (fd);
}

void	exec_cmd(char *cmd, char **env)
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	path = find_path(args[0], env);
	if (!path)
	{
		free_str_arr(&args);
		quit("Command not found");
	}
	if (execve(path, args, env) == -1)
		quit("Failed to execute command");
}

char	*find_path(char *cmd, char **env)
{
	char	*full_path;
	char	**dir_names;
	char	*temp;
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	dir_names = ft_split((env[i] + 5), ':');
	i = -1;
	while (dir_names[++i])
	{
		temp = ft_strjoin("/", cmd);
		full_path = ft_strjoin(dir_names[i], temp);
		if (access(full_path, F_OK | X_OK) == 0)
			break ;
		free(temp);
		free(full_path);
		full_path = NULL;
	}
	free_str_arr(&dir_names);
	return (full_path);
}
