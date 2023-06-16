/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:50:01 by oroy              #+#    #+#             */
/*   Updated: 2023/06/15 12:03:30 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_algo_bck(t_stack **stacks)
{
	size_t	moves;

	moves = 0;
	while ((*stacks)->head_a)
	{
		if ((*stacks)->head_a->next)
		{
			if ((*stacks)->head_a->content > (*stacks)->head_a->next->content)
				sa(stacks);
			else if ((*stacks)->head_a->content > (*stacks)->tail_a->content)
				rra(stacks);
			else
			{
				pb(stacks);
				if ((*stacks)->head_b->next)
				{
					if ((*stacks)->head_b->content < (*stacks)->tail_b->content)
					{
						rb(stacks);
						moves++;
					}
					else if ((*stacks)->head_b->content
						< (*stacks)->head_b->next->content)
					{
						sb(stacks);
						moves++;
					}
				}
			}
		}
		else
		{
			pb(stacks);
			if ((*stacks)->head_b->next)
			{
				if ((*stacks)->head_b->content < (*stacks)->tail_b->content)
				{
					rb(stacks);
					moves++;
				}
				else if ((*stacks)->head_b->content
					< (*stacks)->head_b->next->content)
				{
					sb(stacks);
					moves++;
				}
			}
		}
		moves++;
	}
	while ((*stacks)->head_b)
	{
		if ((*stacks)->head_b->next)
		{
			if ((*stacks)->head_b->content < (*stacks)->head_b->next->content)
				sb(stacks);
			else if ((*stacks)->head_b->content < (*stacks)->tail_b->content)
				rrb(stacks);
			else
			{
				pa(stacks);
				if ((*stacks)->head_a->next)
				{
					if ((*stacks)->head_a->content > (*stacks)->tail_a->content)
					{
						ra(stacks);
						moves++;
					}
					else if ((*stacks)->head_a->content
						> (*stacks)->head_a->next->content)
					{
						sa(stacks);
						moves++;
					}
				}
			}
		}
		else
		{
			pa(stacks);
			if ((*stacks)->head_a->next)
			{
				if ((*stacks)->head_a->content > (*stacks)->tail_a->content)
				{
					ra(stacks);
					moves++;
				}
				else if ((*stacks)->head_a->content
					> (*stacks)->head_a->next->content)
				{
					sa(stacks);
					moves++;
				}
			}
		}
		moves++;
	}
	return (moves);
}
