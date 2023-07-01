/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:18:48 by oroy              #+#    #+#             */
/*   Updated: 2023/06/29 22:38:37 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_displaychunks(t_stack *stacks)
{
	t_list	*head;

	stacks->head_b->prev->next = NULL;
	head = stacks->head_b;
	while (head)
	{
		printf ("%i", head->chunk);
		printf (" - ");
		printf ("%i\n", head->content);
		head = head->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	size_t	count;

	if (argc > 1)
	{
		count = 0;
		stacks = stacknew();
		if (!stacks)
			ft_error(&stacks);
		if (checkargs(&stacks, argv, &count))
		{
			stacks->head_a->prev->next = stacks->head_a;
			if (count <= 5)
				basic_sort(&stacks, count);
			else
				chunk_sort(&stacks, count);
		}
		// ft_displaychunks(stacks);
		// stacks->head_a->prev->next = NULL;
		// ft_free(&stacks);
	}
	return (0);
}
