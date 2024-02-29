/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:31:09 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(tt_list **stack, tt_list **s2)
{
	int	tmp;
	int	data;
	
	if (!(*stack))
		return (0);
	if (s2)
		data = (*s2)->data;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
	return (1);
}

int	sa(tt_list **stack, tt_list **s2)
{
	if (!(*stack))
		return (0);
	swap(stack, s2);
	return (1);
}

int	sb(tt_list **stack, tt_list **s2)
{
	if (!(*stack))
		return (0);
	swap(stack, s2);
	return (1);
}

int	ss(tt_list **stack1, tt_list **stack2)
{
	if (!(*stack1) || (!(*stack2)))
		return (0);
	swap(stack1, stack2);
	swap(stack2, stack1);
	return (0);
}
