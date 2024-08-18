#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

//utils
void	quit(const char *err_msg);
char	*find_path(char *cmd, char **env);
void	free_str_arr(char ***str_arr);

#endif