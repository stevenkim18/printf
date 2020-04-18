/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gethexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 11:07:35 by seunkim           #+#    #+#             */
/*   Updated: 2020/04/18 11:07:37 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		gethexlen(long long num)
{
	int		count;

	count = 1;
	while (num /= 16)
		count++;
	return (count);
}
