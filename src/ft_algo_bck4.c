/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bck4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:50:01 by oroy              #+#    #+#             */
/*   Updated: 2023/06/28 16:57:56 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static void	b_to_a(t_stack **stacks)
// {
// 	size_t	r_times;

// 	r_times = 0;
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

// static void	a_to_b(t_stack **stacks, int chunks_nbr, size_t nodes_nbr, int min, int max)
// {
// 	size_t	min_n;
// 	size_t	max_n;

// 	min_n = nodes_nbr;
// 	max_n = nodes_nbr;
// 	while ((*stacks)->head_a)
// 	{
// 		if (!min_n && min > 0)
// 		{
// 			min--;
// 			min_n = nodes_nbr;
// 		}
// 		else if (!max_n && max <= chunks_nbr)
// 		{
// 			max++;
// 			max_n = nodes_nbr;
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
// }

// static void	a_to_b(t_stack **stacks, int min, int max)
// {
// 	pb(stacks);
// 	if ((*stacks)->head_b->next != (*stacks)->head_b)
// 	{
// 		if ((*stacks)->head_a && (*stacks)->head_a->chunk != max
// 			&& (*stacks)->head_a->chunk != min)
// 			rr(stacks);
// 		else
// 			rb(stacks);
// 	}
// }

// static size_t	update_min_max(int min_max, size_t nodes_nbr)
// {
// 	(void) min_max;
// 	return (nodes_nbr);
// }

// void	ft_algo(t_stack **stacks, int chunks_nbr, size_t nodes_nbr)
// {
// 	int		max;
// 	int		min;
// 	size_t	min_n;
// 	size_t	max_n;

// 	min_n = nodes_nbr;
// 	max_n = nodes_nbr;
// 	min = chunks_nbr / 2;
// 	max = min + 1;
// 	while ((*stacks)->head_a)
// 	{
// 		if (!min_n && min > 0)
// 			min_n = update_min_max(--min, nodes_nbr);
// 		else if (!max_n && max <= chunks_nbr)
// 			max_n = update_min_max(++max, nodes_nbr);
// 		while ((*stacks)->head_a->chunk != max
// 			&& (*stacks)->head_a->chunk != min)
// 			ra(stacks);
// 		if ((*stacks)->head_a->chunk == max)
// 			max_n--;
// 		else
// 			min_n--;
// 		a_to_b(stacks, min, max);
// 	}
// 	b_to_a(stacks);
// }
