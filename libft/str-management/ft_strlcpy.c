/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:16:15 by yachan            #+#    #+#             */
/*   Updated: 2024/08/15 16:22:12 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*src_ptr;

	src_ptr = src;
	if (size == 0)
		return (ft_strlen(src_ptr));
	else if (ft_strlen(src) == 0)
	{
		*dst = '\0';
		return (0);
	}
	while ((size - 1) > 0 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (ft_strlen(src_ptr));
}
