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
// #include "list_operations.c"   //for debugger only
// #include "instructions.c"    //for debugger only
// #include "sortingB.c"    //for debugger only
// #include "sortingA.c"    //for debugger only
#include "libft/ft_atoi.c"
#include "libft/ft_isdigit.c"

int	main(int argc, char *argv[])
{
	tt_list	*stack1;
	tt_list	*stack2;

	stack1 = malloc(sizeof(tt_list));
	if (!(ft_parse_input(argc, argv, &stack1)))
		return (0);
	stack2 = malloc(sizeof(stack2));
	stack2 = NULL;
	push_to_stack2(&stack1, &stack2);
	push_to_stack1(&stack1, &stack2);
	ft_exit_ps(stack1, stack2, 0);
	return (0);
}
