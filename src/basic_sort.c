/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:36:35 by oroy              #+#    #+#             */
/*   Updated: 2023/07/04 19:42:36 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort3(t_stack **stacks)
{
	t_list	*head;

	head = (*stacks)->head_a;
	if ((head->prev->content > head->content 
			&& head->content > head->next->content))
		sa(stacks);
	else if (head->content > head->next->content
		&& head->next->content > head->prev->content)
	{
		sa(stacks);
		rra(stacks);
	}
	else if ((head->content > head->prev->content 
			&& head->prev->content > head->next->content))
		ra(stacks);
	else if (head->next->content > head->content 
		&& head->content > head->prev->content)
		rra(stacks);
	else if (head->next->content > head->prev->content
		&& head->prev->content > head->content)
	{
		rra(stacks);
		sa(stacks);
	}
}

void	basic_sort(t_stack **stacks, size_t count)
{
	if (count == 2)
		sa(stacks);
	else
	{
		while (count != 3)
		{
			pb(stacks);
			count--;
		}
		sort3(stacks);
		b_to_a(stacks);
	}
}
