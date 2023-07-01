/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:42:02 by oroy              #+#    #+#             */
/*   Updated: 2023/06/30 20:35:03 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct stack_info
{
	t_list	*head_a;
	t_list	*head_b;
}	t_stack;

void	a_to_b(t_stack **stacks, size_t min_n, int min, int max);
void	algo(t_stack **stacks, int chunks_nbr, size_t nodes_nbr);
void	b_to_a(t_stack **stacks);
void	basic_sort(t_stack **stacks, size_t count);
int		checkargs(t_stack **stacks, char **argv, size_t *count);
int		chunk_add(t_list *head_a, int *sorted, size_t nodes_nbr, size_t count);
int		chunk_getindex(int content, int *arr, size_t nodes_nbr);
int		chunk_nodes_amount(size_t count);
void	chunk_sort(t_stack **stacks, size_t count);
void	ft_error(t_stack **stacks);
void	ft_free(t_stack **stacks);
int		ft_isint(char *str, size_t *i);
int		*lstoarray(int *arr, t_list *head, size_t count);
void	parsing(t_stack **stacks, int param, int *algo_do);
int		*sortarray(int *arr, size_t count);
t_stack	*stacknew(void);

// PUSH --------------------------------------------------------------------- //
void	pa(t_stack **stacks);
void	pb(t_stack **stacks);
// REVERSE ROTATE ----------------------------------------------------------- //
void	rra(t_stack **stacks);
void	rrb(t_stack **stacks);
void	rrr(t_stack **stacks);
// ROTATE ------------------------------------------------------------------- //
void	ra(t_stack **stacks);
void	rb(t_stack **stacks);
void	rr(t_stack **stacks);
// SWAP --------------------------------------------------------------------- //
void	sa(t_stack **stacks);
void	sb(t_stack **stacks);
void	ss(t_stack **stacks);

#endif