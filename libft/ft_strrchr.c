/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 04:53:51 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/05 03:56:43 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	idx;
	size_t	len;
	
	len = ft_strlen(s);
	idx = len - 1;
	while (idx >= 0)
	{	
		if (s[idx] == (char)c)
			return(s + idx);
		idx--;
	}
	if (c == '\0')
		return (s + len);
	return (NULL);
}

