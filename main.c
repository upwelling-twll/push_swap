/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 11:32:02 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	tt_list	*stack1;
	tt_list	*stack2;

	stack1 = malloc(sizeof(tt_list));
	if (!(ft_parse_input(argc, argv, &stack1)))
		return (0);
	push_to_stack2(&stack1, &stack2);
	push_to_stack1(&stack1, &stack2);
	ft_exit_ps(&stack1, &stack2, NULL, 3);
	stack1 = NULL;
	stack2 = NULL;
	return (0);
}
