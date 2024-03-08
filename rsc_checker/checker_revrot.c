/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_revrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/03/08 17:17:06 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rra(t_llist **stack, t_llist **s2)
{
	int	data;

	if (!(*stack))
		return (0);
	if (s2)
	{
		data = (*stack)->data;
		(*stack)->data = data;
	}
	*stack = (*stack)->prev;
	return (1);
}

int	rrb(t_llist **stack, t_llist **s2)
{
	int	data;

	if (!(*stack))
		return (0);
	if (s2)
	{
		data = (*stack)->data;
		(*stack)->data = data;
	}
	*stack = (*stack)->prev;
	return (1);
}

int	rrr(t_llist **stack1, t_llist **stack2)
{
	if (!(*stack1))
	{
		rrb(stack2, stack1);
		return (1);
	}
	else if (!(*stack2))
	{
		rra(stack1, stack2);
		return (1);
	}
	rra(stack1, stack2);
	rrb(stack2, stack2);
	return (1);
}
