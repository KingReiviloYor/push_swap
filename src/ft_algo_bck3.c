/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bck3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:50:01 by oroy              #+#    #+#             */
/*   Updated: 2023/06/16 14:51:50 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_algo_bck3(t_stack **stacks, int chunks_num)
{
	size_t	moves;
	size_t	r_times;

	r_times = 0;
	moves = 0;
	while ((*stacks)->head_a)
	{
		if ((*stacks)->head_b && (*stacks)->head_b->next)
		{
			while (((*stacks)->head_b->chunk > (*stacks)->head_a->chunk
				|| (*stacks)->tail_b->chunk < (*stacks)->head_a->chunk)
				&& ((*stacks)->tail_b->chunk - (*stacks)->head_a->chunk != 1
				&& (*stacks)->head_a->chunk - (*stacks)->head_b->chunk != 1)
				&& (!((*stacks)->head_a->chunk >= (*stacks)->head_b->chunk)
				&& !((*stacks)->tail_b->chunk < (*stacks)->head_b->chunk)))
			{
				if (ft_abs((*stacks)->head_a->chunk - (*stacks)->head_b->chunk)
					< ft_abs((*stacks)->head_a->chunk - (*stacks)->tail_b->chunk))
					rb(stacks);
				else
					rrb(stacks);
				moves++;
			}
		}
		pb(stacks);
		moves++;
	}
	while ((*stacks)->tail_b->chunk != 1 && (*stacks)->head_b->chunk != chunks_num)
	{
		if ((*stacks)->head_b->chunk - 1 > (*stacks)->tail_b->chunk - 1)
			rb(stacks);
		else
			rrb(stacks);
	}
	while ((*stacks)->head_b)
	{
		if ((*stacks)->head_a && (*stacks)->head_b->content > (*stacks)->head_a->content)
		{
			while ((*stacks)->head_b->content > (*stacks)->head_a->content)
			{
				ra(stacks);
				moves++;
				r_times++;
			}
			while ((*stacks)->head_b
				&& (*stacks)->head_b->content < (*stacks)->head_a->content
				&& (*stacks)->head_b->content > (*stacks)->tail_a->content)
			{
				pa(stacks);
				moves++;
			}
			while (r_times)
			{
				rra(stacks);
				r_times--;
				moves++;
			}
		}
		else
		{
			pa(stacks);
			moves++;
		}
	}
	return (moves);
}
