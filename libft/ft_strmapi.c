/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:20:44 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/06 21:35:10 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	idx = 0;
	while (s[idx] && idx < len)
	{
		str[idx] = f(idx, s[idx]);
		idx++;
	}
	str[idx] = '\0';
	return (str);
}

