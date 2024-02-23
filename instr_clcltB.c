/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_clclt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 19:57:43 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	i_to_float(int position, tt_list *stack1, int size, i_list **inumber)
{
	(*inumber)->s1_rotate_up = position - 1;
	(*inumber)->s1_rotate_down = size - position + 1;
}

tt_list	*find_place(tt_list *st2, int target_data, tt_list *max, tt_list *min)
{
	int	size;

	size = ft_llstsize(st2);
	while (size)
	{
		if ((target_data > st2->data && target_data < st2->prev->data))
			return (st2);
		st2 = st2->next;
		size--;
	}
	return (st2);
}

void	clclt_instr(tt_list *upper_nbr, tt_list *st2, int s, i_list **inumber)
{
	int	un_position;

	un_position = 1;
	while (st2->data != upper_nbr->data)
	{
		un_position++;
		st2 = st2->next;
	}
	(*inumber)->s2_rotate_up = un_position - 1;
	if (un_position != s)
		(*inumber)->s2_rotate_down = s - un_position + 1;
	else
		(*inumber)->s2_rotate_down = 1;
}

void	i_to_place(tt_list *target_s1, tt_list *st2, i_list **inumber, int s)
{
	tt_list	*min_s2;
	tt_list	*max_s2;
	tt_list	*upper_nebor;
	int		inum;

	min_s2 = get_min(st2, s);
	max_s2 = get_max(st2, s);
	if (target_s1->data < min_s2->data)
		push_on_max(st2, max_s2, inumber);
	else if (target_s1->data > max_s2->data)
		push_under_min(st2, min_s2, inumber);
	else
	{
		upper_nebor = find_place(st2, target_s1->data, max_s2, min_s2);
		clclt_instr(upper_nebor, st2, s, inumber);
	}
}

int	inst_num(tt_list *stack1, tt_list *stack2, tt_list *node, i_list **inumber)
{
	int		position;
	tt_list	*heads1;
	int		inst_num;
	int		size2;
	int		size1;

	position = 1;
	inst_num = 0;
	heads1 = stack1;
	size2 = ft_llstsize(stack2);
	size1 = ft_llstsize(stack1);
	(*inumber)->target = node->data;
	while (stack1 -> data != node->data)
	{
		position++;
		stack1 = stack1->next;
	}
	i_to_float(position, heads1, size1, inumber);
	i_to_place(node, stack2, inumber, size2);
	inst_num = optimize(inumber);
	return (inst_num + 1);
}
