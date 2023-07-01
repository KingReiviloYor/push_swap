/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:58:19 by oroy              #+#    #+#             */
/*   Updated: 2023/06/28 19:48:46 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_list **head1, t_list **head2)
{
	t_list	*save;

	save = NULL;
	if (*head2)
	{
		if ((*head2)->next != *head2)
		{
			save = (*head2)->next;
			save->prev = (*head2)->prev;
			save->prev->next = save;
		}
		ft_lstadd_front(&*head1, *head2);
		*head2 = save;
	}
}

void	pa(t_stack **stacks)
{
	push(&(*stacks)->head_a, &(*stacks)->head_b);
	ft_printf ("%s\n", "pa");
}

void	pb(t_stack **stacks)
{
	push(&(*stacks)->head_b, &(*stacks)->head_a);
	ft_printf ("%s\n", "pb");
}
