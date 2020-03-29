/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 15:01:53 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/24 17:10:16 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

# include <stdio.h>
# include <stdarg.h>

typedef struct s_struct
{
    char    *format;

    int     minus;
    int     zero;

    int     width;
    int     dot;
    int     precision;
}               t_struct;

int	ft_printf(const char *s, ...);

#endif