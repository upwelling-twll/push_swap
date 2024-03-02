/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:43:44 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*find_place3(t_llist *stack2, int target_data, int size)
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

t_llist	*find_place33(t_llist *stack2, int target_data, int size)
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
