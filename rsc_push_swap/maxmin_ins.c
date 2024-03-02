/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxmin_ins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 12:10:47 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*get_min(t_llist *stack, int size)
{
	t_llist	*min;

	size++;
	min = stack;
	while (size > 0)
	{
		if (stack->data < min->data)
			min = stack;
		stack = stack->next;
		size--;
	}
	return (min);
}

t_llist	*get_max(t_llist *stack, int size)
{
	t_llist	*max;

	size++;
	max = stack;
	while (size)
	{
		if (stack->data > max->data)
			max = stack;
		stack = stack->next;
		size--;
	}
	return (max);
}

void	push_on_max(t_llist *stack, t_llist *max, t_inst **instr)
{
	t_llist	*head;
	int		i_rb;
	int		i_rrb;

	i_rb = 0;
	i_rrb = 0;
	head = stack;
	while (stack->data != max->data)
	{
		rb(&stack, NULL);
		i_rb++;
	}
	(*instr)->s2_rotate_up = i_rb;
	stack = head;
	while (stack->data != max->data)
	{
		rrb(&stack, NULL);
		i_rrb++;
	}
	(*instr)->s2_rotate_down = i_rrb;
}

void	push_under_min(t_llist *stack, t_llist *min, t_inst **instr)
{
	t_llist	*head;
	int		i_rb;
	int		i_rrb;

	i_rb = 0;
	i_rrb = 0;
	head = stack;
	while (stack->data != min->next->data)
	{
		rb(&stack, NULL);
		i_rb++;
	}
	(*instr)->s2_rotate_up = i_rb;
	stack = head;
	while (stack->data != min->next->data)
	{
		rrb(&stack, NULL);
		i_rrb++;
	}
	(*instr)->s2_rotate_down = i_rrb;
}
