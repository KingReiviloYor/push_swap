/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:18:48 by oroy              #+#    #+#             */
/*   Updated: 2023/06/05 20:20:52 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head_a)
{
	t_list	*save;

	if (*head_a && (*head_a)->next)
	{
		save = *head_a;
		*head_a = (*head_a)->next;
		save->next = (*head_a)->next;
		(*head_a)->next = save;
		ft_printf ("%s\n", "sa");
	}
}

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*save;

	if (*head_b)
	{
		save = (*head_b)->next;
		ft_lstadd_front(head_a, *head_b);
		*head_b = save;
		ft_printf ("%s\n", "pa");
	}
}

void	ra(t_list **head_a, t_list **tail_a)
{
	t_list	*save;

	if (*head_a && (*head_a)->next)
	{
		save = *head_a;
		*head_a = (*head_a)->next;
		save->previous = *tail_a;
		save->next = NULL;
		(*head_a)->previous = NULL;
		(*tail_a)->next = save;
		*tail_a = save;
		ft_printf ("%s\n", "ra");
	}
}

void	rra(t_list **head_a, t_list **tail_a)
{
	if (*head_a && (*head_a)->next)
	{
		(*tail_a)->next = *head_a;
		(*head_a)->previous = *tail_a;
		*head_a = *tail_a;
		*tail_a = (*tail_a)->previous;
		(*tail_a)->next = NULL;
		(*head_a)->previous = NULL;
		ft_printf ("%s\n", "rra");
	}
}

int	main(int argc, char **argv)
{
	size_t	i;
	int		param;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		i = 1;
		stack_a = ft_stacknew();
		stack_b = ft_stacknew();
		stack_b->head = ft_lstnew(0, NULL);
		while (argv[i])
		{
			if (!ft_isint(argv[i]))
			{
				// Eventually need to free here
				ft_putstr_rtn_fd("Error\n", 2);
				return (0);
			}
			param = ft_atoi(argv[i]);
			if (i == 1)
				stack_a->head = ft_lstnew(param, NULL);
			else
			{
				if (ft_lstchr(stack_a->head, param))
				{
					// Eventually need to free here
					ft_putstr_rtn_fd("Error\n", 2);
					return (0);
				}
				if (i == 2)
					stack_a->tail = stack_a->head;
				stack_a->tail = ft_lstnew(param, stack_a->tail);
				stack_a->tail->previous->next = stack_a->tail;
			}
			i++;
		}
		pa(&stack_a->head, &stack_b->head);
		sa(&stack_a->head);
		ra(&stack_a->head, &stack_a->tail);
		rra(&stack_a->head, &stack_a->tail);
		// For Testing Purposes
		while (stack_a->head->next)
		{
			printf ("%i\n", stack_a->head->content);
			stack_a->head = stack_a->head->next;
		}
		printf ("%i\n", stack_a->head->content);
		if (stack_b->head)
			printf ("%i\n", stack_b->head->content);
	}
	return (0);
}
