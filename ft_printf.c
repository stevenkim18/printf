/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 15:07:00 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/26 16:52:08 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*findformat(const char *s)
{
	int i;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-' ||
				s[i] == ' ' || s[i] == '#' || s[i] == '.'))
	{

		i++;
	}
	return ();
}

void	checkformat(const char *s, va_list ap)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			
		}
		i++;
	}
}

/* 
** main function
 */

int	ft_printf(const char *s, ...)
{	
	va_list	ap;
	
	va_start(ap, s);
	checkformat(s, ap);
	va_end(ap);
	return (0);
}
