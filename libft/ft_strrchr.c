/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:18:49 by yachan            #+#    #+#             */
/*   Updated: 2024/08/02 01:22:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*locates the (last occurence) of char in a str
*return value: a substr startting from the (last occurence) of char || NULL if char is not found
*/
char	*ft_strrchr(const char *s, int c)
{
	char	ref;
	char	*temp;

	ref = (char)c;
	temp = (char *)s;
	while (*temp)
		temp++;
	while (temp != s)
	{
		if (*temp == ref)
			break ;
		temp--;
	}
	if (temp == s && *temp != ref)
		return (NULL);
	return (temp);
}
