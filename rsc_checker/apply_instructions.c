/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/03/08 16:36:00 by nmagdano         ###   ########.fr       */
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

static char	*pssbl_op_list[] = {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

//this is a new type-function pointer type which will be used for instr func-s;
typedef int	(*t_insfunc)(t_llist **, t_llist **);

//this a definition of arrey of function pointers to instruction finctions;
t_insfunc	pssbl_op[] = {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

// void	move_first(t_llist **stack1, t_llist **stack2)
// {
// 	int		tmp;
// 	t_llist	*new_head;
// 	t_llist	*old_last;

// 	tmp = (*stack1)->data;
// 	if (*stack2 == NULL)
// 	{
// 		*stack2 = add_node(*stack2, tmp);
// 		(*stack2)->next = *stack2;
// 		(*stack2)->prev = (*stack2);
// 	}
// 	else
// 	{
// 		old_last = ft_llstlast(*stack2);
// 		new_head = add_node(*stack2, tmp);
// 		old_last->next = new_head;
// 		new_head->next = *stack2;
// 		new_head->prev = old_last;
// 		(*stack2)->prev = new_head;
// 		*stack2 = new_head;
// 	}
// 	*stack1 = delfirst_ch(*stack1);
// }

// void	pb_first_ch(t_llist **stack1, t_llist **stack2)
// {
// 	int		tmp;

// 	tmp = (*stack1)->data;
// 	*stack2 = add_node(*stack2, tmp);
// 	(*stack2)->next = *stack2;
// 	(*stack2)->prev = (*stack2);
// 	*stack1 = delfirst_ch(*stack1);
// }

// int	pa(t_llist **stack1, t_llist **stack2)
// {
// 	if (!(*stack2))
// 		return (0);
// 	move_first(stack2, stack1);
// 	return (1);
// }

// int	pb(t_llist **stack1, t_llist **stack2)
// {
// 	if (!(*stack1))
// 		return (0);
// 	if ((*stack2) == NULL)
// 	{
// 		pb_first_ch(stack1, stack2);
// 		return (1);
// 	}
// 	move_first(stack1, stack2);
// 	return (1);
// }

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
	int	i;

	i = 0;
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
	//t_insfunc	pssbl_op[] = {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
	int	i;

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
