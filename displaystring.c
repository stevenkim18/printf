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

void    ft_putnstr(char* str, int n)
{
    int     i;

    i = 0;
    while (i < n)
    {
        ft_putchar_fd(str[i], 1);
        i++;
    }
}

// 문자열 길이 맞게 width presicion 수정
void    editflags(t_struct *f, int strlen)
{   
    // width 만 있을 때
    if (!(f->dot))
    {
        // width가 strlen 보다 작을 때
        if (f->width < strlen)
            f->width = strlen;
        f->precision = strlen;
    }
    // width 와 precision 이 같이 있을 때
    else
    {   
        /*/ width가 strlen보다 작을 때
        if (f->width < strlen)
        {   
            // ("%8.13s", "HelloWorld")
            if (f->precision >= strlen)
            {
                f->width = strlen;
                f->precision = strlen;
            }
            // ("%8.5s", "HelloWorld")
        }
        // width가 strlen 보다 클때 
        else
        {
            // ("%13.11s", "HelloWorld")
            if (f->precision >= strlen)
                f->precision = strlen;
            // ("%13.8s", "HelloWorld")
        }*/
        if (f->precision >= strlen)
        {
            f->precision = strlen;
            if (f->width < strlen)
                f->width = strlen;
        }
    }
}

void    displaystring(t_struct *f, va_list ap)
{   
    char    *str;

    // 이거 안해주면 segfalut 뜸. NULL 처리
    if (!(str = va_arg(ap, char *)))
        str = "(null)";
    // str = va_arg(ap, char *);
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

void    ifstring(t_struct *f, va_list ap)
{
    int     i;

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
    displaystring(f, ap);
}
