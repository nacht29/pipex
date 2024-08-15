/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:02:28 by yachan            #+#    #+#             */
/*   Updated: 2024/08/15 16:18:25 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
converts string to integer
accept whitespaces and 1 sign (+) (-) before digits
*/
int	ft_atoi(const char *nptr)
{
	int	op;
	int	results;

	op = 1;
	results = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			op *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		results = results * 10 + (*nptr - '0');
		nptr++;
	}
	return (results * op);
}
