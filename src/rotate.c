/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:58:25 by oroy              #+#    #+#             */
/*   Updated: 2023/06/26 15:47:56 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **head)
{
	if (*head && (*head)->next != *head)
		*head = (*head)->next;
}

void	ra(t_stack **stacks)
{
	rotate(&(*stacks)->head_a);
	ft_printf ("%s\n", "ra");
}

void	rb(t_stack **stacks)
{
	rotate(&(*stacks)->head_b);
	ft_printf ("%s\n", "rb");
}

void	rr(t_stack **stacks)
{
	rotate(&(*stacks)->head_a);
	rotate(&(*stacks)->head_b);
	ft_printf ("%s\n", "rr");
}
