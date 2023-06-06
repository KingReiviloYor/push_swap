/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:58:28 by oroy              #+#    #+#             */
/*   Updated: 2023/06/06 17:00:42 by oroy             ###   ########.fr       */
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

void	rra(t_stack **stack_a)
{
	rrotate(&(*stack_a)->head, &(*stack_a)->tail);
	ft_printf ("%s\n", "rra");
}

void	rrb(t_stack **stack_b)
{
	rrotate(&(*stack_b)->head, &(*stack_b)->tail);
	ft_printf ("%s\n", "rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrotate(&(*stack_a)->head, &(*stack_a)->tail);
	rrotate(&(*stack_b)->head, &(*stack_b)->tail);
	ft_printf ("%s\n", "rrr");
}
