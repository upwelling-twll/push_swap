#include "../rsc_push_swap/push_swap.h"
#include "../libft/ft_atoi.c"
#include "checker.h"

int main(int argc, char *argv[])
{
	t_llist	*lst;
	t_llist	*stack2;
	t_chins	*oper;

	if (argc < 2)
		return (0);
	lst = malloc(sizeof(t_llist));
	stack2 = NULL;
	if (!(ft_parse_input_ch(argc, argv, &lst)))
		return (0);
	if (!(parse_instr(&lst, &oper)))
		return (0);
	if (check_if_sorted(lst) && ft_olstsize(oper))
		return(ft_exit(lst, NULL, oper, 2));
	return(apply_instructions(&lst, &stack2, oper));
}

// in_cmd="#" input="1 2" return KO
// in_cmd="123" input="1 2" return KO
// in_cmd="@" input="1 2" return KO -> error

//!!!!if sorted still apply instructions
