/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingA.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 22:09:46 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_under_max(tt_list *stack, tt_list *max, i_list **instr)
{
	tt_list	*head;
	int		i_rb;
	int		i_rrb;

	i_rb = 0;
	i_rrb = 0;
	head = stack;
	while (stack->data != max->next->data)
	{
		rb(&stack, NULL);
		i_rb++;
	}
	(*instr)->s2_rotate_up = i_rb;
	stack = head;
	while (stack->data != max->next->data)
	{
		rrb(&stack, NULL);
		i_rrb++;
	}
	(*instr)->s2_rotate_down = i_rrb;
}

void	push_on_min(tt_list *stack, tt_list *min, i_list **instr)
{
	tt_list	*head;
	int		i_rb;
	int		i_rrb;

	i_rb = 0;
	i_rrb = 0;
	head = stack;
	while (stack->data != min->data)
	{
		rb(&stack, NULL);
		i_rb++;
	}
	(*instr)->s2_rotate_up = i_rb;
	stack = head;
	while (stack->data != min->data)
	{
		rrb(&stack, NULL);
		i_rrb++;
	}
	(*instr)->s2_rotate_down = i_rrb;
}

void	fnd_tra(tt_list *head, tt_list *st2, i_list **i_target, tr_list **data)
{
	(*data)->cur_ins = inst_numa(head, st2, (*data)->cur, (*data)->ins_data);
	if ((*data)->min_ins > (*data)->cur_ins)
	{
		(*data)->tr = (*data)->cur;
		(*data)->min_ins = (*data)->cur_ins;
		update_inst(i_target, (*data)->ins_data);
	}
}

void	find_targeta(tt_list *head, tt_list *stack2, i_list **i_target, int s)
{
	i_list	*inumber;
	tr_list	*tr_data;

	inumber = malloc(sizeof(i_list));
	tr_data = malloc(sizeof(tr_list));
	tr_data->cur = head;
	tr_data->ins_data = &inumber;
	tr_data->min_ins = inst_numa(head, stack2, tr_data->cur, tr_data->ins_data);
	update_inst(i_target, &inumber);
	tr_data->tr = tr_data->cur;
	while (s)
	{
		fnd_tra(head, stack2, i_target, &tr_data);
		tr_data->cur = (tr_data->cur)->next;
		s--;
	}
	free (inumber);
	free(tr_data);
	return ;
}
