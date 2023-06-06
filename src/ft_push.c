/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:58:19 by oroy              #+#    #+#             */
/*   Updated: 2023/06/06 19:40:39 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **stack1, t_stack **stack2)
{
	t_list	*save;

	if ((*stack2)->head)
	{
		save = ((*stack2)->head)->next;
		ft_lstadd_front(&(*stack1)->head, (*stack2)->head);
		if (!(*stack1)->tail)
			(*stack1)->tail = (*stack1)->head;
		(*stack2)->head = save;
		if ((*stack2)->head)
			((*stack2)->head)->previous = NULL;
		else
			(*stack2)->tail = NULL;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf ("%s\n", "pa");
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_printf ("%s\n", "pb");
}
