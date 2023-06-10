/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:58:25 by oroy              #+#    #+#             */
/*   Updated: 2023/06/08 11:12:32 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **head, t_list **tail)
{
	if (*head && (*head)->next)
	{
		(*head)->previous = *tail;
		(*tail)->next = *head;
		*head = (*head)->next;
		(*head)->previous = NULL;
		*tail = (*tail)->next;
		(*tail)->next = NULL;
	}
}

void	ra(t_stack **stacks)
{
	rotate(&(*stacks)->head_a, &(*stacks)->tail_a);
	ft_printf ("%s\n", "ra");
}

void	rb(t_stack **stacks)
{
	rotate(&(*stacks)->head_b, &(*stacks)->tail_b);
	ft_printf ("%s\n", "rb");
}

void	rr(t_stack **stacks)
{
	rotate(&(*stacks)->head_a, &(*stacks)->tail_a);
	rotate(&(*stacks)->head_b, &(*stacks)->tail_b);
	ft_printf ("%s\n", "rr");
}
