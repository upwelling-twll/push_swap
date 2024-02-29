/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 18:08:31 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_llist
{
	struct s_llist	*prev;
	int				data;
	struct s_llist	*next;
}					t_llist;

typedef struct s_inst
{
	int		target;
	int		s1_rotate_up;
	int		s1_rotate_down;
	int		s2_rotate_up;
	int		s2_rotate_down;
	int		mood;
}					t_inst;

typedef struct t_trda
{
	struct s_llist		*cur;
	struct s_llist		*tr;
	struct s_inst		**ins_data;
	int					min_ins;
	int					cur_ins;
}						t_trda;

//more_args.c
int		fill_stack1_argv(char **str, t_llist **stack1);
int		split_parse_fill_argv(char *argv, t_llist **stack1);
int		more_args(int argc, char *argv[], t_llist **stack1);
void	*check_frst_arg(int argc, char *argv[], t_llist **stack1);

//sceleton.c
void	sort_2_3(t_llist **stack1, int size);
int		ft_parse_input(int argc, char *argv[], t_llist **nlist);
int		fill_stack1(char **str, t_llist **nlist);
void	push_to_stack2(t_llist **stack1, t_llist **stack2);
void	push_to_stack1(t_llist **stack1, t_llist **stack2);

//exit.c
void	del_stack_lst(t_llist **lst);
int		ft_splsize(char **str);
void	ft_cleanstr_ext(char **arr, size_t n);
int		ft_exit_ps(t_llist **st1, t_llist **st2, char **str, int display);

//verify.c
int		check_overflow(const char *str, int flag, int i);
int		verify_atoi(const char *str);
int		verify_argv(t_llist *args_lst, char *str);

//list_operations.c
t_llist	*init_list(int i);
t_llist	*ft_llstlast(t_llist *lst);
int		ft_llstsize(t_llist *lst);
t_llist	*add_node(t_llist *nlist, int data);

//stack_analysis.c
int		check_if_sorted(t_llist *lst);
void	float_ra(t_llist **head, int position);
void	float_rra(t_llist **head, t_llist *new_head, int position);
void	float_to_top(t_llist **head, t_llist *new_head);
void	min_to_top(t_llist **lst);

//sort_samll.c
t_llist	*sort_2(t_llist **lst);
void	write_oper(int opt);
void	run(t_llist **lst, int opt);
void	sort_3(t_llist **lst);

//sort_mode.c
void	rotate_2(t_llist **s1, t_llist **s2, t_inst *it, int mode);
void	run_mood1(t_llist **stack1, t_llist **stack2, t_inst *i_target, int dr);
void	run_mood2(t_llist **stack1, t_llist **stack2, t_inst *i_target, int dr);
void	run_mood3(t_llist **stack1, t_llist **stack2, t_inst *i_target, int dr);
void	run_mood4(t_llist **stack1, t_llist **stack2, t_inst *i_target, int dr);

//optimize_ins.c
char	gmin(int a, int b, int c, int d);
int		best_option(int s1us2d, int s1ds2u, int tu, int td);
int		gmin_i(int a, int b, int c, int d);
int		optimize(t_inst **in);

//maxmin_ins.c
t_llist	*get_min(t_llist *stack, int size);
t_llist	*get_max(t_llist *stack, int size);
void	push_on_max(t_llist *stack, t_llist *max, t_inst **instr);
void	push_under_min(t_llist *stack, t_llist *min, t_inst **instr);

//instr_clcltB.c
void	i_to_float(int position, int size, t_inst **inumber);
void	i_to_place(t_llist *target_s1, t_llist *st2, t_inst **inumber, int s);
t_llist	*find_place(t_llist *stack2, int target_data);
void	clclt_instr(t_llist *up_nbr, t_llist *st2, int size, t_inst **inumber);
int		inst_num(t_llist *st1, t_llist *st2, t_llist *node, t_inst **inumber);

//sorting B
void	exec_instr(t_llist **stack1, t_llist **st2, t_inst *i_target, int dr);
void	update_inst(t_inst **i_target, t_inst **inumber);
void	fnd_tr(t_llist *head, t_llist *st2, t_inst **i_target, t_trda **data);
void	find_target(t_llist *head, t_llist *stack2, t_inst **i_target, int s);

//instr_clcltA.c
void	clclt_instr3(t_llist *upper_nbr, t_llist *st2, int size, t_inst **inmb);
void	i_to_placea(t_llist *tr_s1, t_llist *st2, t_inst **inumber, int size);
int		inst_numa(t_llist *st1, t_llist *st2, t_llist *node, t_inst **inumber);

//find_place3.c
t_llist	*find_place3(t_llist *stack2, int target_data, int size);
t_llist	*find_place33(t_llist *stack2, int target_data, int size);

//sorting A
void	push_on_min(t_llist *stack, t_llist *min, t_inst **instr);
void	push_under_max(t_llist *stack, t_llist *max, t_inst **instr);
void	fnd_tra(t_llist *head, t_llist *st2, t_inst **i_target, t_trda **data);
void	find_targeta(t_llist *head, t_llist *stack2, t_inst **i_target, int s);

//func_push.c
t_llist	*delfirst(t_llist *lst);
void	pb_first(t_llist **stack1, t_llist **stack2);
void	move_first(t_llist **stack1, t_llist **stack2); //pb
int		pa(t_llist **stack1, t_llist **stack2);
int		pb(t_llist **stack1, t_llist **stack2);

//func_swap.c
int		ss(t_llist **stack1, t_llist **stack2);
int		sb(t_llist **stack, t_llist **s2); //no s2);
int		sa(t_llist **stack, t_llist **s2); //no s2);
int		swap(t_llist **stack, t_llist **s2); //no s2);

//func_revrot.c
int		rrr(t_llist **stack1, t_llist **stack2);
int		rrb(t_llist **stack, t_llist **s2); //no s2
int		rra(t_llist **stack, t_llist **s2); //no s2);

//func_rotate.c
int		rb(t_llist **stack, t_llist **s2); //no s2);
int		ra(t_llist **stack, t_llist **s2); //no s2);
int		rr(t_llist **stack1, t_llist **stack2);

//dbg_func.c
void	print_list(t_llist *lst);
void	print_itarget(t_inst *lst);
int		check_if_sorted_final(t_llist *lst);

#endif
