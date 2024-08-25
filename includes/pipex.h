/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:25:10 by yachan            #+#    #+#             */
/*   Updated: 2024/08/25 18:25:49 by yachan           ###   ########.fr       */
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

//main
void	parent_process(char **av, char **env, int *end);
void	child_process(char **av, char **env, int *end);

//utils
void	quit(const char *err_msg);
void	exec_cmd(char *cmd, char **env);
char	*find_path(char *cmd, char **env);
void	free_str_arr(char ***str_arr);

#endif