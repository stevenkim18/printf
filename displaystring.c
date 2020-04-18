/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaystring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:00:28 by seunkim           #+#    #+#             */
/*   Updated: 2020/04/01 17:00:44 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char* str, int n)
{
	int     i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	editflags(t_struct *f, int strlen)
{
	if (!(f->dot))
	{
		if (f->width < strlen)
			f->width = strlen;
		f->precision = strlen;
	}
	else
	{
		if (f->precision >= strlen)
		{
			f->precision = strlen;
			if (f->width < strlen)
				f->width = strlen;
		}
	}
}

void	displaystring(t_struct *f, va_list ap)
{
	char	*str;

	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	editflags(f, ft_strlen(str));
	if (f->minus)
	{
		ft_putnstr(str, f->precision);
		displaywidth(f);
	}
	else
	{
		displaywidth(f);
		ft_putnstr(str, f->precision);
	}
	f->nprinted += f->precision;
}

void	ifstring(t_struct *f, va_list ap)
{
	int	i;

	i = 0;
	while (f->format[i])
	{
		if (f->format[i] == '-' && !(f->minus))
		{
			if (f->zero)
				f->zero = 0;
			f->minus = 1;
		}
		else if (f->format[i] == '0' && !(f->zero)
					&& !(f->width) && !(f->minus))
			f->zero = 1;
		else if (ft_isdigit(f->format[i]) && !(f->dot))
			f->width = (f->width) * 10 + (f->format[i] - 48);
		else if (f->format[i] == '.' && !(f->dot))
			f->dot = 1;
		else if (ft_isdigit(f->format[i]) && (f->dot))
			f->precision = (f->precision) * 10 + (f->format[i] - 48);
		else if (f->format[i] == '*')
			putflaginstar(f, ap);
		i++;
	}
	displaystring(f, ap);
}
