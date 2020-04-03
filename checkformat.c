/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:21:24 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/31 16:21:46 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// % 뒤에 오는 문자 찾기 ex) cspdiuxX%
char	*findspecifier(const char *s)
{
	int 	i;
	char	conversion;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-' ||
				s[i] == ' ' || s[i] == '#' || s[i] == '.'))
		i++;
	conversion = *ft_strchr("cspdiuxX%%", s[i]);
	if (conversion)
		return ((char*)s + i);
	else 
		return (NULL);
}

// 구조체 초기화
void	init(t_struct *f, char *format, char conversion)
{
	f->format = format;
	f->conversion = conversion;
	f->nprinted = 0;
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->dot = 0;
	f->precision = 0;
}

//서식자 분류해서 각 함수로 보내기
void	classifyconversion(t_struct *f, va_list ap)
{
	if (f->conversion == '%')
		ifpercent(f);
    else if(f->conversion == 'c')
        ifchar(f, ap);
	else if(f->conversion == 's')
		ifstring(f, ap);
	free(f->format);
}

int		handleformatspecifier(t_struct *f, const char *s, int *i, va_list ap)
{
	char	*tmp;

	tmp = findspecifier(s + *i + 1);
	init(f, ft_strndup((s + *i), (tmp + 1) - (s + *i)), *tmp);
	classifyconversion(f, ap);
	*i = *i + ((tmp) - (s + *i));
	return (f->nprinted);
}

// 문자열에서 % 찾기 
int		checkformat(const char *s, va_list ap)
{
	int 		i;
	int			ret;
	t_struct 	*f;
	
	ret = 0;
	if (!(f = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{	
			if (!findspecifier(s + i + 1))
				i++;
			else if (findspecifier(s + i + 1))
				ret += handleformatspecifier(f, s, &i, ap);
		}
		else
			ret += ft_putchar_fd(s[i], 1);
	}
	free(f);
	return (ret);
}
