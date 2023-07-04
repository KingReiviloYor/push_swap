/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:50:01 by oroy              #+#    #+#             */
/*   Updated: 2023/07/04 17:11:14 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static size_t	update_min_max(size_t min_max, size_t nodes_nbr)
{
	(void) min_max;
	return (nodes_nbr);
}

void	algo(t_stack **stacks, size_t chunks_nbr, size_t nodes_nbr)
{
	size_t	max;
	size_t	min;
	size_t	min_n;
	size_t	max_n;

	min_n = nodes_nbr;
	max_n = nodes_nbr;
	min = chunks_nbr / 2;
	max = min + 1;
	while ((*stacks)->head_a)
	{
		if (!min_n)
			min_n = update_min_max(min--, nodes_nbr);
		else if (!max_n)
			max_n = update_min_max(max++, nodes_nbr);
		while ((*stacks)->head_a->chunk != max
			&& (*stacks)->head_a->chunk != min)
			ra(stacks);
		if ((*stacks)->head_a->chunk == max)
			max_n--;
		else
			min_n--;
		a_to_b(stacks, min_n, min, max);
	}
	b_to_a(stacks);
}
