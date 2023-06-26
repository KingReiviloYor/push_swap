/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstoarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:08:07 by oroy              #+#    #+#             */
/*   Updated: 2023/06/22 14:41:51 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_lstoarray(int *arr, t_list *head)
{
	size_t	i;

	i = 0;
	while (head)
	{
		arr[i] = head->content;
		head = head->next;
		i++;
	}
	return (arr);
}
