/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:31:18 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(tt_list **stack, tt_list **s2)
{
	int	data;
	
	if (!(*stack))
		return (0);
	if (s2)
		data = (*s2)->data;
	*stack = (*stack)->next;
	return (1);
}

int	rb(tt_list **stack, tt_list **s2)
{
	int	data;
	
	if (!(*stack))
		return (0);
	if (s2)
		data = (*s2)->data;
	*stack = (*stack)->next;
	return (1);
}

int	rr(tt_list **stack1, tt_list **stack2)
{
	if (!(*stack1) || (!(*stack2)))
		return (0);
	ra(stack1, stack2);
	rb(stack2, stack2);
	return (1);
}
