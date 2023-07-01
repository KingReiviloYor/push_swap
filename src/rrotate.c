/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:58:28 by oroy              #+#    #+#             */
/*   Updated: 2023/06/28 10:04:51 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rrotate(t_list **head)
{
	if (*head && (*head)->next != *head)
		*head = (*head)->prev;
}

void	rra(t_stack **stacks)
{
	rrotate(&(*stacks)->head_a);
	ft_printf ("%s\n", "rra");
}

void	rrb(t_stack **stacks)
{
	rrotate(&(*stacks)->head_b);
	ft_printf ("%s\n", "rrb");
}

void	rrr(t_stack **stacks)
{
	rrotate(&(*stacks)->head_a);
	rrotate(&(*stacks)->head_b);
	ft_printf ("%s\n", "rrr");
}
