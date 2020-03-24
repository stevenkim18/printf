/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:45:53 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/05 00:07:09 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	idx;
	
	len = ft_strlen(s1);
	if (!(ptr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	idx = 0;
	while (s1[idx])
	{	
		ptr[idx] = s1[idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}

