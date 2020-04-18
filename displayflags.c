/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:54:38 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/31 17:54:51 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handleminusandwidth(t_struct *f, int flag)
{
	if (!(f->minus))
	{
		if (flag < 0)
		{
			f->minus = 1;
			flag = -flag;
		}
	}
	else
	{
		if (flag < 0)
			flag = -flag;
	}
	f->width = flag;
}

void	putflaginstar(t_struct *f, va_list ap)
{
	int	flag;

	flag = va_arg(ap, int);
	if (f->dot)
	{
		if (flag < 0)
		{
			f->dot = 0;
			f->precision = 0;
		}
		else
			f->precision = flag;
		return ;
	}
	handleminusandwidth(f, flag);
}

void	displayzero(t_struct *f, int len)
{   
	int		i;
	int		zerolen;

	i = 0;
	zerolen = 0;
	if ((f->conversion == 'c') || f->conversion == '%')
		zerolen = f->width - 1;
	else if (((f->conversion == 'd') || (f->conversion == 'i')
			|| (f->conversion == 'u')) && (f->width != 0 || f->precision > 0))
		zerolen = f->precision - len;
	else if ((f->conversion == 'x') || (f->conversion == 'X'))
		zerolen = f->precision - len;
	else if ((f->conversion == 'p') && (len != 2))
		zerolen = f->precision - len;
	while (i++ < zerolen)
		ft_putchar_fd('0', 1);
	f->nprinted += zerolen;
}

void	displaywidth(t_struct *f)
{
	int     i;
	int     spacelen;

	i = 0;
	spacelen = 0;
	if (f->width && (f->conversion == 'c' || f->conversion == '%'))
		spacelen = f->width - 1;
	else if (f->width && (f->conversion == 's'))
		spacelen = f->width - f->precision;
	else if (f->width && ((f->conversion == 'd') || (f->conversion == 'i')
							|| (f->conversion = 'u')))
		spacelen = f->width - f->precision;
	else if (f->width && ((f->conversion == 'x') || (f->conversion == 'X')))
		spacelen = f->width - f->precision;
	else if (f->width && (f->conversion == 'p'))
		spacelen = f->width - f->precision;
	while (i++ < spacelen)
		ft_putchar_fd(' ', 1);
	f->nprinted += spacelen;
}
