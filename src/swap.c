/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:35:58 by oroy              #+#    #+#             */
/*   Updated: 2023/06/28 19:53:11 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list **head)
{
	if (*head && (*head)->next != *head)
	{
		if ((*head)->next->next == *head)
			*head = (*head)->next;
		else
		{
			*head = (*head)->next;
			(*head)->prev->next = (*head)->next;
			(*head)->next = (*head)->prev;
			(*head)->prev = (*head)->prev->prev;
			(*head)->next->prev = *head;
			(*head)->prev->next = *head;
			(*head)->next->next->prev = (*head)->next;
		}
	}
}

void	sa(t_stack **stacks)
{
	swap(&(*stacks)->head_a);
	ft_printf ("%s\n", "sa");
}

void	sb(t_stack **stacks)
{
	swap(&(*stacks)->head_b);
	ft_printf ("%s\n", "sb");
}

void	ss(t_stack **stacks)
{
	swap(&(*stacks)->head_a);
	swap(&(*stacks)->head_b);
	ft_printf ("%s\n", "ss");
}
