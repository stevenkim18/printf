/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 11:07:16 by seunkim           #+#    #+#             */
/*   Updated: 2020/04/18 11:07:20 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(long long num, int isupcase)
{
	char *hexup;
	char *hexlow;

	hexup = "0123456789ABCDEF";
	hexlow = "0123456789abcdef";
	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
	}
	if (num >= 16)
	{
		ft_puthex(num / 16, isupcase);
		ft_puthex(num % 16, isupcase);
	}
	else
	{
		if (isupcase)
			write(1, &hexup[num], 1);
		else
			write(1, &hexlow[num], 1);
	}
}
