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

#include "ft_printf.h"

// % 뒤에 오는 문자 찾기 ex) cspdiuxX%
char	*findspecifier(const char *s)
{
	int i;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-' ||
				s[i] == ' ' || s[i] == '#' || s[i] == '.'))
		i++;
	if (ft_strchr("cspdiuxX%", s[i]))
		return (s + i);
	else 
		return (NULL);
}
// 구조체 초기화
void	init(t_struct *f, char *format)
{
	f->format = format;
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->dot = 0;
	f->precision = 0;
}

// 문자열에서 % 찾기 
void	checkformat(const char *s, va_list ap)
{
	int 		i;
	char		*tmp;
	t_struct 	*f;

	if (!(f = (t_struct*)malloc(sizeof(t_struct))))
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (!(tmp = findspecifier(s + i + 1)))
				i++;
			else
			{
				init(f, ft_strndup((s + i), (tmp + 1) - (s + i)));
				// 여기에 분류 하는 함수 넣기 (인자 f, *tmp, ap)
				i = i + (tmp + 1) - (s + i);
			}
		}
		else
			write (1, &s[i], 1);
		i++;
	}
}

// 제출 함수 ft_printf
int	ft_printf(const char *s, ...)
{	
	va_list	ap;
	
	va_start(ap, s);
	checkformat(s, ap);
	va_end(ap);
	return (0);
}
