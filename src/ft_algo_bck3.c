/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bck3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:50:01 by oroy              #+#    #+#             */
/*   Updated: 2023/06/28 11:06:42 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	ft_algo(t_stack **stacks, int chunks_num, size_t chunk_size)
// {
// 	size_t	r_times;
// 	int		max;
// 	int		min;
// 	int		up_down;
// 	size_t	min_n;
// 	size_t	max_n;

// 	r_times = 0;
// 	up_down = 1;
// 	min = chunks_num / 2;
// 	max = min + 1;
// 	min_n = chunk_size;
// 	max_n = chunk_size;
// 	while ((*stacks)->head_a)
// 	{
// 		if (!min_n && min > 0)
// 		{
// 			min--;
// 			min_n = chunk_size;
// 		}
// 		else if (!max_n && max <= chunks_num)
// 		{
// 			max++;
// 			max_n = chunk_size;
// 		}
// 		while ((*stacks)->head_a->chunk != max
// 			&& (*stacks)->head_a->chunk != min)
// 			ra(stacks);
// 		if ((*stacks)->head_a->chunk == max)
// 		{
// 			pb(stacks);
// 			max_n--;
// 		}
// 		else
// 		{
// 			pb(stacks);
// 			if ((*stacks)->head_b->next != (*stacks)->head_b)
// 			{
// 				if ((*stacks)->head_a && (*stacks)->head_a->chunk != max
// 					&& (*stacks)->head_a->chunk != min)
// 					rr(stacks);
// 				else
// 					rb(stacks);
// 			}
// 			min_n--;
// 		}
// 	}
// 	pa(stacks);
// 	while ((*stacks)->head_b)
// 	{
// 		if ((*stacks)->head_b->content < (*stacks)->head_a->content)
// 			pa(stacks);
// 		else if ((*stacks)->head_b->content > (*stacks)->head_a->prev->content)
// 		{
// 			pa(stacks);
// 			ra(stacks);
// 		}
// 		else
// 		{
// 			while ((*stacks)->head_a->content < (*stacks)->head_b->content)
// 			{
// 				ra(stacks);
// 				r_times++;
// 			}
// 			while ((*stacks)->head_b && (*stacks)->head_b->content < (*stacks)->head_a->content
// 				&& (*stacks)->head_b->content > (*stacks)->head_a->prev->content)
// 				pa(stacks);
// 			while (r_times)
// 			{
// 				rra(stacks);
// 				r_times--;
// 			}
// 		}
// 	}
// }
