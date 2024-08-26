/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:15:18 by yachan            #+#    #+#             */
/*   Updated: 2024/08/15 16:21:43 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*allocates memory and duplicate a str
*return value: duplicated str
*/
char	*ft_strdup(const char *src)
{
	int		i;
	char	*holder;

	i = 0;
	holder = malloc(ft_strlen(src) + 1);
	if (!holder)
		return (NULL);
	while (src[i])
	{
		holder[i] = src[i];
		i++;
	}
	holder[i] = '\0';
	return (holder);
}
