/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:41:48 by oroy              #+#    #+#             */
/*   Updated: 2023/06/30 22:13:23 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	else if (!*lst)
	{
		*lst = new;
		(*lst)->prev = *lst;
		(*lst)->next = *lst;
	}
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		new->prev->next = new;
		(*lst)->prev = new;
		*lst = new;
	}
}
