/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 15:07:00 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/26 16:52:08 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 제출 함수 ft_printf
int	ft_printf(const char *s, ...)
{	
	va_list	ap;
	int		ret;
	
	va_start(ap, s);
	ret = checkformat(s/*, ap*/);
	va_end(ap);
	return (ret);
}
