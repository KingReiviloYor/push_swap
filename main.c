/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:18:48 by oroy              #+#    #+#             */
/*   Updated: 2023/06/16 20:35:42 by oroy             ###   ########.fr       */
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

void	ft_parse(t_stack **stacks, char *arg, int *algo_do)
{
	int		param;

	param = ft_atoi(arg);
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
			(*count)++;
		}
		i++;
	}
}

int	*ft_fillarray(int *sorted, t_list *head_a, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		sorted[i] = head_a->content;
		head_a = head_a->next;
		i++;
	}
	return (sorted);
}

int	ft_addchunk(t_list *head_a, int *sorted, size_t chunk_size)
{
	int	chunks_num;

	chunks_num = 0;
	while (head_a)
	{
		head_a->chunk = ft_getchunkindex(head_a->content, sorted, chunk_size);
		if (head_a->chunk > chunks_num)
			chunks_num = head_a->chunk;
		head_a = head_a->next;
	}
	return (chunks_num);
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	int		*sorted;
	int		algo_do;
	int		chunks_num;
	size_t	count;

	if (argc > 1)
	{
		count = 0;
		algo_do = 0;
		sorted = NULL;
		stacks = NULL;
		stacks = ft_stacknew();
		if (!stacks)
			ft_error(stacks);
		ft_checkargs(&stacks, argv, &algo_do, &count);
		sorted = ft_calloc(count, sizeof(int));
		if (!sorted)
			ft_error(stacks);
		sorted = ft_fillarray(sorted, stacks->head_a, count);
		sorted = ft_sortarray(sorted, count);
		chunks_num = ft_addchunk(stacks->head_a, sorted, count / 10 + 1);
		// while (stacks->head_a)
		// {
		// 	printf ("%i ", stacks->head_a->chunk);
		// 	printf ("%i\n", stacks->head_a->content);
		// 	stacks->head_a = stacks->head_a->next;
		// }
		if (algo_do)
			ft_algo(&stacks, chunks_num);
		// if (algo_do)
		// 	ft_result(stacks, ft_algo(&stacks, chunks_num));
		// ft_tests(&stacks);
		// ft_result(stacks);
	}
	return (0);
}
