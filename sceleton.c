/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sceleton.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 22:01:35 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_split.c"

void	push_to_stack1(tt_list **stack1, tt_list **stack2)
{
	i_list	*i_target;

	while (ft_llstsize(*stack2) >= 1)
	{
		i_target = malloc(sizeof(i_list));
		find_targeta(*stack2, *stack1, &i_target, ft_llstsize(*stack2));
		exec_instr(stack2, stack1, i_target, 2);
		free(i_target);
	}
	min_to_top(stack1);
	*stack1 = get_min(*stack1, ft_llstsize(*stack1));
}

void	push_to_stack2(tt_list **stack1, tt_list **stack2)
{
	i_list	*i_target;

	pb_first(stack1, stack2);
	pb(stack1, stack2);
	write(1, "pb\npb\n", 6);
	while (ft_llstsize(*stack1) > 3)
	{
		i_target = malloc(sizeof(i_list));
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

int	fill_stack1(char **str, tt_list **stack1)
{
	tt_list	*head;
	char	**str_h;

	str_h = str;
	// printf("after split:\n strh 1 = %s;\n strh 2 = %s \n", *str_h, *(str_h + 1));
	// printf("after split:\n str 1 = %s;\n str2 = %s\n ", *str, *(str + 1));
	(*stack1)->prev = *stack1;
	(*stack1)->data = ft_atoi(*str);
	(*stack1)->next = *stack1;
	head = *stack1;
	//printf("str1 = %s\n", *str);
	str++;
	// printf("will verify second: %s\n", *str);
	// printf("str2 = %s\n", *str);
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
	//printf("all args are ok\n");
	head->prev = *stack1;
	(*stack1)->next = head;
	*stack1 = head;
	str = str_h;
	// printf("will clean str\n");
	// printf("str1 = %s\n", *str);
	//printf("str2 = %s\n", *str+1);
	ft_cleanstr_ext(str, ft_splsize(str));
	//printf("done filling\n");
	return (1);
}

int	fill_stack1_argv(char **str, tt_list **stack1)
{
	tt_list	*head;
	char	**str_h;
	tt_list	*new_last;
	tt_list	*old_last;

	head = *stack1;
	str_h = str;
	while(*str != NULL)
	{
		if ((!(verify_argv(head, *str))))
			return (0);
		old_last = ft_llstlast(*stack1);
		new_last = add_node(*stack1, ft_atoi(*str));
		old_last->next = new_last;
		new_last->next = *stack1;
		new_last->prev = old_last;
		(*stack1)->prev = new_last;
		str++;
	}
	str = str_h;
	ft_cleanstr_ext(str, ft_splsize(str));
	*stack1 = head;
	//printf("all args are ok\n");
	return (1);
}

int	split_parse_fill_argv(char *argv, tt_list **stack1)
{
	char	**str;
	tt_list	*head;
	tt_list	*new;

	printf("spl_par_fll: stack1=%i\n", (*stack1)->data);
	printf("spl_par_fll: stack1->next=%i\n", (*stack1)->next->data);
	printf("spl_par_fll: stack1->next->next=%i\n", (*stack1)->next->next->data);
	printf("spl_par_fll: stack1->prev=%i\n", (*stack1)->prev->data);
	printf("lst size = %i\n", ft_llstsize(*stack1));
	str = ft_split(argv, ' ');
	printf("str1 =%s\n", *str);
	if (!(fill_stack1_argv(str, stack1)))
		return (ft_exit_ps(stack1, NULL, str, 1));
	return (1);
}

int	ft_parse_input(int argc, char *argv[], tt_list **stack1)
{
	tt_list	*head;
	char	**str;

	if (argc < 2)
		return (0);
	argv++;
	//printf("split\n");
	str = ft_split(*argv, ' ');
	//printf("after split:\n str 1 = %s;\n str2 = %s\n will verify: \n", *str, *(str + 1));
	if ((!(verify_argv(NULL, *str))))
	{
		//printf("will chean `cause !verif_argv\n");
		return (ft_exit_ps(stack1, NULL, str, 5));
	}
	//printf("fill st1:\n str 1 = %s;\n str2 = %s\n will verify while filling st1 \n", *str, *(str + 1));
	if (!fill_stack1(str, stack1))
		return (0);
	argc--;
	argv++;
	printf("argc=%i\n", argc);
	print_list(*stack1);
	while (argc >= 2)
	{
		if (!(split_parse_fill_argv(*argv, stack1)))
			return (0);
		print_list(*stack1);
		argc--;
		argv++;
	}
	head = *stack1;
	//print_list(*stack1);
	if (check_if_sorted(head) || ft_llstsize(head) == 1)
		return (ft_exit_ps(stack1, NULL, NULL, 0));
	if (ft_llstsize(head) == 2)
	{
		sort_2(stack1);
		//printf("sorted 2\n");
		return (ft_exit_ps(stack1, NULL, NULL, 0));
	}
	return (1);
}
