/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 01:20:58 by seunkim           #+#    #+#             */
/*   Updated: 2020/02/29 01:01:38 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		idx;
	unsigned char* 	dest_tmp;
	unsigned char*	src_tmp;
	
	if (dest == NULL && src == NULL)
		return (NULL);
	idx = 0;
	dest_tmp = (unsigned char*)dest;
	src_tmp = (unsigned char*)src;
	while (idx < n)
	{
		dest_tmp[idx] = src_tmp[idx];
		idx++;
	}
	return (dest);
}

