/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bck4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:50:01 by oroy              #+#    #+#             */
/*   Updated: 2023/06/20 18:16:28 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_isinner(t_stack *stacks, int sub)
{
	if ((sub < 0 && stacks->head_a->chunk > stacks->head_b->chunk
		&& stacks->head_a->chunk < stacks->tail_b->chunk)
		|| (sub > 0 && stacks->head_a->chunk < stacks->head_b->chunk
		&& stacks->head_a->chunk > stacks->tail_b->chunk))
		return (1);
	else
		return (0);
}

size_t	ft_algo_bck4(t_stack **stacks, int chunks_num)
{
	size_t	moves;
	size_t	r_times;
	int		sub;

	moves = 0;
	r_times = 0;
	sub = 0;
	while ((*stacks)->head_a)
	{
		if ((*stacks)->head_b && (*stacks)->head_b->next)
		{
			while ((*stacks)->head_a->chunk != (*stacks)->head_b->chunk
				&& (*stacks)->head_a->chunk != (*stacks)->tail_b->chunk)
			{
				sub = (*stacks)->head_b->chunk - (*stacks)->tail_b->chunk;
				if ((*stacks)->head_b->chunk == (*stacks)->tail_b->chunk
					&& (*stacks)->head_a->chunk < (*stacks)->head_b->chunk)
					rb(stacks);
				else if ((*stacks)->head_b->chunk == (*stacks)->tail_b->chunk
					&& (*stacks)->head_a->chunk > (*stacks)->head_b->chunk)
					rrb(stacks);
				else if ((ft_isinner(*stacks, sub) && sub < 0)
					|| (!ft_isinner(*stacks, sub) && sub > 0))
					break ;
				else
				{
					if (ft_abs((*stacks)->head_a->chunk - (*stacks)->head_b->chunk)
						< ft_abs((*stacks)->head_a->chunk - (*stacks)->tail_b->chunk))
						rb(stacks);
					else
						rrb(stacks);
				}
				moves++;
			}
		}
		pb(stacks);
		moves++;
	}
	while ((*stacks)->tail_b->chunk != 1 || (*stacks)->head_b->chunk != chunks_num)
	{
		if ((*stacks)->head_b->chunk - 1 > (*stacks)->tail_b->chunk - 1)
			rb(stacks);
		else
			rrb(stacks);
	}
	while ((*stacks)->head_b)
	{
		if ((*stacks)->head_a && (*stacks)->head_a->next
			&& (*stacks)->head_a->next == (*stacks)->tail_a
			&& (*stacks)->head_a->content > (*stacks)->tail_a->content)
			sa(stacks);
		else if ((*stacks)->head_a && (*stacks)->head_a->next
			&& (*stacks)->head_b->content > (*stacks)->head_a->content)
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
