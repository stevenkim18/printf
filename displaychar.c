/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaychar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:38:35 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/31 17:38:59 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    displaychar(t_struct *f, va_list ap)
{
    if (f->minus)
    {
        ft_putchar_fd(va_arg(ap, int), 1);
        displaywidth(f);
    }
    else
    {
        displaywidth(f);
        ft_putchar_fd(va_arg(ap, int), 1);
    }
    f->nprinted++;
}

void	ifchar(t_struct *f, va_list ap)
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
        else if (ft_isdigit(f->format[i]))
            f->width = (f->width) * 10 + (f->format[i] - 48);
        i++;
    }
    displaychar(f, ap);
}
