/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:33:07 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/05 16:47:02 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;	
	size_t	size;
	size_t	idx;

	if (ft_strlen(s) > start)
	{
		if (ft_strlen(s) >= start + len)
			size = len;
		else
			size = ft_strlen(s) - start;
	}
	else 
		size = 0;
	if (!(substr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s += start;
	idx = 0;
	while (s[idx] && idx < len)
	{
		substr[idx] = s[idx];
		idx++;
	}
	substr[idx] = '\0';
	return (substr);
}

