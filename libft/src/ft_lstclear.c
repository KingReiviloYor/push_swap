/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:48:34 by oroy              #+#    #+#             */
/*   Updated: 2023/07/05 11:32:16 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*position;
	t_list	*head;

	if (!lst || !*lst)
		return ;
	head = NULL;
	position = *lst;
	while (position)
	{
		head = position->next;
		position->prev = NULL;
		position->next = NULL;
		free(position);
		position = head;
	}
	*lst = NULL;
}
