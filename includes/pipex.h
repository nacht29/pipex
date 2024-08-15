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

//main
void	parent_process(char **av, int *end);
void	child_process(char **av, int *end); 
#endif