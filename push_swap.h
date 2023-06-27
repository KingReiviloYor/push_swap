/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:42:02 by oroy              #+#    #+#             */
/*   Updated: 2023/06/27 19:00:46 by oroy             ###   ########.fr       */
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
}	t_stack;

int		ft_addchunk(t_list *head_a, int *sorted, size_t chunk_size);
void	ft_algo(t_stack **stacks, int chunks_num, size_t chunk_size);
int		ft_checkargs(t_stack **stacks, char **argv, size_t *count);
void	ft_error(t_stack **stacks);
int		ft_getchunkdiv(size_t count);
int		ft_getchunkindex(int content, int *arr, size_t chunk_size);
int		ft_isint(char *str, size_t *i);
int		*ft_lstoarray(int *arr, t_list *head);
void	ft_parse(t_stack **stacks, int param, int *algo_do);
// int		ft_sendarg(t_stack **stacks, char *s, size_t s_start, size_t s_end);
void	ft_sendarg(t_stack **stacks, char *s, size_t len, int *algo_do);
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