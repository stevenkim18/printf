/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:48:46 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/02 01:29:57 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t idx;

	if (dest <= src)
		ft_memcpy(dest, src, len);
	else
	{
		idx = len;
		while (idx)
		{	
			idx--;
			((unsigned char*)dest)[idx] = ((unsigned char*)src)[idx];
		}
	}
	return (dest);
}

