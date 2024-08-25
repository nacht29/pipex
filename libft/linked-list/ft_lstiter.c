/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <nacht29.study@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:08:40 by yachan            #+#    #+#             */
/*   Updated: 2024/06/18 19:08:40 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*iterate through a linked list and 
apply function f() to the contents of each node
*return value: none
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;
	t_list	*current;

	if (!lst || !f)
		return ;
	current = lst;
	while (current)
	{
		temp = current->next;
		f(current->content);
		current = temp;
	}
}
