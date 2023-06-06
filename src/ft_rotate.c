/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:58:25 by oroy              #+#    #+#             */
/*   Updated: 2023/06/06 19:27:37 by oroy             ###   ########.fr       */
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

void	ra(t_stack **stack_a)
{
	rotate(&(*stack_a)->head, &(*stack_a)->tail);
	ft_printf ("%s\n", "ra");
}

void	rb(t_stack **stack_b)
{
	rotate(&(*stack_b)->head, &(*stack_b)->tail);
	ft_printf ("%s\n", "rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(&(*stack_a)->head, &(*stack_a)->tail);
	rotate(&(*stack_b)->head, &(*stack_b)->tail);
	ft_printf ("%s\n", "rr");
}
