/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:31:36 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/06 00:47:11 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_findchar(char c, char const *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		if (c == str[idx])
			return (1);
		idx++;
	}
	return (0);
}

static	char	*ft_checkfront(char const *s1, char const *set)
{
	size_t	idx;

	idx = 0;
	if (ft_findchar(s1[idx], set))
	{
		idx++;
		while (ft_findchar(s1[idx], set))
			idx++;
		return ((char*)s1 + idx);
	}
	else 
		return ((char*)s1);
}

static	int	ft_checkend(char const *s1, char const *set)
{
	int	idx;
	
	idx = (int)ft_strlen(s1) - 1;
	if (idx < 0)
		return (0);
	if (ft_findchar(s1[idx], set))
	{
		idx--;
		while (ft_findchar(s1[idx], set))
			idx--;
	}	
	return (idx + 1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int	idx;
	int	size;
	char	*str;
	
	s1 = ft_checkfront(s1, set);
	size = ft_checkend(s1, set);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		str[idx] = s1[idx];
		idx++;
	}
	str[idx] = '\0';
	return (str);
}

