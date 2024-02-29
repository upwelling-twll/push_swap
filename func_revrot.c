/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_revrot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:31:28 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(tt_list **stack, tt_list **s2)
{
	int	data;
	
	if (!(*stack))
		return (0);
	if (s2)
		data = (*s2)->data;
	*stack = (*stack)->prev;
	return (1);
}

int	rrb(tt_list **stack, tt_list **s2)
{
	int	data;
	
	if (!(*stack))
		return (0);
	if (s2)
		data = (*s2)->data;
	*stack = (*stack)->prev;
	return (1);
}

int	rrr(tt_list **stack1, tt_list **stack2)
{
	if (!(*stack1) || (!(*stack2)))
		return (0);
	rra(stack1, stack2);
	rrb(stack2, stack2);
	return (1);
}
