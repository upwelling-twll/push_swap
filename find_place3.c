/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 21:50:45 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

tt_list	*find_place3(tt_list *stack2, int target_data, int size)
{
	while (size)
	{
		if ((target_data > stack2->data && target_data < stack2->next->data))
			return (stack2);
		stack2 = stack2->next;
		size--;
	}
	return (stack2);
}

tt_list	*find_place33(tt_list *stack2, int target_data, int size)
{
	while (size)
	{
		if ((target_data < stack2->data && target_data > stack2->prev->data))
			return (stack2);
		stack2 = stack2->next;
		size--;
	}
	return (stack2);
}
