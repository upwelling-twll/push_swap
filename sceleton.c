/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sceleton.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 12:10:33 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack1(t_llist **stack1, t_llist **stack2)
{
	t_inst	*i_target;

	while (ft_llstsize(*stack2) >= 1)
	{
		i_target = malloc(sizeof(t_inst));
		find_targeta(*stack2, *stack1, &i_target, ft_llstsize(*stack2));
		exec_instr(stack2, stack1, i_target, 2);
		free(i_target);
	}
	min_to_top(stack1);
	*stack1 = get_min(*stack1, ft_llstsize(*stack1));
}

void	push_to_stack2(t_llist **stack1, t_llist **stack2)
{
	t_inst	*i_target;

	pb_first(stack1, stack2);
	pb(stack1, stack2);
	write(1, "pb\npb\n", 6);
	while (ft_llstsize(*stack1) > 3)
	{
		i_target = malloc(sizeof(t_inst));
		find_target(*stack1, *stack2, &i_target, ft_llstsize(*stack1));
		exec_instr(stack1, stack2, i_target, 1);
		free(i_target);
		if (check_if_sorted(*stack1))
			break ;
	}
	if (ft_llstsize(*stack1) == 3)
	{
		sort_3(stack1);
		min_to_top(stack1);
	}
}

int	fill_stack1(char **str, t_llist **stack1)
{
	t_llist	*head;
	char	**str_h;

	str_h = str;
	(*stack1)->prev = *stack1;
	(*stack1)->data = ft_atoi(*str);
	(*stack1)->next = *stack1;
	head = *stack1;
	str++;
	while (*str != NULL)
	{
		if ((!(verify_argv(head, *str))))
			return (ft_exit_ps(stack1, NULL, str_h, 1));
		(*stack1)->next = add_node(*stack1, ft_atoi(*str));
		head->prev = *stack1;
		str++;
		*stack1 = (*stack1)->next;
		(*stack1)->next = head;
	}
	head->prev = *stack1;
	(*stack1)->next = head;
	*stack1 = head;
	str = str_h;
	ft_cleanstr_ext(str, ft_splsize(str));
	return (1);
}

int	ft_parse_input(int argc, char *argv[], t_llist **stack1)
{
	t_llist	*head;
	char	**str;

	if (argc < 2)
	{
		free(*stack1);
		return (0);
	}
	argv++;
	str = ft_split(*argv, ' ');
	if ((!(verify_argv(NULL, *str))))
		return (ft_exit_ps(stack1, NULL, str, 5));
	if (!fill_stack1(str, stack1))
		return (0);
	if (!(more_args(argc, argv, stack1)))
		return (0);
	head = *stack1;
	if (check_if_sorted(head) || ft_llstsize(head) == 1)
		return (ft_exit_ps(stack1, NULL, NULL, 0));
	if (ft_llstsize(head) == 2)
	{
		sort_2(stack1);
		return (ft_exit_ps(stack1, NULL, NULL, 0));
	}
	return (1);
}
