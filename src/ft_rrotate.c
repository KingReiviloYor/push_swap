/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:58:28 by oroy              #+#    #+#             */
/*   Updated: 2023/06/08 11:16:23 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rrotate(t_list **head, t_list **tail)
{
	if (*head && (*head)->next)
	{
		(*tail)->next = *head;
		(*head)->previous = *tail;
		*head = *tail;
		*tail = (*tail)->previous;
		(*tail)->next = NULL;
		(*head)->previous = NULL;
	}
}

void	rra(t_stack **stacks)
{
	rrotate(&(*stacks)->head_a, &(*stacks)->tail_a);
	ft_printf ("%s\n", "rra");
}

void	rrb(t_stack **stacks)
{
	rrotate(&(*stacks)->head_b, &(*stacks)->tail_b);
	ft_printf ("%s\n", "rrb");
}

void	rrr(t_stack **stacks)
{
	rrotate(&(*stacks)->head_a, &(*stacks)->tail_a);
	rrotate(&(*stacks)->head_b, &(*stacks)->tail_b);
	ft_printf ("%s\n", "rrr");
}
