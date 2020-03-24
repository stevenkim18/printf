/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 01:02:26 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/06 02:24:24 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	ft_wordcount(char const *s, char c)
{
	int	idx;
	int	count;

	idx = 0;
	while (s[idx] && s[idx] == c)
		idx++;
	count = 0;
	while (s[idx])
	{
		if (s[idx] == c)
		{
			if(s[idx - 1] != c)
				count++;
		}
		idx++;
	}
	if (s[idx - 1] != c)
		count++;
	return (count + 1);
}

char		*ft_strndup(char const *s, int n)
{
	int	idx;
	char	*ptr;

	idx = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (idx < n)
	{
		ptr[idx] = s[idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}

char		**ft_split(char const *s, char c)
{	
	int	word_idx;
	char	**words;
	char	*ptr;

	if (!(words = (char**)malloc(sizeof(char*) * (ft_wordcount(s, c)))))
		return (NULL);
	while (*s && *s == c)
		s++;
	word_idx = 0;
	ptr = (char*)s;
	while (*s)
	{
		if (*s == c)
		{
			words[word_idx++] = ft_strndup(ptr, s - ptr);
			while (*s == c)
				s++;
			ptr = (char*)s--;
		}
		s++;
	}
	if (ptr != s)
		words[word_idx++] = ft_strndup(ptr, s - ptr);
	words[word_idx] = NULL;
	return (words);
}

