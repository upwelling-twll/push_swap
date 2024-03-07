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
	return(apply_instructions(&lst, &stack2, oper));
}
