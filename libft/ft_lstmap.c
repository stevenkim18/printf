/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:25:28 by seunkim           #+#    #+#             */
/*   Updated: 2020/03/08 04:31:00 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{	
	t_list	*new_lst;
	t_list	*begin_lst;
	
	begin_lst = NULL;
	while (lst)
	{
		if (!(new_lst = ft_lstnew(f(lst->content))))
			ft_lstclear(&begin_lst, del);
		ft_lstadd_back(&begin_lst, new_lst);
		lst = lst->next;
	}
	return (begin_lst);
}
