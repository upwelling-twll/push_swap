/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 16:43:56 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_mood1(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr)
{
	while (i_target->s1_rotate_up != 0)
	{
		ra(stack1, NULL);
		if (dr == 1)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
		i_target->s1_rotate_up--;
	}
	while (i_target->s2_rotate_down != 0)
	{
		rrb(stack2, NULL);
		if (dr == 1)
			write(1, "rrb\n", 4);
		else
			write(1, "rra\n", 4);
		i_target->s2_rotate_down--;
	}
	pb(stack1, stack2);
}

void	run_mood2(tt_list **stack1, tt_list **stack2, i_list *i_target, int d2)
{
	while (i_target->s1_rotate_down != 0)
	{
		rra(stack1, NULL);
		if (d2 == 1)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
		i_target->s1_rotate_down--;
	}
	while (i_target->s2_rotate_up != 0)
	{
		rb(stack2, NULL);
		if (d2 == 1)
			write(1, "rb\n", 3);
		else
			write(1, "ra\n", 3);
		i_target->s2_rotate_up--;
	}
	pb(stack1, stack2);
}

void	rotate_2(tt_list **s1, tt_list **s2, i_list *it, int mode)
{
	if (mode == 3)
	{
		while (it->s1_rotate_up != 0 && it->s2_rotate_up != 0)
		{
			rr(s1, s2);
			write(1, "rr\n", 3);
			it->s1_rotate_up--;
			it->s2_rotate_up--;
		}
	}
	if (mode == 4)
	{
		while (it->s1_rotate_down != 0 && it->s2_rotate_down != 0)
		{
			rrr(s1, s2);
			write(1, "rrr\n", 4);
			it->s1_rotate_down--;
			it->s2_rotate_down--;
		}
	}
}

void	run_mood3(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr)
{
	rotate_2(stack1, stack2, i_target, 3);
	while (i_target->s1_rotate_up != 0)
	{
		ra(stack1, NULL);
		if (dr == 1)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
		i_target->s1_rotate_up--;
	}
	while (i_target->s2_rotate_up != 0)
	{
		rb(stack2, NULL);
		if (dr == 1)
			write(1, "rb\n", 3);
		else
			write(1, "ra\n", 3);
		i_target->s2_rotate_up--;
	}
	pb(stack1, stack2);
}

void	run_mood4(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr)
{
	rotate_2(stack1, stack2, i_target, 4);
	while (i_target->s1_rotate_down != 0)
	{
		rra(stack1, NULL);
		if (dr == 1)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
		i_target->s1_rotate_down--;
	}
	while (i_target->s2_rotate_down != 0)
	{
		rrb(stack2, NULL);
		if (dr == 1)
			write(1, "rrb\n", 4);
		else
			write(1, "rra\n", 4);
		i_target->s2_rotate_down--;
	}
	pb(stack1, stack2);
}
