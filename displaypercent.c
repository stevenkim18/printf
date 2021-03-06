/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaypercent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:03:10 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/30 17:03:21 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	displaypercent(t_struct *f)
{
	if (f->minus)
	{
		ft_putchar_fd('%', 1);
		displaywidth(f);
	}
	else
	{
		if (f->zero)
		{
			displayzero(f, 0);
			ft_putchar_fd('%', 1);
		}
		else
		{
			displaywidth(f);
			ft_putchar_fd('%', 1);
		}
	}
	f->nprinted++;
}

void	ifpercent(t_struct *f, va_list ap)
{
	int	i;

	i = 0;
	while (f->format[i])
	{
		if (f->format[i] == '-' && !(f->minus))
			f->minus = 1;
		else if (f->format[i] == '0' && !(f->zero)
					&& !(f->width) && !(f->minus) && !(f->precision))
			f->zero = 1;
		else if (ft_isdigit(f->format[i]))
			f->width = (f->width) * 10 + (f->format[i] - 48);
		else if (f->format[i] == '*')
			putflaginstar(f, ap);
		i++;
	}
	displaypercent(f);
}
