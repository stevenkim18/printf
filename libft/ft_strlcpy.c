/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:11:22 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/05 03:36:21 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	idx;
	
	idx = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[idx] && idx + 1 < dstsize)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (ft_strlen(src));
}

