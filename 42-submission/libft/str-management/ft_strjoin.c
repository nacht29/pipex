/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:15:55 by yachan            #+#    #+#             */
/*   Updated: 2024/08/15 16:22:02 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*allocate memory and concatenate two str
*return value: concatenated str
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*final_str;
	char	*holder;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	holder = malloc(total_size + 1);
	if (!holder)
		return (NULL);
	final_str = holder;
	while (*s1)
	{
		*holder = *s1;
		holder++;
		s1++;
	}
	while (*s2)
	{
		*holder = *s2;
		holder++;
		s2++;
	}
	*holder = '\0';
	return (final_str);
}
