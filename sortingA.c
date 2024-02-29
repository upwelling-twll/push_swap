/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingA.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 12:13:24 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_under_max(t_llist *stack, t_llist *max, t_inst **instr)
{
	t_llist	*head;
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

void	push_on_min(t_llist *stack, t_llist *min, t_inst **instr)
{
	t_llist	*head;
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

void	fnd_tra(t_llist *head, t_llist *st2, t_inst **i_target, t_trda **data)
{
	(*data)->cur_ins = inst_numa(head, st2, (*data)->cur, (*data)->ins_data);
	if ((*data)->min_ins > (*data)->cur_ins)
	{
		(*data)->tr = (*data)->cur;
		(*data)->min_ins = (*data)->cur_ins;
		update_inst(i_target, (*data)->ins_data);
	}
}

void	find_targeta(t_llist *head, t_llist *stack2, t_inst **i_target, int s)
{
	t_inst	*inumber;
	t_trda	*tr_data;

	inumber = malloc(sizeof(t_inst));
	tr_data = malloc(sizeof(t_trda));
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
