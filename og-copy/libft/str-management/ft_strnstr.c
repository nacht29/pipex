/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:18:38 by yachan            #+#    #+#             */
/*   Updated: 2024/08/15 16:22:33 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*locates a substr (needle) in a main str (haystack)
*return value: substr if located || NULL if substr is not located
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len;

	len = ft_strlen(needle);
	if (n == 0 && haystack == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len <= n)
	{
		if (ft_strncmp(haystack, needle, len) == 0)
			return ((char *)haystack);
		n--;
		haystack++;
	}
	return (NULL);
}
