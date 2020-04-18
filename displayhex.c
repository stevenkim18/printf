/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 03:18:54 by seunkim           #+#    #+#             */
/*   Updated: 2020/04/16 03:19:09 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    editflagshex(t_struct *f, int hexlen)
{
    if (f->dot)
    {
        if (f->precision == 0)
            return ;
        if (f->precision <= hexlen)
            f->precision = hexlen;
    }
    if (f->width > 0)
    {
        if (f->precision == 0)
            f->precision = hexlen;
        if (f->width < f->precision)
            f->width = f->precision;
        if (f->zero && !(f->dot))
            f->precision = f->width;
    }
}

void    displayhex(t_struct *f, va_list ap, int isupcase)
{   
    long long num;

    num = (long long)va_arg(ap, char *);
    if (!num)
        num = 0;
    editflagshex(f, gethexlen(num));
    if (f->minus)
    {   
        if (f->zero || f->dot)
            displayzero(f, gethexlen(num));
        if (!(f->dot && f->precision == 0))
            ft_puthex(num, isupcase);
        displaywidth(f);
    }
    else
    {
        displaywidth(f);
        if (f->zero || f->dot)
            displayzero(f, gethexlen(num));
        if (!(f->dot && f->precision == 0))
            ft_puthex(num, isupcase);
    }
    f->nprinted += gethexlen(num);
}

void    ifhex(t_struct *f, va_list ap)
{
    int     i;
    int     isupcase;

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
    isupcase = (f->conversion == 'X')? 1 : 0;
    displayhex(f, ap, isupcase);
}