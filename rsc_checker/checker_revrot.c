/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:48:39 by nmagdano         ###   ########.fr       */
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
		data = (*s2)->data;
		(*s2)->data = data;
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
		data = (*s2)->data;
		(*s2)->data = data;
	}
	*stack = (*stack)->prev;
	return (1);
}

int	rrr(t_llist **stack1, t_llist **stack2)
{
	if (!(*stack1) || (!(*stack2)))
		return (0);
	rra(stack1, stack2);
	rrb(stack2, stack2);
	return (1);
}
