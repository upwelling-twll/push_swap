#include "push_swap.h"

#define RA_STR (dr == 1 ? "ra\n" : "rb\n")
#define RRB_STR (dr == 1 ? "rrb\n" : "rra\n")
#define RA2_STR (d2 == 1 ? "rra\n" : "rrb\n")
#define RRA2_STR (d2 == 1 ? "rb\n" : "ra\n")

void	run_mood1(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr)
{
	while (i_target->s1_rotate_up != 0)
	{
		ra(stack1, NULL);
		write(1, RA_STR, 3);
		i_target->s1_rotate_up--;
	}
	while (i_target->s2_rotate_down != 0)
	{
		rrb(stack2, NULL);
		write(1, RRB_STR, 4);
		i_target->s2_rotate_down--;
	}
	pb(stack1, stack2);
}

void	run_mood2(tt_list **stack1, tt_list **stack2, i_list *i_target, int d2)
{
	while (i_target->s1_rotate_down != 0)
	{
		rra(stack1, NULL);
		write(1, RA2_STR, 4);
		i_target->s1_rotate_down--;
	}
	while (i_target->s2_rotate_up != 0)
	{
		rb(stack2, NULL);
		write(1, RRA2_STR, 3);
		i_target->s2_rotate_up--;
	}
	pb(stack1, stack2);
}

void	run_mood3(tt_list **stack1, tt_list **stack2, i_list *i_target, int dr)
{
	while (i_target->s1_rotate_up != 0 && i_target->s2_rotate_up != 0)
	{
		rr(stack1, stack2);
		write(1, "rr\n", 3);
		i_target->s1_rotate_up--;
		i_target->s2_rotate_up--;
	}
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
	while (i_target->s1_rotate_down != 0 && i_target->s2_rotate_down != 0)
	{
		rrr(stack1, stack2);
		write(1, "rrr\n", 4);
		i_target->s1_rotate_down--;
		i_target->s2_rotate_down--;
	}
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