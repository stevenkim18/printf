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

void    ifpercent(t_struct *f)
{
    int     i;

    i = 0;
    while(f->format[i])
    {   
        // - flag
        if (f->format[i] == '-' && !(f->minus))
            f->minus++;
        // 0 flag
        else if(f->format[i] == '0' && !(f->minus))
            f->zero++;
        // width
        else if(ft_isdigit(f->format[i]))
            f->width = (f->width) * 10 + (ft_atoi(f->format[i]));
        i++;
    }
    displaypercent(f);
}

void    displayzero(t_struct *f)
{
    int     i;
    int     zerolen;

    i = 0;
    if (f->conversion == 'c' || f->conversion == '%')
        zerolen = f->width - 1;
    // print space
    while (i++ < zerolen)
        write(1, "0", 1);
    // add nprinted by space len
        f->nprinted += zerolen;
}

void    displaywidth(t_struct *f)
{
    int     i;
    int     spacelen;

    i = 0;
    if (f->conversion == 'c' || f->conversion == '%')
        spacelen = f->width - 1;
    // print space
    while (i++ < spacelen)
        write(1, " ", 1);
    // add nprinted by space len
        f->nprinted += spacelen;
}

void    displaypercent(t_struct *f)
{
    if (f->minus)
    {
        displaywidth(f);
        write(1, "%%", 1);
    }
    else
    {
        if (f->zero)
        {
            displayzero(f);
            write(1, "%%", 1);
        }
        else 
        {
            write(1, "%%", 1);
            displaywidth(f);
        }
    }
    f->nprinted++;
}
