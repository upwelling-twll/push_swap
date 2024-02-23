/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 17:55:02 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

tt_list	*sort_2(tt_list **lst)
{
	if ((*lst)->data > (*lst)->next->data)
	{
		ra(lst, NULL);
		write(1, "ra\n", 3);
	}
	return (*lst);
}

void	write_oper(int opt)
{
	if (opt == 1)
		write(1, "sa\n", 3);
	if (opt == 2)
		write(1, "rra\n", 4);
	if (opt == 3)
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
	}
	if (opt == 4)
	{
		write(1, "rra\n", 4);
		write(1, "rra\n", 4);
	}
	if (opt == 5)
	{
		write(1, "rra\n", 4);
		write(1, "sa\n", 3);
	}
}

void	run(tt_list **lst, int opt)
{
	if (opt == 1)
		sa(lst, NULL);
	if (opt == 2)
		rra(lst, NULL);
	if (opt == 3)
	{
		sa(lst, NULL);
		rra(lst, NULL);
	}
	if (opt == 4)
	{
		rra(lst, NULL);
		rra(lst, NULL);
	}
	if (opt == 5)
	{
		rra(lst, NULL);
		sa(lst, NULL);
	}
	write_oper(opt);
}

void	sort_3(tt_list **lst)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->data;
	b = (*lst)->next->data;
	c = (*lst)->prev->data;
	if (a > b && a < c)
		run(lst, 1);
	else if (a > c && a < b)
		run(lst, 2);
	else if (a > b && b > c)
		run (lst, 3);
	else if (a > b && b < c)
		run (lst, 4);
	else if (a < b && b > c)
		run (lst, 5);
	return ;
}
