/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:28:36 by yachan            #+#    #+#             */
/*   Updated: 2024/08/25 18:28:37 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# ifdef __APPLE__
#  define OP OPEN_MAX
# elif _WIN32 || _WIN64 || __linux__
#  define OP FOPEN_MAX
# else
#  error "Unsupported operating system"
# endif

# define TRUE 1
# define FALSE 0

typedef struct s_linked_list
{
	char					*str;
	struct s_linked_list	*next;
}	t_node;

char	*get_next_line(int fd);
int		read_to_list(t_node **lst, int fd);
void	add_node(t_node **lst, char *buffer);
char	*extract_line(t_node *lst, char **temp_buff);
void	free_list(t_node **lst);

int		has_newline(const char *s, int c);
void	free_list(t_node **lst);
#endif