/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:43:31 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_llist **stack, t_llist **s2)
{
	int	data;

	if (!(*stack))
		return (0);
	if (s2)
		data = (*s2)->data;
	*stack = (*stack)->next;
	return (1);
}

int	rb(t_llist **stack, t_llist **s2)
{
	int	data;

	if (!(*stack))
		return (0);
	if (s2)
		data = (*s2)->data;
	*stack = (*stack)->next;
	return (1);
}

int	rr(t_llist **stack1, t_llist **stack2)
{
	if (!(*stack1) || (!(*stack2)))
		return (0);
	ra(stack1, stack2);
	rb(stack2, stack2);
	return (1);
}
