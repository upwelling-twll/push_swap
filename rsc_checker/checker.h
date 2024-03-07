/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:48:39 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include "../rsc_push_swap/push_swap.h"
# include "../rsc_gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef int	(*t_insfunc)(t_llist **, t_llist **);

typedef struct t_inslist
{
	char				*content;
	struct t_inslist	*next;
}					t_chins;

//apply_instructions.c
int		apply_ins(t_llist **stack1, t_llist **stack2, t_insfunc ins_recived);
int		valid_ins(char *ins);
int		proc_all(t_chins *oper, t_llist **head, t_llist **stack2, t_chins *hoper);
int		apply_instructions(t_llist **lst, t_llist **stack2, t_chins *oper);

//exit_del.c
t_llist	*delfirst(t_llist *lst);
void	del_instr_list(t_chins *lst);
void	del_stack_lst_ch(t_llist *lst);
int		ft_exit(t_llist *st1, t_llist *st2, t_chins *oper, int display);

//checker_inc.c
int		ft_olstsize(t_chins *lst);
void	print_list_ins(t_chins *lst);
char	*other_str(char *str, t_llist *st1, int flag);
int		fill_str(t_llist **stack1, t_llist *head, char **str, char **str_h);

//parse_instructions.c
int		ft_strcmp(char *s1, char *s2);
t_chins	*add_node_ins(t_chins *lst, char *ins);
char	*read_stdin(int fd, t_llist *st1, int flag);
int		parse_instr(t_llist **lst, t_chins **oper);

//parse_nums.c
int		split_parse_fill_argv_ch(char *argv, t_llist **stack1);
int		more_args_ch(int argc, char *argv[], t_llist **stack1);
int		fill_num_stack(char **str, t_llist **stack1);
int		ft_parse_input_ch(int argc, char *argv[], t_llist **stack1);

//checker_push.c
void	pb_first_ch(t_llist **stack1, t_llist **stack2);
int		pb(t_llist **stack1, t_llist **stack2);
int		pa(t_llist **stack1, t_llist **stack2);
void	move_first(t_llist **stack1, t_llist **stack2);

//checker_swap.c
int		ss(t_llist **stack1, t_llist **stack2);
int		sb(t_llist **stack, t_llist **s2); //no s2);
int		sa(t_llist **stack, t_llist **s2); //no s2);
int		swap(t_llist **stack, t_llist **s2); //no s2);

//checker_revrot.c
int		rrr(t_llist **stack1, t_llist **stack2);
int		rrb(t_llist **stack, t_llist **s2); //no s2
int		rra(t_llist **stack, t_llist **s2); //no s2);

//checker_rotate.c
int		rr(t_llist **stack1, t_llist **stack2);
int		rb(t_llist **stack, t_llist **s2); //no s2);
int		ra(t_llist **stack, t_llist **s2); //no s2);

#endif