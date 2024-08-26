/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:05:53 by yachan            #+#    #+#             */
/*   Updated: 2024/08/25 18:35:09 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	alloc_len(int n);
static void		make_str(char **str, size_t len, int n, long num);

/*
converts integer to string
*/
char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	char	*str;

	num = n;
	if (n < 0)
		num = -num;
	len = alloc_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	make_str(&str, len, n, num);
	return (str);
}

static size_t	alloc_len(int n)
{
	long	num;
	size_t	len;

	len = 1;
	num = n;
	if (n < 0)
		num = -num;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	if (n < 0)
		return (len + 1);
	return (len);
}

static void	make_str(char **str, size_t len, int n, long num)
{
	size_t	og_len;

	og_len = len;
	while (len > 0)
	{
		(*str)[len - 1] = '0' + num % 10;
		num /= 10;
		len--;
	}
	if (n < 0)
		(*str)[0] = '-';
	(*str)[og_len] = '\0';
}
