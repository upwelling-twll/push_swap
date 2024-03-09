/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/03/09 17:17:02 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#define SA "sa" //1
#define SB "sb" //2
#define SS "ss" //3
#define PA "pa" //4
#define PB "pb" //5
#define RA "ra" //6
#define RB "rb" //7
#define RR "rr" //8
#define RRA "rra" //9
#define RRB "rrb" //10
#define RRR "rrr" //11

//this is a new type-function pointer type which will be used for instr func-s;
typedef int	(*t_insfunc)(t_llist **, t_llist **);

int	apply_ins(t_llist **stack1, t_llist **stack2, t_insfunc ins_recived)
{
	if (ins_recived == rrb || ins_recived == rb || ins_recived == sb)
	{
		if (ins_recived(stack2, stack1))
			return (1);
		return (1);
	}
	else if (ins_recived == rr || ins_recived == pa || ins_recived == ss)
	{
		if (ins_recived(stack1, stack2))
			return (1);
		return (1);
	}
	if (ins_recived(stack1, stack2))
		return (1);
	return (1);
}

int	valid_ins(char *ins)
{
	int			i;
	static char	*pssbl_op_list[11];

	i = 0;
	pssbl_op_list[0] = SA;
	pssbl_op_list[1] = SB;
	pssbl_op_list[2] = SS;
	pssbl_op_list[3] = PA;
	pssbl_op_list[4] = PB;
	pssbl_op_list[5] = RA;
	pssbl_op_list[6] = RB;
	pssbl_op_list[7] = RR;
	pssbl_op_list[8] = RRA;
	pssbl_op_list[9] = RRB;
	pssbl_op_list[10] = RRR;
	while (i < 11)
	{
		if ((ft_strcmp(ins, pssbl_op_list[i]) == 0))
			return (i);
		i++;
	}
	return (-1);
}

int	proc_all(t_chins *oper, t_llist **head, t_llist **stack2, t_chins *hoper)
{
	t_insfunc	pssbl_op[11];
	int			i;

	pssbl_op[0] = sa;
	pssbl_op[1] = sb;
	pssbl_op[2] = ss;
	pssbl_op[3] = pa;
	pssbl_op[4] = pb;
	pssbl_op[5] = ra;
	pssbl_op[6] = rb;
	pssbl_op[7] = rr;
	pssbl_op[8] = rra;
	pssbl_op[9] = rrb;
	pssbl_op[10] = rrr;
	i = valid_ins(oper ->content);
	if (i >= 0)
	{
		if (!(apply_ins(head, stack2, pssbl_op[i])))
			return (ft_exit(*head, *stack2, hoper, 2));
	}
	else
		return (ft_exit(*head, *stack2, hoper, 1));
	return (1);
}

int	apply_instructions(t_llist **lst, t_llist **stack2, t_chins *oper)
{
	t_chins	*hoper;

	hoper = oper;
	while (oper != NULL)
	{
		if (!(proc_all(oper, lst, stack2, hoper)))
			return (0);
		oper = oper ->next;
	}
	if (!(check_if_sorted(*lst)) || ft_llstsize(*stack2) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (ft_exit(*lst, *stack2, hoper, 0));
}
