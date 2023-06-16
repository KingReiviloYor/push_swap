/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bck2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:50:01 by oroy              #+#    #+#             */
/*   Updated: 2023/06/15 18:28:11 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_algo_bck2(t_stack **stacks)
{
	size_t	moves;
	size_t	r_times;

	r_times = 0;
	moves = 0;
	while ((*stacks)->head_a->next)
	{
		if ((*stacks)->head_a->content > (*stacks)->tail_a->content)
			rra(stacks);
		else if ((*stacks)->head_a->content > (*stacks)->head_a->next->content)
			sa(stacks);
		else
		{
			pb(stacks);
			// if ((*stacks)->head_b->next)
			// {
			// 	if ((*stacks)->head_b->content < (*stacks)->tail_b->content)
			// 	{
			// 		rb(stacks);
			// 		moves++;
			// 	}
			// 	else if ((*stacks)->head_b->content
			// 		< (*stacks)->head_b->next->content)
			// 	{
			// 		if ((*stacks)->head_a->content
			// 			> (*stacks)->head_a->next->content)
			// 			ss(stacks);
			// 		else
			// 			sb(stacks);
			// 		moves++;
			// 	}
			// }
		}
		moves++;		
	}
	while ((*stacks)->head_b)
	{
		if ((*stacks)->head_b->content > (*stacks)->head_a->content)
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
