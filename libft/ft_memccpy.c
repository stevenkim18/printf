/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 02:01:12 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/02 00:14:05 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	idx;

	idx = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (idx < n)
	{
		((unsigned char*)dest)[idx] = ((unsigned char*)src)[idx];
		if (((unsigned char*)src)[idx] == (unsigned char)c)
			return (dest + idx + 1);
		idx++;
	}
	return (NULL);
}

