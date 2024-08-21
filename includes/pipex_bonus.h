#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define INFILE 1
# define OUTFILE 0

//utils
void	quit(const char *err_msg);
char	*find_path(char *cmd, char **env);
void	free_str_arr(char ***str_arr);


//main
void	create_child_process(char *cmd, char **env);
#endif