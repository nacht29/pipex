/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:15:01 by yachan            #+#    #+#             */
/*   Updated: 2024/08/25 18:31:20 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*locates the (first occurence) of char in a str
*return value: a substr starting from the (first occurence) of char 
|| NULL if char is not found
*/
char	*ft_strchr(const char *s, int c)
{
	char	ref;
	char	*temp;

	ref = (char)c;
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == ref)
			return (temp);
		temp++;
	}
	if (c == '\0')
		return (temp);
	return (NULL);
}
