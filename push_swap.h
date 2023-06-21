/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:22:59 by oroy              #+#    #+#             */
/*   Updated: 2023/06/21 12:15:36 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct stack_info
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*tail_a;
	t_list	*tail_b;
}	t_stack;

void	ft_algo(t_stack **stacks, int chunks_num, size_t chunk_size);
int		ft_getchunkindex(int content, int *arr, size_t chunk_size);
int		ft_isint(char *str, size_t *i);
int		*ft_sortarray(int *arr, size_t count);
t_stack *ft_stacknew(void);

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