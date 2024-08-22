#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define OUTFILE 0
# define INFILE 1
# define OUTFILE_HD 2

//main
void	manage_files_hd(int ac, char **av, int *cmd_id, int *outfile);
void	create_child_process(char *cmd, char **env);

//utils
void	quit(const char *err_msg);
int	    open_file(int ac, char **av, int file_mode);
void	exec_cmd(char *cmd, char **env);
char	*find_path(char *cmd, char **env);

//extra utils
void	free_str_arr(char ***str_arr);
#endif