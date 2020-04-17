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

int		gethexlen1(long long num)
{
	int		count;

	count = 1;
	while (num /= 16)
		count++;
	return (count);
}

void	ft_puthex1(long long num, int isupcase)
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
		ft_puthex1(num / 16, isupcase);
		ft_puthex1(num % 16, isupcase);
	}
	else
    {   
        if (isupcase)
		    write(1, &hexup[num], 1);
        else
            write(1, &hexlow[num], 1);
    }
}
void    editflagspointer(t_struct *f, int *hexlen)
{
    if (f->dot)
    {
        if (f->precision == 0)
            *hexlen = 2;
        if (f->precision <= *hexlen)
            f->precision = *hexlen;
        // 2.9p / .5p 일때
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
    ptrlen = (gethexlen1(ptr) + 2);
    editflagspointer(f, &ptrlen);
    if (f->minus)
    {
        ft_putstr_fd("0x", 1);
        if (f->zero || f->dot)
            displayzero(f, ptrlen);
        if (!(f->dot && f->precision == 2))
            ft_puthex1(ptr, 0);
        displaywidth(f);
    }
    else
    {   
        displaywidth(f);
        ft_putstr_fd("0x", 1);
        if (f->zero || f->dot)
            displayzero(f, ptrlen);
        if (!(f->dot && f->precision == 2))
            ft_puthex1(ptr, 0);
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
