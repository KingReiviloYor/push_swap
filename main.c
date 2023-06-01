/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:18:48 by oroy              #+#    #+#             */
/*   Updated: 2023/06/01 18:17:47 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head)
{
	t_list	*save;

	save = *head;
	*head = (*head)->next;
	save->next = (*head)->next;
	(*head)->next = save;
}

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*save;

	save = (*head_b)->next;
	ft_lstadd_front(head_a, *head_b);
	*head_b = save;
}

void	ra(t_list **head_a)
{
	t_list	*save;

	save = *head_a;
	*head_a = (*head_a)->next;
	save->next = NULL;
	ft_lstadd_back(head_a, save);
}

void	rra(t_list **head_a)
{
	t_list	*save;

	save = ft_lst2ndlast(*head_a);
	ft_lstadd_front(head_a, save->next);
	save->next = NULL;
}

int	main(int argc, char **argv)
{
	size_t	i;
	int		param;
	t_list	*head_a;
	t_list	*head_b;

	if (argc > 1)
	{
		i = 1;
		head_b = ft_lstnew(0);
		while (argv[i])
		{
			param = ft_atoi(argv[i]);
			if (i == 1)
				head_a = ft_lstnew(param);
			else
				ft_lstadd_back(&head_a, ft_lstnew(param));
			i++;
		}
		// sa(&head_a);
		// pa(&head_a, &head_b);
		// ra(&head_a);
		rra(&head_a);
		// For Testing Purposes
		while (head_a->next)
		{
			printf ("%i\n", head_a->content);
			head_a = head_a->next;
		}
		printf ("%i\n", head_a->content);
		if (head_b)
			printf ("%i\n", head_b->content);
	}
	return (0);
}
