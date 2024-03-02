/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:43:39 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*delfirst(t_llist *lst)
{
	t_llist	*new_head;
	t_llist	*lst_prev;

	if (ft_llstsize(lst) == 1)
	{
		free (lst);
		return (NULL);
	}
	new_head = lst->next;
	lst_prev = lst->prev;
	new_head->prev = lst_prev;
	lst_prev->next = new_head;
	free (lst);
	return (new_head);
}

void	pb_first(t_llist **stack1, t_llist **stack2)
{
	int		tmp;

	tmp = (*stack1)->data;
	*stack2 = add_node(*stack2, tmp);
	(*stack2)->next = *stack2;
	(*stack2)->prev = (*stack2);
	*stack1 = delfirst(*stack1);
}

void	move_first(t_llist **stack1, t_llist **stack2)
{
	int		tmp;
	t_llist	*new_head;
	t_llist	*old_last;

	tmp = (*stack1)->data;
	if (*stack2 == NULL)
	{
		*stack2 = add_node(*stack2, tmp);
		(*stack2)->next = *stack2;
		(*stack2)->prev = (*stack2);
	}
	else
	{
		old_last = ft_llstlast(*stack2);
		new_head = add_node(*stack2, tmp);
		old_last->next = new_head;
		new_head->next = *stack2;
		new_head->prev = old_last;
		(*stack2)->prev = new_head;
		*stack2 = new_head;
	}
	*stack1 = delfirst(*stack1);
}

int	pa(t_llist **stack1, t_llist **stack2)
{
	if (!(*stack2))
		return (0);
	move_first(stack2, stack1);
	return (1);
}

int	pb(t_llist **stack1, t_llist **stack2)
{
	if (!(*stack1))
		return (0);
	move_first(stack1, stack2);
	return (1);
}
