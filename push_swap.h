/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:22:59 by oroy              #+#    #+#             */
/*   Updated: 2023/06/06 17:31:17 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct stack_info
{
	t_list	*head;
	t_list	*tail;
}	t_stack;

t_stack	*ft_stacknew(void);

// PUSH --------------------------------------------------------------------- //
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
// REVERSE ROTATE ----------------------------------------------------------- //
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
// ROTATE ------------------------------------------------------------------- //
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
// SWAP --------------------------------------------------------------------- //
void	sa(t_stack **head_a);
void	sb(t_stack **head_b);
void	ss(t_stack **head_a, t_stack **head_b);

#endif