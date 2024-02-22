#include "push_swap.h"

int	best_option(int s1us2d, int s1ds2u, int tu, int td)
{
	char	min_inst = gmin(s1us2d,s1ds2u,tu, td);
	if (min_inst == 'a')
		return (1);
	else if (min_inst == 'b')
		return (2);
	else if (min_inst == 'c')
		return (3);
	return (4);
}

int	gmin_i(int a, int b , int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return (a);
	if (b <= a && b <= c && b <= d)
		return (b);
	if (c <= a && c <= b && c <= d)
		return (c);
	else
		return (d);
}

int	optimize(i_list **in)
{
	int	ttl_up_i;
	int	ttl_down_i;
	int s1_down;
	int s1up_s2d;
	int s1d_s2up;

	s1_down = (*in)->s1_rotate_down;
	s1up_s2d = (*in)->s1_rotate_up + (*in)->s2_rotate_down;
	s1d_s2up = s1_down + (*in)->s2_rotate_up;

	if ((*in)->s1_rotate_up > (*in)->s2_rotate_up)
		ttl_up_i = (*in)->s2_rotate_up + ((*in)->s1_rotate_up - 
		(*in)->s2_rotate_up);
	else if ((*in)->s1_rotate_up <= (*in)->s2_rotate_up)
		ttl_up_i = (*in)->s1_rotate_up + 
		((*in)->s2_rotate_up - (*in)->s1_rotate_up);
	if (s1_down > (*in)->s2_rotate_down)
		ttl_down_i =(*in)->s2_rotate_down + (s1_down - (*in)->s2_rotate_down);
	else if (s1_down <= (*in)->s2_rotate_down)
		ttl_down_i = s1_down + ((*in)->s2_rotate_down - s1_down);
	(*in)->mood = best_option(s1up_s2d, s1d_s2up, ttl_up_i, ttl_down_i);
	return (gmin_i(s1up_s2d, s1d_s2up, ttl_up_i, ttl_down_i));
}
