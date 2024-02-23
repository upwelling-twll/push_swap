/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_clcltA.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 22:10:13 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clclt_instr3(tt_list *upper_nbr, tt_list *st2, int size, i_list **inmb)
{
	int	un_position;

	un_position = 1;
	while (st2->data != upper_nbr->data)
	{
		un_position++;
		st2 = st2->next;
	}
	(*inmb)->s2_rotate_up = un_position;
	if (un_position == 1)
		(*inmb)->s2_rotate_down = 2;
	else
		(*inmb)->s2_rotate_down = size - un_position;
}

void	i_to_placea(tt_list *tr_s1, tt_list *st2, i_list **inumber, int size)
{
	tt_list	*min_s2;
	tt_list	*max_s2;
	tt_list	*upper_neighbour;
	int		inum;

	min_s2 = get_min(st2, size);
	max_s2 = get_max(st2, size);
	if (tr_s1-> data < min_s2->data)
		push_on_min(st2, min_s2, inumber);
	else if (tr_s1->data > max_s2->data)
		push_under_max(st2, max_s2, inumber);
	else
	{
		if (size == 3)
		{
			upper_neighbour = find_place3(st2, tr_s1->data, size);
			clclt_instr3(upper_neighbour, st2, size, inumber);
		}
		else
		{
			upper_neighbour = find_place33(st2, tr_s1->data, size);
			clclt_instr(upper_neighbour, st2, size, inumber);
		}
	}
}

int	inst_numa(tt_list *st1, tt_list *st2, tt_list *node, i_list **inumber)
{
	int		position;
	tt_list	*heads1;
	int		inst_num;
	int		size2;
	int		size1;

	position = 1;
	inst_num = 0;
	heads1 = st1;
	size1 = ft_llstsize(st1);
	size2 = ft_llstsize(st2);
	(*inumber)->target = node->data;
	while (st1 -> data != node->data)
	{
		position++;
		st1 = st1->next;
	}
	i_to_float(position, heads1, size1, inumber);
	i_to_placea(node, st2, inumber, size2);
	inst_num = optimize(inumber);
	return (inst_num + 1);
}
