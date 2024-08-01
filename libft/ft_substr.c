/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <nacht29.study@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:24:25 by yachan            #+#    #+#             */
/*   Updated: 2024/06/19 18:57:04 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*holder;
	size_t	i;
	size_t	strt;

	if (!s)
		return (NULL);
	strt = (size_t)start;
	if (strt > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - strt + 1))
		holder = malloc(ft_strlen(s) - strt + 2);
	else
		holder = malloc(len + 1);
	if (!holder)
		return (NULL);
	i = 0;
	while (i < len && s[strt + i] != '\0')
	{
		holder[i] = s[strt + i];
		i++;
	}
	holder[len] = '\0';
	return (holder);
}
