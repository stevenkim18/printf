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

typedef struct	s_struct
{
	char		*format;

	char		conversion;

	int			nprinted;

	int			minus;
	int			zero;

	int			width;
	int			dot;
	int			precision;
}				t_struct;

int				ft_printf(const char *s, ...);
int				checkformat(const char *s, va_list ap);

void			ifpercent(t_struct *f, va_list ap);
void			ifchar(t_struct *f, va_list ap);
void			ifstring(t_struct *f, va_list ap);
void			ifinteger(t_struct *f, va_list ap, int isunsigned);
void			ifhex(t_struct *f, va_list ap);
void			ifpointer(t_struct *f, va_list ap);

void			displayzero(t_struct *f, int num);
void			displaywidth(t_struct *f);
void			putflaginstar(t_struct *f, va_list ap);

#endif
