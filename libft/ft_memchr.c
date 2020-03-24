/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 02:39:38 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/02 03:02:26 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t	idx;
	unsigned char *ptr;

	idx = 0;
	ptr = (unsigned char*)s;
	while (idx < n)
	{	
		if (ptr[idx] == (unsigned char)c)
			return (s + idx);
		idx++;
	}
	return (NULL);
}

