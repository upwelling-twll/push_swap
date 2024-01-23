#include "push_swap.h" 

tt_list	*add_node(tt_list *nlist, int data)
{
	tt_list	*new;

	new = malloc(sizeof(tt_list));
	new -> prev = nlist;
	new -> data = data;
	new -> next = NULL;
	return (new);
}

tt_list	*init_list(int i)
{
	tt_list	*nlist;

	nlist = malloc(sizeof(tt_list)* 1);
	nlist -> prev = NULL;
	nlist -> data = 1;
	nlist ->next = NULL;
	return (nlist);
}

int	main(int argc, char *argv[])
{
	tt_list *nlist;
	
	if (argc > 2)
	{
		nlist = init_list(ft_atoi(argv[1]));
		argv++;
	}
	while (*argv)
	{
		nlist = add_node(nlist, ft_atoi(*argv));
		argv++;
	}
}