/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/03/09 16:38:12 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ra(t_llist **stack, t_llist **s2)
{
	int	data;

	if (!(*stack))
		return (0);
	if (s2)
	{
		data = (*stack)->data;
		(*stack)->data = data;
	}
	*stack = (*stack)->next;
	return (1);
}

int	rb(t_llist **stack, t_llist **s2)
{
	int	data;

	if (!(*stack))
		return (0);
	if (s2)
	{
		data = (*stack)->data;
		(*stack)->data = data;
	}
	*stack = (*stack)->next;
	return (1);
}

int	rr(t_llist **stack1, t_llist **stack2)
{
	if (!(*stack1))
	{
		rb(stack2, stack1);
		return (1);
	}
	else if (!(*stack2))
	{
		ra(stack1, stack2);
		return (1);
	}
	ra(stack1, stack2);
	rb(stack2, stack2);
	return (1);
}
