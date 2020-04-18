/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayinteger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:18:32 by seunkim           #+#    #+#             */
/*   Updated: 2020/04/14 17:18:51 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		getintlen(long long num)
{
	int		count;

	count = 1;
	while (num /= 10)
		count++;
	return (count);
}

void	editflagsinteger(t_struct *f, long long num, int numlen)
{
	if (f->dot)
	{
		if (f->precision == 0)
			return ;
		if (f->precision <= numlen)
			f->precision = numlen;
		else if (f->precision < 0)
			f->precision = 1;
	}
	if (f->width > 0)
	{
		if (num < 0)
			f->width--;
		if (f->precision == 0)
			f->precision = numlen;
		if (f->width < f->precision)
			f->width = f->precision;
		if (f->zero && !(f->dot))
			f->precision = f->width;
		if (f->zero && f->minus)
			f->zero = 0;
	}
}

void	displayzerointeger(t_struct *f, long long num)
{
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
		f->nprinted++;
	}
	if (f->zero || f->dot)
		displayzero(f, getintlen(num));
	if (!(f->dot && f->precision == 0))
		ft_putnbr_fd(num, 1);
}

void	displayinteger(t_struct *f, va_list ap, int isunsigned)
{
	long long	num;

	if (isunsigned)
		num = (long long)va_arg(ap, unsigned int);
	else 
		num = va_arg(ap, int);
	editflagsinteger(f, num, getintlen(num));
	if (f->minus)
	{
		displayzerointeger(f, num);
		displaywidth(f);
	}
	else
	{
		displaywidth(f);
		displayzerointeger(f, num);
	}
	if (!(f->width == 0 && f->dot && f->precision == 0))
		f->nprinted += getintlen(num);
}

void	ifinteger(t_struct *f, va_list ap, int isunsigned)
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
	displayinteger(f, ap, isunsigned);
}
