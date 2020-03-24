/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:18:03 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/07 01:19:37 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		write(fd, &s[idx], 1);
		idx++;
	}
	write(fd, "\n", 1);
}
