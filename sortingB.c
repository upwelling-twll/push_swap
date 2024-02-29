/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingB.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 12:13:44 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_instr(t_llist **stack1, t_llist **stack2, t_inst *i_target, int dr)
{
	if (i_target->mood == 1)
		run_mood1(stack1, stack2, i_target, dr);
	if (i_target->mood == 2)
		run_mood2(stack1, stack2, i_target, dr);
	if (i_target->mood == 3)
		run_mood3(stack1, stack2, i_target, dr);
	if (i_target->mood == 4)
		run_mood4(stack1, stack2, i_target, dr);
	if (dr == 1)
		write(1, "pb\n", 3);
	else if (dr == 2)
		write(1, "pa\n", 3);
}

void	update_inst(t_inst **i_target, t_inst **inumber)
{
	(*i_target)-> target = (*inumber)-> target;
	(*i_target)-> s1_rotate_up = (*inumber)-> s1_rotate_up;
	(*i_target)-> s1_rotate_down = (*inumber)-> s1_rotate_down;
	(*i_target)-> s2_rotate_up = (*inumber)-> s2_rotate_up;
	(*i_target)-> s2_rotate_down = (*inumber)-> s2_rotate_down;
	(*i_target)-> mood = (*inumber)-> mood;
}

void	fnd_tr(t_llist *head, t_llist *st2, t_inst **i_target, t_trda **data)
{
	(*data)->cur_ins = inst_num(head, st2, (*data)->cur, (*data)->ins_data);
	if ((*data)->min_ins > (*data)->cur_ins)
	{
		(*data)->tr = (*data)->cur;
		(*data)->min_ins = (*data)->cur_ins;
		update_inst(i_target, (*data)->ins_data);
	}
}

void	find_target(t_llist *head, t_llist *stack2, t_inst **i_target, int s)
{
	t_inst	*inumber;
	t_trda	*tr_data;

	inumber = malloc(sizeof(t_inst));
	tr_data = malloc(sizeof(t_trda));
	tr_data->cur = head;
	tr_data->ins_data = &inumber;
	tr_data->min_ins = inst_num(head, stack2, tr_data->cur, tr_data->ins_data);
	update_inst(i_target, tr_data->ins_data);
	tr_data->tr = tr_data->cur;
	while (s)
	{
		fnd_tr(head, stack2, i_target, &tr_data);
		tr_data->cur = (tr_data->cur)->next;
		s--;
	}
	free(inumber);
	free(tr_data);
	return ;
}
