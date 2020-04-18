/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaypointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 15:53:09 by seunkim           #+#    #+#             */
/*   Updated: 2020/04/16 15:53:12 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    editflagspointer(t_struct *f, int *hexlen)
{
	if (f->dot)
	{
		if (f->precision == 0)
			*hexlen = 2;
		if (f->precision <= *hexlen)
			f->precision = *hexlen;
		else 
			f->precision += 2;
	}
	if (f->width > 0)
	{
		if (f->precision == 0)
			f->precision = *hexlen;
		if (f->width < f->precision)
			f->width = f->precision;
		if (f->zero && !(f->dot))
			f->precision = f->width;
	}
}

void    displaypointer(t_struct *f, va_list ap)
{
	long long   ptr;
	int         ptrlen;

	ptr = (long long)va_arg(ap, char *);
	ptrlen = (gethexlen(ptr) + 2);
	editflagspointer(f, &ptrlen);
	if (f->minus)
	{
		ft_putstr_fd("0x", 1);
		if (f->zero || f->dot)
			displayzero(f, ptrlen);
		if (!(f->dot && f->precision == 2))
			ft_puthex(ptr, 0);
		displaywidth(f);
	}
	else
	{   
		displaywidth(f);
		ft_putstr_fd("0x", 1);
		if (f->zero || f->dot)
			displayzero(f, ptrlen);
		if (!(f->dot && f->precision == 2))
			ft_puthex(ptr, 0);
	}
	f->nprinted += ptrlen;
}

void    ifpointer(t_struct *f, va_list ap)
{
	int     i;

	i = 0;
	while (f->format[i])
	{
		if (f->format[i] == '-' && !(f->minus))
			f->minus = 1;
		else if (f->format[i] == '0' && !(f->zero)
					&& !(f->width) && !(f->minus))
			f->zero = 1;
		else if (ft_isdigit(f->format[i]) && !(f->dot))
			f->width = (f->width) * 10 + (f->format[i] - 48);
		else if (f->format[i] == '.' && !(f->dot))
			f->dot = 1;
		else if (ft_isdigit(f->format[i]) && (f->dot))
			f->precision = (f->precision) * 10 + (f->format[i] - 48);
		i++;
	}
	displaypointer(f, ap);
}
