/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:49:15 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/03 17:18:43 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *neddle, size_t len)
{
	size_t	idx;
	size_t	n_idx;
	size_t	idx_tmp;
	
	if (*neddle == '\0')
		return ((char*)haystack);
	idx = 0;
	while (haystack[idx] && idx < len)
	{
		n_idx = 0;
		if (haystack[idx] == neddle[n_idx++])
		{	
			idx_tmp = idx + 1;
			while (haystack[idx_tmp] == neddle[n_idx])
			{
				idx_tmp++;
				n_idx++;
			}
			if (idx_tmp <= len && n_idx == ft_strlen(neddle))
				return ((char*)haystack + idx);
		}
		idx++;
	}
	return (NULL);
}

