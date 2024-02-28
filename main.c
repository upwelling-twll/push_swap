/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/23 22:18:07 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "func_push.c"          //for debugger only
// #include "func_swap.c"          //for debugger only
// #include "func_revrot.c"        //for debugger only
// #include "func_rotate.c"        //for debugger only
// #include "optimize_ins.c"       //for debugger only
// #include "maxmin_ins.c"         //for debugger only
// #include "stack_analysis.c"     //for debugger only
// #include "list_operations.c"    //for debugger only
// #include "verify_or_exit.c"     //for debugger only
// #include "sort_small.c"         //for debugger only
// #include "sort_mode.c"          //for debugger only
// #include "instr_clcltA.c"       //for debugger only
// #include "sortingA.c"           //for debugger only
// #include "find_place3.c"        //for debugger only
// #include "instr_clcltB.c"       //for debugger only
// #include "sortingB.c"           //for debugger only
// #include "sceleton.c"           //for debugger only
#include "libft/ft_atoi.c"
#include "libft/ft_isdigit.c"

int	main(int argc, char *argv[])
{
	tt_list	*stack1;
	tt_list	*stack2;

	stack1 = malloc(sizeof(tt_list));
	if (!(ft_parse_input(argc, argv, &stack1)))
		return (0);
	//stack2 = malloc(sizeof(tt_list));
	// printf("stack1=%p\n", stack1);
	// printf("stack2=%p\n", stack2);
	push_to_stack2(&stack1, &stack2);
//	print_list(stack1);
	//printf("st2 - size = %li\n", sizeof(stack2));
	push_to_stack1(&stack1, &stack2);
	//printf("st2 - size = %li\n", sizeof(stack2));
	//print_list(stack1);
	ft_exit_ps(&stack1, &stack2, NULL, 3);
	//free(stack1);
	//print_list(stack1);
	//printf("lst siaze:%i\n", ft_llstsize(stack1));
	stack1 = NULL;
	//print_list(stack1);
	stack2 = NULL;
	return (0);
}
