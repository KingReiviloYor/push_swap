/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortarray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:30:43 by oroy              #+#    #+#             */
/*   Updated: 2023/06/30 22:14:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*sortarray(int *arr, size_t count)
{
	size_t	i;
	int		save;

	save = 0;
	while (count)
	{
		i = 0;
		while (i < count - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				save = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = save;
			}
			i++;
		}
		count--;
	}
	return (arr);
}
