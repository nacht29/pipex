#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

//files_and_exit
void	quit(const char *err_msg);
void	exec_cmd(char *cmd, char **env);
char	*find_path(char *cmd, char **env);

//utils
void	validate_input(int ac);
void	free_str_arr(char ***str_arr);

//main
void	parent_process(char **av, char **env, int *end);
void	child_process(char **av, char ** env, int *end);
#endif