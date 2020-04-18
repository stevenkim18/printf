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

char	*findspecifier(const char *s)
{
	int 	i;
	char	*conversion;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-' ||
				s[i] == ' ' || s[i] == '#' || s[i] == '.' || s[i] == '*'))
		i++;
	if (ft_isprint(s[i]))
	{
		conversion = ft_strchr("cspdiuxX%%", s[i]);
		if (conversion)
			return ((char*)s + i);
		else
			return (NULL);
	}
	return (NULL);
}

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

void	classifyconversion(t_struct *f, va_list ap)
{
	if (f->conversion == '%')
		ifpercent(f);
    else if (f->conversion == 'c')
        ifchar(f, ap);
	else if (f->conversion == 's')
		ifstring(f, ap);
	else if (f->conversion == 'i' || f->conversion == 'd')
		ifinteger(f, ap, 0);
	else if (f->conversion == 'u')
		ifinteger(f, ap, 1);
	else if (f->conversion == 'x' || f->conversion == 'X')
		ifhex(f, ap);
	else if (f->conversion == 'p')
		ifpointer(f, ap);
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
