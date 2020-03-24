/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:59:10 by seunkim           #+#    #+#             */
/*   Updated: 2020/02/27 15:41:02 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*	ft_memset(void *b, int c, size_t len)
{
	size_t		idx;
	size_t		size;
	unsigned char	value;
	char		*ptr;
	
	idx = 0;
	value = c;
	size = len;
	ptr = (char*)b;
	while(ptr[idx] && idx < size)
	{
		ptr[idx] = value;
		idx++;
	}
	return (b);
}

