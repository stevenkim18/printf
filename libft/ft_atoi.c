/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 02:25:25 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/04 02:51:37 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	idx;
	int 	sign;
	int	value;
	
	idx = 0;
	while (str[idx] && 
		(str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13)))
		idx++;
	sign = 1;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	value = 0;
	while (str[idx] && (str[idx] >= '0' && str[idx] <= '9'))
	{
		value = (value * 10) + (str[idx] - 48);
		idx++;
	}
	return (value * sign);
}

