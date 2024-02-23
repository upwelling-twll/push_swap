/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 22:20:12 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
#include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct ss_list
{
	struct ss_list	*prev;
	int				data;
	struct ss_list	*next;
}					tt_list;

typedef struct inst_list
{
	int		target;
	int		s1_rotate_up; // up = ra
	int		s1_rotate_down; // down = rra

	int		s2_rotate_up; //  up = rb The first element becomes the last one. the number of instructions rb which are needed to place the element
	int 	s2_rotate_down;// down = rrb The last element becomes the first one.
	int		mood; //
}					i_list;

typedef	struct tr_data
{
	struct ss_list 		*cur;
	struct ss_list 		*tr;
	struct inst_list	**ins_data;
	int					min_ins;
	int					cur_ins;
}						tr_list;

//sceleton.c
int		ft_parse_input(int argc, char *argv[], tt_list **nlist);
int		fill_stack1(int argc, char *argv[], tt_list **nlist, tt_list **head);
void	push_to_stack2(tt_list **stack1, tt_list **stack2);
void	push_to_stack1(tt_list **stack1, tt_list **stack2);

//verify or exit.c
void	del_stack_lst(tt_list *lst);
int		check_overflow(const char *str, int flag, int i);
int		verify_atoi(const char *str);
int		verify_argv(tt_list *args_lst, char *argv);
int		ft_exit_ps(tt_list *st1, tt_list *st2, int display);

//list_operations.c
tt_list	*init_list(int i);
tt_list	*ft_llstlast(tt_list *lst);
int		ft_llstsize(tt_list *lst);
tt_list	*add_node(tt_list *nlist, int data);

//stack_analysis.c
int		check_if_sorted(tt_list *lst);
void	float_ra(tt_list **head, int position); //rotating until the element which is prev to min is not on the top
void	float_rra(tt_list **head, tt_list *new_head, int position); //rotating until the element which is prev to min is not on the top
void	float_to_top(tt_list **head, tt_list *new_head);
void	min_to_top(tt_list **lst);

//sort_samll.c
tt_list	*sort_2(tt_list **lst);
void	write_oper(int opt);
void	run(tt_list **lst, int opt);
void	sort_3(tt_list **lst);

//sort_mode.c
void	rotate_2(tt_list **s1, tt_list **s2, i_list *it, int mode);
void	run_mood1(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr);
void	run_mood2(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr);
void	run_mood3(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr);
void	run_mood4(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr);

//optimize_ins.c
char	gmin(int a, int b , int c, int d);
int		best_option(int s1us2d, int s1ds2u, int tu, int td);
int		gmin_i(int a, int b , int c, int d);
int		optimize(i_list **in);

//maxmin_ins.c
tt_list	*get_min(tt_list *stack, int size);
tt_list	*get_max(tt_list *stack, int size);
void	push_on_max(tt_list *stack, tt_list *max, i_list **instr);
void	push_under_min(tt_list *stack, tt_list *min, i_list **instr);

//instr_clcltB.c
void	i_to_float(int position, tt_list *stack1, int size, i_list **inumber);
void	i_to_place(tt_list *target_s1, tt_list *st2, i_list **inumber, int s);
tt_list	*find_place(tt_list *stack2, int target_data, tt_list *max, tt_list *min);
void	clclt_instr(tt_list *upper_nebor, tt_list *stack2, int size, i_list **inumber);
int		inst_num(tt_list *stack1, tt_list *stack2, tt_list *node, i_list **inumber);

//sorting B
void	exec_instr(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr);
void	update_inst(i_list **i_target, i_list **inumber);
void	fnd_tr(tt_list *head, tt_list *stack2, i_list **i_target, tr_list **data);
void	find_target(tt_list *head, tt_list *stack2, i_list **i_target, int s);

//instr_clcltA.c
void	clclt_instr3(tt_list *upper_nbr, tt_list *st2, int size, i_list **inmb);
void	i_to_placea(tt_list *tr_s1, tt_list *st2, i_list **inumber, int size);
int		inst_numa(tt_list *st1, tt_list *st2, tt_list *node, i_list **inumber);

//find_place3.c
tt_list	*find_place3(tt_list *stack2, int target_data, int size);
tt_list	*find_place33(tt_list *stack2, int target_data, int size);

//sorting A
void	push_on_min(tt_list *stack, tt_list *min, i_list **instr);
void	push_under_max(tt_list *stack, tt_list *max, i_list **instr);
void	fnd_tra(tt_list *head, tt_list *st2, i_list **i_target, tr_list **data);
void	find_targeta(tt_list *head, tt_list *stack2, i_list **i_target, int s);

//func_push.c
tt_list	*delfirst(tt_list  *lst);
void	move_first(tt_list **stack1, tt_list **stack2); //pb
int		pa(tt_list **stack1, tt_list **stack2);
int		pb(tt_list **stack1, tt_list **stack2);

//func_swap.c
int		ss(tt_list **stack1, tt_list **stack2);
int		sb(tt_list **stack,  tt_list **s2); //no s2);
int		sa(tt_list **stack,  tt_list **s2); //no s2);
int		swap(tt_list **stack,  tt_list **s2); //no s2);

//func_revrot.c
int		rrr(tt_list **stack1, tt_list **stack2);
int		rrb(tt_list **stack, tt_list **s2); //no s2
int		rra(tt_list **stack, tt_list **s2); //no s2);

//func_rotate.c
int		rb(tt_list **stack, tt_list **s2); //no s2);
int		ra(tt_list **stack,  tt_list **s2); //no s2);
int		rr(tt_list **stack1, tt_list **stack2);

//dbg_func.c
void	print_list(tt_list *lst);
void	print_itarget(i_list *lst);
int		check_if_sorted_final(tt_list *lst);

#endif
