/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:18:48 by oroy              #+#    #+#             */
/*   Updated: 2023/06/14 16:54:25 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_result(t_stack *stacks, size_t moves)
// {
// 	printf ("Moves : %zu\n", moves);
// 	ft_printf ("\n");
// 	ft_printf ("a	b");
// 	ft_printf ("\n\n");
// 	while (stacks->head_a || stacks->head_b)
// 	{
// 		if (stacks->head_a)
// 		{
// 			ft_printf ("%i", stacks->head_a->content);
// 			stacks->head_a = stacks->head_a->next;
// 		}
// 		ft_printf ("	");
// 		if (stacks->head_b)
// 		{
// 			ft_printf ("%i", stacks->head_b->content);
// 			stacks->head_b = stacks->head_b->next;
// 		}
// 		ft_printf ("\n");
// 	}
// 	ft_printf ("\n\n");
// }

// void	ft_tests(t_stack **stacks)
// {
// 	pa(stacks);
// 	pb(stacks);
// 	pb(stacks);
// 	sa(stacks);
// 	sb(stacks);
// 	ra(stacks);
// 	rb(stacks);
// 	pb(stacks);
// 	pb(stacks);
// 	pb(stacks);
// 	pb(stacks);
// 	rra(stacks);
// 	pa(stacks);
// 	pa(stacks);
// 	pa(stacks);
// 	rra(stacks);
// 	ss(stacks);
// 	rrr(stacks);
// 	rr(stacks);
// }

void	ft_error(t_stack *stacks)
{
	ft_putstr_rtn_fd("Error\n", 2);
	if (stacks)
	{
		ft_lstclear(&stacks->head_a);
		if (stacks->tail_a)
			stacks->tail_a = NULL;
		free (stacks);
		stacks = NULL;
	}
	exit (1);
}

void	ft_updatelimits(t_stack *stacks, int param)
{
	if (param > stacks->max)
		stacks->max = param;
	else if (param < stacks->min)
		stacks->min = param;
}

void	ft_parse(t_stack **stacks, char *arg, int *algo_do)
{
	int		param;

	param = ft_atoi(arg);
	ft_updatelimits(*stacks, param);
	if (!(*stacks)->head_a)
	{
		(*stacks)->head_a = ft_lstnew(param, NULL);
		if (!(*stacks)->head_a)
			ft_error(*stacks);
		(*stacks)->tail_a = (*stacks)->head_a;
	}
	else
	{
		if (ft_lstchr((*stacks)->head_a, param))
			ft_error(*stacks);
		(*stacks)->tail_a = ft_lstnew(param, (*stacks)->tail_a);
		if (!(*stacks)->tail_a)
			ft_error(*stacks);
		(*stacks)->tail_a->previous->next = (*stacks)->tail_a;
		if (param < (*stacks)->tail_a->previous->content)
			*algo_do = 1;
	}
}

void	ft_checkargs(t_stack **stacks, char **argv, int	*algo_do, size_t *count)
{
	size_t	i;
	size_t	j;
	size_t	j_save;
	char	*str;

	i = 1;
	str = NULL;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j] <= 13))
				j++;
			if (!argv[i][j])
				break ;
			j_save = j;
			if (!ft_isint(argv[i], &j))
				ft_error(*stacks);
			if (argv[i][j] || j_save)
			{
				str = ft_substr(argv[i], j_save, j - j_save);
				if (!str)
					ft_error(*stacks);
				ft_parse(stacks, str, algo_do);
				free (str);
				str = NULL;
			}
			else
				ft_parse(stacks, argv[i], algo_do);
			*count += 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	int		algo_do;
	size_t	count;

	if (argc > 1)
	{
		count = 0;
		algo_do = 0;
		stacks = NULL;
		stacks = ft_stacknew();
		if (!stacks)
			ft_error(stacks);
		ft_checkargs(&stacks, argv, &algo_do, &count);
		ft_printf ("Count : %i\n", count);
		ft_printf ("Max : %i\n", stacks->max);
		ft_printf ("Min : %i\n", stacks->min);
		if (algo_do)
			ft_algo(&stacks, count);
		// ft_result(stacks, ft_algo(&stacks));
		// ft_tests(&stacks);
		// ft_result(stacks);
	}
	return (0);
}
