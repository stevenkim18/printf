/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:22:57 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/07 01:32:29 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long long n, int fd)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else 
	{
		num += 48;
		write(fd, &num, 1);
	}
}
