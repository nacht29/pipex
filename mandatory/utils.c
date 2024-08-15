#include "../includes/pipex.h"

void	quit(const char *err_msg)
{
	ft_printf("%s\n", err_msg);
	exit(EXIT_FAILURE);
}

/*
*the command cand be something like "ls -l"
*the command is split by space and stored in args as args = {"ls", "-l"}
*with find_path(args[0], env), we find the path to "ls" - path = find_path("ls", env)
*hence, path = "/bin/ls"
*/
void	exec_cmd(char *cmd, char **env)
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	path = find_path(args[0], env);
	if (execve(path, args, env) == -1)
		quit("Failed to execute command");
}

/*
*to break down a PATH env, say: PATH=/usr/local/bin:/usr/bin:/bin
*
*it lists the directories that will be searched in order, and each
directory name is separated by a colon (:)
*
*hence, in order, the directories will be searched
*(for reference: /usr/local/bin : /usr/bin : /bin)
*-/usr/local/bin
*-/usr/bin
*
*then, we will combine the command with the paths
*-/usr/local/bin + cat = /usr/local/bin/cat
*-/usr/bin + cat = /usr/bin/cat
*-/bin/cat
*
*once the constructed path is valid, it will be returned
*/

/*
*use strncmp to find PATH
*substr to extract everything after PATH=
*split the dir names by :
*iterate and join the dir names with the command name one by one
*return valid path to cmd
*else, return NULL / FALSE if all dirs had been tried and no path is valid, 
hence invalid cmd
*/
char	*find_path(char *cmd, char **env)
{
	char	*full_path;
	char	*path_str;
	char	**dir_names;
	int		i;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			path_str = ft_substr(*env, 5, (ft_strlen(*env) - 5));
			break;
		}
		env++;
	}
	dir_names = ft_split(path_str, ':');
	while (*dir_names)
	{
		full_path = ft_strjoin(*dir_names, ft_strjoin("/", cmd));
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		dir_names++;
	}
	free(full_path);
	return (NULL);
}
