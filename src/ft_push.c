/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:58:19 by oroy              #+#    #+#             */
/*   Updated: 2023/06/08 11:16:44 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_list **head1, t_list **head2, t_list **tail1, t_list **tail2)
{
	t_list	*save;

	if (*head2)
	{
		save = (*head2)->next;
		ft_lstadd_front(&*head1, *head2);
		if (!*tail1)
			*tail1 = *head1;
		*head2 = save;
		if (*head2)
			(*head2)->previous = NULL;
		else
			*tail2 = NULL;
	}
}

void	pa(t_stack **stacks)
{
	push(&(*stacks)->head_a, &(*stacks)->head_b,
		&(*stacks)->tail_a, &(*stacks)->tail_b);
	ft_printf ("%s\n", "pa");
}

void	pb(t_stack **stacks)
{
	push(&(*stacks)->head_b, &(*stacks)->head_a,
		&(*stacks)->tail_b, &(*stacks)->tail_a);
	ft_printf ("%s\n", "pb");
}
