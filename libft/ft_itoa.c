/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:54:40 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/06 20:50:11 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_numlen(long long int num)
{
	int	count;

	count = 1;
	while (num / 10)
	{
		count++;
		num /= 10;
	}
	return (count);
}

static	char	*ft_revstr(char *str)
{	
	size_t	idx;
	size_t	len;
	char	temp;

	len = ft_strlen(str);
	idx = 0;
	while (idx < len / 2)
	{	
		temp = str[idx];
		str[idx] = str[len - idx - 1];
		str[len - idx - 1] = temp;
		idx++;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		size;
	int		idx;
	char		*str;
	long long int	num;
	
	num = (long long int)n;
	size = ft_numlen(num);
	if (num < 0)
	{
		num = -num;
		size++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	idx = 0;
	while (num / 10 || idx < size)
	{
		str[idx++] = (num % 10) + 48;
		num /= 10;
	}
	str[idx] = '\0';
	str = ft_revstr(str);
	if (str[0] == '0' && idx != 1)
		str[0] = '-';
	return (str);
}

