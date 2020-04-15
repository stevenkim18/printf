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

int		gethexlen(long long num)
{
	int		count;

	count = 1;
	while (num /= 16)
		count++;
	return (count);
}

void	ft_puthex(long long num, int isupcase)
{	
    char *hexup;
    char *hexlow;
    hexup = "0123456789ABCDEF";
    hexlow = "0123456789abcdef";
	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
	}
	if (num >= 16)
	{
		ft_puthex(num / 16, isupcase);
		ft_puthex(num % 16, isupcase);
	}
	else
    {   
        if (isupcase)
		    write(1, &hexup[num], 1);
        else
            write(1, &hexlow[num], 1);
    }
}

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

    num = va_arg(ap, unsigned int);
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
        else if (f->format[i] == '0' && !(f->zero) && !(f->width))
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