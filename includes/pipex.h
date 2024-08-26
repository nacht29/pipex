/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:25:33 by yachan            #+#    #+#             */
/*   Updated: 2024/08/26 17:53:01 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

//here_doc
void	here_doc(int ac, char **av);
void	here_doc_prompt(int end[2], char *limiter);

//files_and_exit
void	quit(const char *err_msg);
int		open_file(int ac, char **av, int file_mode);
void	exec_cmd(char *cmd, char **env);
char	*find_path(char *cmd, char **env);

//utils
void	free_str_arr(char ***str_arr);
void	invalid_input(void);
#endif