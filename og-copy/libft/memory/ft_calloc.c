/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:02:33 by yachan            #+#    #+#             */
/*   Updated: 2024/08/15 16:20:54 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
dynamically allocates memory and sets allocated bytes to 0
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*holder;
	size_t	total_size;

	if ((size && (nmemb > UINT_MAX / size)) || (nmemb && (size > UINT_MAX
				/ nmemb)))
		return (NULL);
	total_size = nmemb * size;
	holder = malloc(total_size);
	if (!holder)
		return (NULL);
	ft_memset(holder, 0, total_size);
	return (holder);
}

/*
#include <stdio.h>
int main(void)
{
	// int *int_arr = ft_calloc(4, sizeof(int));
	// if (!int_arr)
	// 	return (0);
	char *str = ft_calloc(4, sizeof(char));
	// char *str = malloc(sizeof(char) * 4);
	// for (int i = 0; i < 4; i ++)
	// 	printf("str[%i]: %c\n", i, str[i]);
	// 	write(1, &str[i], 1);
	// printf("str[10]: %c\n", str[10]);
	write(1, "str: ", 5);
	write(1, str, 10);
}
*/