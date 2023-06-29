/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:54:33 by oroy              #+#    #+#             */
/*   Updated: 2023/06/28 19:04:36 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	b_to_a_more(t_stack **stacks)
{
	size_t	r_times;

	r_times = 0;
	while ((*stacks)->head_a->content < (*stacks)->head_b->content)
	{
		ra(stacks);
		r_times++;
	}
	while ((*stacks)->head_b
		&& (*stacks)->head_b->content < (*stacks)->head_a->content
		&& (*stacks)->head_b->content > (*stacks)->head_a->prev->content)
		pa(stacks);
	while (r_times)
	{
		rra(stacks);
		r_times--;
	}
}

void	b_to_a(t_stack **stacks)
{
	if (!(*stacks)->head_a)
		pa(stacks);
	while ((*stacks)->head_b)
	{
		if ((*stacks)->head_b->content < (*stacks)->head_a->content)
			pa(stacks);
		else if ((*stacks)->head_b->content > (*stacks)->head_a->prev->content)
		{
			pa(stacks);
			ra(stacks);
		}
		else
			b_to_a_more(stacks);
	}
}
