/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:32:38 by yachan            #+#    #+#             */
/*   Updated: 2024/08/25 18:33:04 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	quit(const char *err_msg)
{
	ft_printf("%s\n", err_msg);
	exit(EXIT_FAILURE);
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
		full_path = ft_strjoin(dir_names[i], ft_strjoin("/", cmd));
		if (access(full_path, F_OK | X_OK) == 0)
			break ;
		free(full_path);
		full_path = NULL;
	}
	free_str_arr(&dir_names);
	return (full_path);
}

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
