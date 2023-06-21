/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:50:01 by oroy              #+#    #+#             */
/*   Updated: 2023/06/20 20:10:11 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_analyze(t_list *head, t_list *tail, int min, int max)
{
	unsigned int	top;
	unsigned int	bottom;

	top = 0;
	bottom = 0;
	while (head->chunk != max && head->chunk != min)
	{
		head = head->next;
		top++;
	}
	while (tail->chunk != max && tail->chunk != min)
	{
		tail = tail->previous;
		bottom++;
	}
	if (top <= bottom)
		return (1);
	else
		return (0);
}

void	ft_algo(t_stack **stacks, int chunks_num, size_t count)
{
	size_t	r_times;
	int		max;
	int		min;
	int		up_down;
	size_t	min_n;
	size_t	max_n;

	r_times = 0;
	up_down = 1;
	min = chunks_num / 2;
	max = min + 1;
	min_n = count / 10 + 1;
	max_n = count / 10 + 1;
	while ((*stacks)->head_a->next->next)
	{
		if (!min_n && min > 0)
		{
			min--;
			min_n = count / 10 + 1;
		}
		else if (!max_n && max <= chunks_num)
		{
			max++;
			max_n = count / 10 + 1;
		}
		up_down = ft_analyze((*stacks)->head_a, (*stacks)->tail_a, min, max);
		if (up_down)
		{
			while ((*stacks)->head_a->chunk != max
				&& (*stacks)->head_a->chunk != min)
				ra(stacks);
		}
		else
		{
			while ((*stacks)->head_a->chunk != max
				&& (*stacks)->head_a->chunk != min)
				rra(stacks);
		}
		if ((*stacks)->head_a->chunk == max)
		{
			pb(stacks);
			max_n--;
		}
		else
		{
			pb(stacks);
			if ((*stacks)->head_b->next)
				rb(stacks);
			min_n--;
		}
	}
	if ((*stacks)->head_a->content > (*stacks)->head_a->next->content)
		sa(stacks);
	while ((*stacks)->head_b)
	{
		if ((*stacks)->head_b->content < (*stacks)->head_a->content)
			pa(stacks);
		else if ((*stacks)->head_b->content > (*stacks)->tail_a->content)
		{
			pa(stacks);
			ra(stacks);
		}
		else
		{
			while ((*stacks)->head_a->content < (*stacks)->head_b->content)
			{
				ra(stacks);
				r_times++;
			}
			while ((*stacks)->head_b && (*stacks)->head_b->content < (*stacks)->head_a->content
				&& (*stacks)->head_b->content > (*stacks)->tail_a->content)
				pa(stacks);
			while (r_times)
			{
				rra(stacks);
				r_times--;
			}
		}
	}
}
