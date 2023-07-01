/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:54:33 by oroy              #+#    #+#             */
/*   Updated: 2023/06/29 22:33:09 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static void	b_to_a_more(t_stack **stacks)
// {
// 	while ((*stacks)->head_a->content < (*stacks)->head_b->content)
// 		ra(stacks);
// 	while ((*stacks)->head_b
// 		&& (*stacks)->head_b->content < (*stacks)->head_a->content
// 		&& (*stacks)->head_b->content > (*stacks)->head_a->prev->content)
// 		pa(stacks);
// }

static size_t	get_node_position(t_stack *stacks)
{
	t_list	*pos;
	size_t	i;

	i = 0;
	pos = stacks->head_a;
	while (pos->next != stacks->head_a)
	{
		if (pos->content < stacks->head_b->content
			&& pos->next->content > stacks->head_b->content)
			break ;
		pos = pos->next;
		i++;
	}
	if (!i)
		i = 1;
	return (i);
}

static int	getindex_lowest(t_list *head)
{
	t_list	*pos;
	int	lowest;
	size_t	i;

	i = 1;
	lowest = 0;
	pos = head;
	while (pos->next != head)
	{
		lowest = pos->content;
		pos = pos->next;
		if (pos->content < lowest)
			break ;
		i++;
	}
	return (i);
}

void	b_to_a(t_stack **stacks)
{
	size_t	r_times;
	size_t	lstsize;
	size_t	idx;

	idx = 0;
	lstsize = 0;
	r_times = 0;
	pa(stacks);
	pa(stacks);
	while ((*stacks)->head_b)
	{
		if (!(*stacks)->head_a || (*stacks)->head_a->next == (*stacks)->head_a
			|| ((*stacks)->head_a->content < (*stacks)->head_a->prev->content
			&& (*stacks)->head_b->content < (*stacks)->head_a->content)
			|| ((*stacks)->head_a->prev->content < (*stacks)->head_a->content
			&& (*stacks)->head_a->content > (*stacks)->head_b->content
			&& (*stacks)->head_a->prev->content < (*stacks)->head_b->content)
			|| ((*stacks)->head_a->prev->content > (*stacks)->head_a->content
			&& (*stacks)->head_b->content > (*stacks)->head_a->prev->content))
			pa(stacks);
		// else if ((*stacks)->head_a->prev->content > (*stacks)->head_a->content
		// 	&& (*stacks)->head_b->content > (*stacks)->head_a->prev->content)
		// {
		// 	pa(stacks);
		// 	ra(stacks);
		// }
		else
		{
			lstsize = ft_lstsize((*stacks)->head_a);
			idx = get_node_position(*stacks);
			if (idx <= lstsize / 2)
			{
				r_times = idx;
				while (r_times)
				{
					ra(stacks);
					r_times--;
				}
			}
			else
			{
				r_times = lstsize - idx;
				while (r_times)
				{
					rra(stacks);
					r_times--;
				}
			}
		}
	}
	if ((*stacks)->head_a->content > (*stacks)->head_a->prev->content)
	{
		lstsize = ft_lstsize((*stacks)->head_a);
		idx = getindex_lowest((*stacks)->head_a);
		if (idx <= lstsize / 2)
		{
			r_times = idx;
			while (r_times)
			{
				ra(stacks);
				r_times--;
			}
		}
		else
		{
			r_times = lstsize - idx;
			while (r_times)
			{
				rra(stacks);
				r_times--;
			}
		}
	}
}

// void	b_to_a(t_stack **stacks)
// {
// 	size_t	r_times;
// 	size_t	lstsize;
// 	size_t	idx;

// 	idx = 0;
// 	lstsize = 0;
// 	r_times = 0;
// 	pa(stacks);
// 	pa(stacks);
// 	while ((*stacks)->head_b)
// 	{
// 		if (!(*stacks)->head_a || (*stacks)->head_a->next == (*stacks)->head_a
// 			|| ((*stacks)->head_a->prev->content > (*stacks)->head_a->content
// 			&& (*stacks)->head_b->content < (*stacks)->head_a->content)
// 			|| ((*stacks)->head_a->prev->content < (*stacks)->head_a->content
// 			&& (*stacks)->head_b->content < (*stacks)->head_a->content))
// 			pa(stacks);
// 		else
// 		{
// 			lstsize = ft_lstsize((*stacks)->head_a);
// 			idx = get_node_position(*stacks);
// 			if (idx <= lstsize / 2)
// 			{
// 				r_times = idx;
// 				while (r_times)
// 				{
// 					ra(stacks);
// 					r_times--;
// 				}
// 			}
// 			else
// 			{
// 				r_times = lstsize - idx;
// 				while (r_times)
// 				{
// 					rra(stacks);
// 					r_times--;
// 				}
// 			}
// 		}
// 	}
// 	if ((*stacks)->head_a->content > (*stacks)->head_a->prev->content)
// 	{
// 		lstsize = ft_lstsize((*stacks)->head_a);
// 		idx = getindex_lowest((*stacks)->head_a);
// 		if (idx <= lstsize / 2)
// 		{
// 			r_times = idx;
// 			while (r_times)
// 			{
// 				ra(stacks);
// 				r_times--;
// 			}
// 		}
// 		else
// 		{
// 			r_times = lstsize - idx;
// 			while (r_times)
// 			{
// 				rra(stacks);
// 				r_times--;
// 			}
// 		}
// 	}
// }
