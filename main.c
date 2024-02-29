/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/02/29 12:23:44 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_llist	*stack1;
	t_llist	*stack2;

	stack1 = malloc(sizeof(t_llist));
	if (!(ft_parse_input(argc, argv, &stack1)))
		return (0);
	push_to_stack2(&stack1, &stack2);
	push_to_stack1(&stack1, &stack2);
	ft_exit_ps(&stack1, &stack2, NULL, 3);
	stack1 = NULL;
	stack2 = NULL;
	return (0);
}
