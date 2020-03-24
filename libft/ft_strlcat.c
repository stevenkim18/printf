/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 02:08:43 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/05 03:31:29 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{	
	size_t	idx;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	idx = 0;
	while (src[idx] && idx + dest_len + 1 < dstsize)
	{
		dest[idx + dest_len] = src[idx];
		idx++;
	}
	dest[idx + dest_len] = '\0';
	if (dstsize < dest_len)
		return (src_len + dstsize);
	return (dest_len + src_len);
}

