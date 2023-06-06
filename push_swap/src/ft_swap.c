/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:35:58 by oroy              #+#    #+#             */
/*   Updated: 2023/06/06 19:39:39 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list **head, t_list **tail)
{
	if (*head && (*head)->next)
	{
		*head = (*head)->next;
		(*head)->previous->next = (*head)->next;
		(*head)->next = (*head)->previous;
		(*head)->previous = NULL;
		(*head)->next->previous = *head;
		if ((*head)->next->next)
			(*head)->next->next->previous = (*head)->next;
		else
			*tail = (*head)->next;
	}
}

void	sa(t_stack **stack_a)
{
	swap(&(*stack_a)->head, &(*stack_a)->tail);
	ft_printf ("%s\n", "sa");
}

void	sb(t_stack **stack_b)
{
	swap(&(*stack_b)->head, &(*stack_b)->tail);
	ft_printf ("%s\n", "sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(&(*stack_a)->head, &(*stack_a)->tail);
	swap(&(*stack_b)->head, &(*stack_b)->tail);
	ft_printf ("%s\n", "ss");
}
